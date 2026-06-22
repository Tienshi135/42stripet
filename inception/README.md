# Inception

42 infrastructure project using Docker Compose with 3 Alpine-based services:
- **nginx** (HTTPS reverse proxy, port 443)
- **wordpress** (PHP-FPM, port 9000 internal)
- **mariadb** (database, port 3306 internal)

## What this repository contains

- `README.md`: project overview and setup
- `USER_DOC.md`: usage guide for WordPress users
- `DEV_DOC.md`: technical notes for development/maintenance
- `Makefile`: common lifecycle commands
- `srcs/docker-compose.yml`: service orchestration
- `srcs/requirements/*`: Dockerfiles, configs, and entrypoints

## Prerequisites

- Docker Engine + Docker Compose plugin
- `make`
- Permission to create/remove:
  - `/home/stripet/data/wordpress`
  - `/home/stripet/data/mariadb`

## Required local files (not committed)

Create these before `make build`:

1) `secrets/.db_password`
2) `secrets/.db_root_password`
3) `srcs/.env`

Example `srcs/.env`:

```env
DOMAIN_NAME=stripet.42.fr
MYSQL_USER=stripet_user
MYSQL_DATABASE=wordpress_db
```

> Note: nginx server_name is currently hardcoded to `stripet.42.fr` in `srcs/requirements/nginx/conf/nginx.conf`.

## Quick start

1. Add host mapping on your machine:
   ```bash
   sudo sh -c 'echo "<VM_IP> stripet.42.fr" >> /etc/hosts'
   ```
2. Build and start:
   ```bash
   make build
   ```
3. Open:
   - `https://stripet.42.fr`

## Make targets

```bash
make up       # docker compose up -d
make down     # docker compose down
make build    # create bind dirs, build images, then up
make logs     # follow compose logs
make clean    # compose down -v
make fclean   # clean + docker system prune -af + remove /home/stripet/data/*
make re       # fclean then build
```

## Service summary

- **nginx**
  - Dockerfile: `srcs/requirements/nginx/Dockerfile`
  - Config: `srcs/requirements/nginx/conf/nginx.conf`
  - TLS cert generation: `srcs/requirements/nginx/tools/entrypoint.sh`

- **wordpress**
  - Dockerfile: `srcs/requirements/wordpress/Dockerfile`
  - PHP-FPM config: `srcs/requirements/wordpress/conf/www.conf`
  - Runtime config generation: `srcs/requirements/wordpress/tools/entrypoint.sh`

- **mariadb**
  - Dockerfile: `srcs/requirements/mariadb/Dockerfile`
  - DB config: `srcs/requirements/mariadb/conf/server.cnf`
  - DB init/startup: `srcs/requirements/mariadb/tools/entrypoint.sh`

## Data and networking

- Volumes map to:
  - `wordpress_volume` → `/home/stripet/data/wordpress`
  - `mariadb_volume` → `/home/stripet/data/mariadb`
- Internal network: `inception` (bridge)
- Only nginx is published to host (`443:443`)

## Troubleshooting

- Check containers:
  ```bash
  docker ps
  ```
- Check logs:
  ```bash
  docker compose -f srcs/docker-compose.yml logs -f
  ```
- Reset stack:
  ```bash
  make re
  ```
