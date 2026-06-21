# Developer Documentation

## Architecture Overview

Inception is a containerized web infrastructure consisting of three main services:
┌─────────────────────────────────────────────────┐

│          Host Machine (Mac/Linux)               │

│  Port 443 (HTTPS) → stripet.42.fr               │

└────────────────────┬────────────────────────────┘

│

↓

┌───────────────────────┐

│   Docker Bridge       │

│   Network: inception  │

└─────────────────────────┘

│          │          │

┌────┴───┐  ┌───┴────┐  ┌─┴────────┐

↓        ↓  ↓        ↓  ↓          ↓

nginx   wordpress    mariadb

:443     :9000       :3306

(public) (internal)  (internal)

## Services

### 1. nginx (Web Server / Reverse Proxy)

**Container:** `nginx`
**Port:** 443 (HTTPS only)
**Image:** `alpine:3.19`

**Responsibilities:**
- Listen on HTTPS (TLS 1.2/1.3)
- Serve static files (index.html, CSS, JS)
- Reverse proxy PHP requests to WordPress
- Handle SSL certificate generation

**Key Files:**
- `srcs/requirements/nginx/Dockerfile` — builds Alpine + nginx
- `srcs/requirements/nginx/conf/nginx.conf` — server configuration
- `srcs/requirements/nginx/tools/entrypoint.sh` — certificate generation

**Configuration Details:**

```nginx
listen 443 ssl http2;
server_name stripet.42.fr;

location ~ \.php$ {
    fastcgi_pass wordpress:9000;  # Forward PHP to WordPress container
    fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
    include fastcgi_params;
}
```

The `fastcgi_pass wordpress:9000` uses Docker's internal DNS to resolve the `wordpress` hostname to the container's internal IP.

### 2. WordPress (Application Server)

**Container:** `wordpress`
**Port:** 9000 (FastCGI, internal only)
**Image:** `alpine:3.19`

**Responsibilities:**
- Run PHP-FPM (FastCGI Process Manager)
- Execute PHP code
- Communicate with MariaDB
- Store uploaded files in the volume

**Key Files:**
- `srcs/requirements/wordpress/Dockerfile` — builds Alpine + PHP + WordPress
- `srcs/requirements/wordpress/conf/www.conf` — PHP-FPM configuration
- `srcs/requirements/wordpress/tools/entrypoint.sh` — WordPress setup

**Setup Process (entrypoint.sh):**

1. Wait for MariaDB to be ready using `mysqladmin ping`
2. If `wp-config.php` doesn't exist, create it with:
   - Database credentials from environment variables
   - Security keys (generated with `openssl rand -base64`)
3. Start PHP-FPM in foreground mode

**PHP-FPM Configuration:**

```ini
listen = 0.0.0.0:9000      # Listen on all interfaces
pm = dynamic               # Dynamic process manager
pm.max_children = 5        # Max worker processes
pm.start_servers = 2       # Start with 2 processes
```

### 3. MariaDB (Database)

**Container:** `mariadb`
**Port:** 3306 (internal only)
**Image:** `alpine:3.19`

**Responsibilities:**
- Store WordPress database (posts, users, settings, etc.)
- Persist data across container restarts

**Key Files:**
- `srcs/requirements/mariadb/Dockerfile` — builds Alpine + MariaDB
- `srcs/requirements/mariadb/conf/zzz-server.cnf` — server configuration
- `srcs/requirements/mariadb/tools/entrypoint.sh` — database initialization

**Initialization Process (entrypoint.sh):**

1. Check if `/var/lib/mysql/mysql` directory exists
2. If not (first run):
   - Run `mysql_install_db` to create system tables
   - Start temporary MariaDB with `--skip-networking`
   - Create the WordPress database and user via HEREDOC
   - Set root password for both localhost and remote access (`root@%`)
   - Shut down temp server gracefully
3. Start real MariaDB listening on `0.0.0.0:3306`

**Critical Config:**

