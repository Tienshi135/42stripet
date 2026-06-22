# Developer Documentation

## Architecture

Three-service stack on Docker Compose:
- `nginx` (public HTTPS, `443:443`)
- `wordpress` (PHP-FPM, internal `9000`)
- `mariadb` (DB, internal `3306`)

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

## Compose details

### Secrets
Defined from local files:
- `../secrets/.db_password`
- `../secrets/.db_root_password`

Mounted in containers as:
- `/run/secrets/db_password`
- `/run/secrets/db_root_password`

### Volumes
- `wordpress_volume` → `/home/stripet/data/wordpress`
- `mariadb_volume` → `/home/stripet/data/mariadb`

### Startup order
- nginx depends on wordpress
- wordpress depends on mariadb

Readiness checks are handled inside entrypoints (for example, WordPress waits for MariaDB ping).

## Service behavior

### nginx
- Alpine 3.19 + nginx + openssl
- Generates self-signed cert at first start (`/etc/nginx/certs/server.crt`, `server.key`)
- Uses:
  - `listen 443 ssl http2;`
  - `fastcgi_pass wordpress:9000;`
  - `server_name stripet.42.fr;` (currently hardcoded)

### wordpress
- Alpine 3.19 + PHP 8.3 FPM + MariaDB client
- Downloads WordPress from `https://wordpress.org/latest.tar.gz` during image build
- Entry point:
  1. Reads DB secrets
  2. Waits for MariaDB (`mysqladmin ping`)
  3. Generates `wp-config.php` if missing
  4. Starts `php-fpm83 -F`

### mariadb
- Alpine 3.19 + MariaDB
- Config copied to `/etc/my.cnf.d/mariadb-server.cnf`
- Entry point:
  1. Initializes DB if `/var/lib/mysql/mysql` absent
  2. Creates DB/user with values from `.env` + secrets
  3. Sets root password and grants privileges
  4. Starts `mysqld --user=mysql`

## Local requirements

Before running:
- create `secrets/.db_password`
- create `secrets/.db_root_password`
- create `srcs/.env` with at least:
  - `DOMAIN_NAME`
  - `MYSQL_USER`
  - `MYSQL_DATABASE`

## Commands

From `/inception`:

```bash
make build   # mkdir bind dirs, build images, up -d
make up
make down
make logs
make clean
make fclean
make re
```

## Useful debug commands

```bash
docker compose -f srcs/docker-compose.yml ps
docker compose -f srcs/docker-compose.yml logs -f
docker exec -it nginx sh
docker exec -it wordpress sh
docker exec -it mariadb sh
```

## Notes

- `srcs/.env` and `secrets/` are intentionally git-ignored.
- `make fclean` removes Docker resources and `/home/stripet/data/*`.
