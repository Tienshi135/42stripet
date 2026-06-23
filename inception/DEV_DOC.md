# Developer Documentation

## Architecture

Docker Compose stack with four services:
- `nginx` (public HTTPS, `443:443`)
- `wordpress` (PHP-FPM, internal `9000`)
- `mariadb` (DB, internal `3306`)
- `website` (bonus static site, internal `80`)

All services are attached to bridge network `inception`.

## Source layout

- `srcs/docker-compose.yml`
- `srcs/requirements/nginx/`
  - `Dockerfile`
  - `conf/nginx.conf`
  - `tools/entrypoint.sh`
- `srcs/requirements/wordpress/`
  - `Dockerfile`
  - `conf/www.conf`
  - `tools/entrypoint.sh`
- `srcs/requirements/mariadb/`
  - `Dockerfile`
  - `conf/server.cnf`
  - `tools/entrypoint.sh`
- `srcs/requirements/bonus/website/`
  - `Dockerfile`
  - `conf/nginx.conf`
  - `html/`

## Compose details

### Secrets

Loaded from local files:
- `../secrets/.db_password`
- `../secrets/.db_root_password`

Mounted as:
- `/run/secrets/db_password`
- `/run/secrets/db_root_password`

### Volumes

- `wordpress_volume` (bind): `/home/stripet/data/wordpress`
- `mariadb_volume` (bind): `/home/stripet/data/mariadb`

### Startup order

- `nginx` depends on `wordpress`
- `wordpress` depends on `mariadb`
- `website` has no explicit dependency

Service readiness is handled inside entrypoints (for example, WordPress waits for MariaDB ping).

## Service behavior

### nginx

- Alpine 3.19 + nginx + openssl
- Generates self-signed cert at startup (`/etc/nginx/certs/server.crt`, `server.key`)
- Handles two HTTPS server blocks:
  - `stripet.42.fr` → `fastcgi_pass wordpress:9000`
  - `cv.stripet.42.fr` → `proxy_pass http://website:80`

### wordpress

- Alpine 3.19 + PHP 8.3 FPM + MariaDB client
- Downloads WordPress (`latest.tar.gz`) during image build
- Entrypoint workflow:
  1. Reads DB passwords from Docker secrets
  2. Waits for MariaDB (`mysqladmin ping`)
  3. Creates `wp-config.php` when missing
  4. Starts `php-fpm83 -F`

### mariadb

- Alpine 3.19 + MariaDB
- Uses config at `/etc/my.cnf.d/mariadb-server.cnf`
- Entrypoint workflow:
  1. Initializes DB when `/var/lib/mysql/mysql` is absent
  2. Creates WordPress DB/user from `.env` + secrets
  3. Sets root password and grants privileges
  4. Starts `mysqld --user=mysql`

### website (bonus)

- Alpine 3.19 + nginx
- Serves static files from `/var/www/html`
- Exposed only inside Compose network and reached through main nginx reverse proxy

## Local requirements

Before running:
- create `secrets/.db_password`
- create `secrets/.db_root_password`
- create `srcs/.env` with at least:
  - `MYSQL_USER`
  - `MYSQL_DATABASE`

## Make targets

From `/inception`:

```bash
make         # default target: build + up
make build   # mkdir bind dirs + docker compose build
make up      # docker compose up -d
make down    # docker compose down
make logs    # docker compose logs -f
make clean   # docker image prune -af
make fclean  # down + docker system prune -af --volumes
make re      # fclean + build + up
```

## Debug commands

```bash
docker compose -f srcs/docker-compose.yml ps
docker compose -f srcs/docker-compose.yml logs -f
docker exec -it nginx sh
docker exec -it wordpress sh
docker exec -it mariadb sh
docker exec -it website sh
```

## Notes

- `srcs/.env` and `secrets/` are intentionally git-ignored.
- `docker system prune --volumes` does not remove host bind directories under `/home/stripet/data/`.