```ini
bind-address=0.0.0.0    # Listen on all interfaces (for container network)
port=3306               # Standard MySQL port
```

The `zzz-server.cnf` filename is intentional — it loads **last** alphabetically, overriding Alpine's default `mariadb-server.cnf` which has `skip-networking`.

## Docker Compose Configuration

`srcs/docker-compose.yml` orchestrates all three services:

```yaml
services:
  nginx:
    ports:
      - "443:443"         # Publish to host
    volumes:
      - wordpress_volume:/var/www/html  # Shared content
    depends_on:
      - wordpress
    restart: always

  wordpress:
    env_file: .env        # Load database credentials
    secrets:              # Pass passwords securely
      - db_password
      - db_root_password
    volumes:
      - wordpress_volume:/var/www/html
    depends_on:
      - mariadb
    expose:               # Internal only
      - "9000"
    restart: always

  mariadb:
    volumes:
      - mariadb_volume:/var/lib/mysql
    expose:
      - "3306"
    restart: always

volumes:
  wordpress_volume:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/stripet/data/wordpress

  mariadb_volume:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/stripet/data/mariadb

networks:
  inception:
    driver: bridge
```

### Key Concepts

**`ports` vs `expose`:**
- `ports`: Published to host machine (only nginx needs this)
- `expose`: Internal Docker network only (WordPress, MariaDB)

**`volumes`:**
- Persist data across container restarts
- Use local driver with bind mount to `/home/stripet/data/`
- Shared between containers for file access

**`restart: always`:**
- Containers auto-restart if they crash

**`depends_on`:**
- Order of service startup (nginx waits for WordPress, WordPress waits for MariaDB)
- Does **not** wait for readiness — that's why entrypoints have health checks

## Environment Variables

`srcs/.env`:

```bash
DOMAIN_NAME=stripet.42.fr
MYSQL_USER=stripet_user
MYSQL_DATABASE=wordpress_db
MYSQL_PASSWORD=MysqlPassword!
MYSQL_ROOT_PASSWORD=MysqlrootPassword!
```

Used by entrypoints and Docker Compose. **Not committed to git** (in `.gitignore`).

## Secrets

Docker Secrets are mounted at `/run/secrets/` inside containers:

```bash
secrets/db_password.txt         # Contains: MysqlPassword!
secrets/db_root_password.txt    # Contains: MysqlrootPassword!
```

Accessed in entrypoints:

```sh
MYSQL_PASSWORD=$(cat /run/secrets/db_password)
```

## Networking

### Internal Communication

Containers communicate via Docker's embedded DNS:
wordpress → mariadb:3306       # WordPress talks to MariaDB

nginx → wordpress:9000         # nginx talks to PHP-FPM

The service name automatically resolves to the container's internal IP on the `inception` bridge network.

### External Communication

- Host machine → nginx on `stripet.42.fr:443`
- No direct access to WordPress or MariaDB from outside

## Data Persistence

### WordPress Files

`/home/stripet/data/wordpress/` contains:
- `wp-config.php` — configuration
- `wp-content/` — themes, plugins, uploads
- All WordPress core files

Mounted as `/var/www/html/` in WordPress and nginx containers.

### Database Files

`/home/stripet/data/mariadb/` contains:
- `mysql/` — system tables
- `wordpress_db/` — WordPress database files (InnoDB)

Mounted as `/var/lib/mysql/` in MariaDB container.

## Troubleshooting for Developers

### Container Logs

```bash
docker logs nginx       # nginx logs
docker logs wordpress   # PHP-FPM logs
docker logs mariadb     # MariaDB logs
docker logs -f service  # Follow logs in real-time
```

### Entering a Container

```bash
docker exec -it nginx sh
docker exec -it wordpress sh
docker exec -it mariadb sh
```

### Testing MariaDB Connection

From WordPress container:

```bash
docker exec wordpress mysql -h mariadb -u stripet_user -pMysqlPassword! wordpress_db -e "SELECT 1;"
```

