# Inception

42 infrastructure project using Docker Compose with Alpine-based services:
- **nginx** (public HTTPS reverse proxy, `443:443`)
- **wordpress** (PHP-FPM, internal `9000`)
- **mariadb** (database, internal `3306`)
- **website** (bonus static site, internal `80`)

## Documentation files

- `README.md`: project overview and setup
- `USER_DOC.md`: user-facing usage guide
- `DEV_DOC.md`: technical/runtime details

## Prerequisites

- Docker Engine + Docker Compose plugin
- `make`
- Permission to create directories under:
  - `/home/stripet/data/wordpress`
  - `/home/stripet/data/mariadb`

## Required local files (not committed)

Create these before starting services:

1) `secrets/.db_password`
2) `secrets/.db_root_password`
3) `srcs/.env`

Example `srcs/.env`:

```env
MYSQL_USER=stripet_user
MYSQL_DATABASE=wordpress_db
```

## Quick start

1. Add host mappings on your machine:
   ```bash
   sudo sh -c 'echo "<VM_IP> stripet.42.fr cv.stripet.42.fr" >> /etc/hosts'
   ```
2. Build images and start all services:
   ```bash
   make
   ```
   (`make` uses the default `inception` target, which runs `build` then `up`.)
3. Open:
   - WordPress: `https://stripet.42.fr`
   - Bonus website: `https://cv.stripet.42.fr`

## Make targets

```bash
make         # default target: build then up
make up      # docker compose up -d
make down    # docker compose down
make build   # create bind dirs and build images
make logs    # follow compose logs
make clean   # docker image prune -af
make fclean  # down + docker system prune -af --volumes
make re      # fclean then build then up
```

## Service summary

- **nginx**
  - Dockerfile: `srcs/requirements/nginx/Dockerfile`
  - Config: `srcs/requirements/nginx/conf/nginx.conf`
  - TLS cert generation: `srcs/requirements/nginx/tools/entrypoint.sh`
  - Routes:
    - `stripet.42.fr` → `wordpress:9000`
    - `cv.stripet.42.fr` → `website:80`

- **wordpress**
  - Dockerfile: `srcs/requirements/wordpress/Dockerfile`
  - PHP-FPM config: `srcs/requirements/wordpress/conf/www.conf`
  - Runtime config generation: `srcs/requirements/wordpress/tools/entrypoint.sh`

- **mariadb**
  - Dockerfile: `srcs/requirements/mariadb/Dockerfile`
  - DB config: `srcs/requirements/mariadb/conf/server.cnf`
  - DB init/startup: `srcs/requirements/mariadb/tools/entrypoint.sh`

- **website** (bonus)
  - Dockerfile: `srcs/requirements/bonus/website/Dockerfile`
  - Nginx config: `srcs/requirements/bonus/website/conf/nginx.conf`
  - Static content: `srcs/requirements/bonus/website/html/`

## Data and networking

- Volumes:
  - `wordpress_volume` → `/home/stripet/data/wordpress`
  - `mariadb_volume` → `/home/stripet/data/mariadb`
- Internal network: `inception` (bridge)
- Only nginx is exposed to host (`443`)

## Troubleshooting

- Container status:
  ```bash
  docker compose -f srcs/docker-compose.yml ps
  ```
- Logs:
  ```bash
  make logs
  ```
- Full reset:
  ```bash
  make re
  ```