### Checking Network

```bash
docker exec wordpress ping mariadb
docker exec nginx wget -O- http://wordpress:9000/  # Will fail (FastCGI)
```

### Rebuilding a Single Service

```bash
docker compose -f srcs/docker-compose.yml build nginx
docker compose -f srcs/docker-compose.yml up -d nginx
```

### Viewing Docker Network

```bash
docker network inspect inception
```

Shows all connected containers and their IPs.

## Making Changes

### Modifying nginx Config

Edit `srcs/requirements/nginx/conf/nginx.conf`, then rebuild:

```bash
make build
```

### Modifying MariaDB Config

Edit `srcs/requirements/mariadb/conf/zzz-server.cnf`, then rebuild.

**Important:** Changes to `zzz-server.cnf` affect **new** MariaDB containers. Existing data won't be affected. Restart with:

```bash
make fclean && make build
```

### Modifying PHP Config

Edit `srcs/requirements/wordpress/conf/www.conf`, then rebuild.

### Updating WordPress Version

Edit `srcs/requirements/wordpress/Dockerfile`:

```dockerfile
wget https://wordpress.org/wordpress-5.9.tar.gz  # Change version URL
```

Then rebuild.

## Security Considerations

1. **Passwords in Secrets:** Never hardcode passwords in Dockerfiles. Use Docker Secrets.
2. **No `latest` Tag:** All images use Alpine 3.19 specifically (reproducible builds).
3. **Non-root User:** WordPress runs as `nobody:nobody`, MariaDB as `mysql:mysql`.
4. **TLS Certificates:** Self-signed, generated on first run. In production, use Let's Encrypt.
5. **Network Isolation:** WordPress and MariaDB only accessible internally.

## Performance Tips

- Increase MariaDB `innodb_buffer_pool_size` in `zzz-server.cnf` for large datasets
- Increase PHP-FPM `pm.max_children` in `www.conf` for high traffic
- Use WordPress caching plugins (WP Super Cache, etc.)
- Enable nginx gzip compression in `nginx.conf`:

```nginx
gzip on;
gzip_types text/plain text/css application/json;
```

## Extension Points

### Adding a Service (Redis Cache)

1. Create `srcs/requirements/redis/Dockerfile`
2. Add to `docker-compose.yml`
3. Update entrypoints to configure WordPress to use Redis
4. Run `make build`

### Custom Domain

Change `DOMAIN_NAME` in `srcs/.env` and regenerate nginx cert:

```bash
make down
make build
```

## Files Reference
srcs/

├── .env                        # Environment variables

├── docker-compose.yml          # Orchestration

├── requirements/

│   ├── nginx/

│   │   ├── Dockerfile          # Alpine + nginx

│   │   ├── conf/

│   │   │   └── nginx.conf      # Server config

│   │   └── tools/

│   │       └── entrypoint.sh   # Certificate generation

│   ├── wordpress/

│   │   ├── Dockerfile          # Alpine + PHP + WordPress

│   │   ├── conf/

│   │   │   └── www.conf        # PHP-FPM config

│   │   └── tools/

│   │       └── entrypoint.sh   # Setup & startup

│   └── mariadb/

│       ├── Dockerfile          # Alpine + MariaDB

│       ├── conf/

│       │   └── zzz-server.cnf  # Server config

│       └── tools/

│           └── entrypoint.sh   # Init & startup
secrets/                        # Docker secrets (git-ignored)

├── db_password.txt

└── db_root_password.txt

## Testing Checklist

- [ ] `make build` succeeds
- [ ] `docker ps` shows 3 running containers
- [ ] `curl -k https://localhost/` returns WordPress 302 redirect
- [ ] WordPress installation wizard loads at `https://stripet.42.fr`
- [ ] Can create posts in WordPress admin
- [ ] Database persists after `make down && make up`
- [ ] `make fclean` removes all data

---

**Last Updated:** June 2026
**Maintainer:** stripet
