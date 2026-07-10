*This project has been created as partof the 42 curriculum by stripet.*

# Description
Inception is a 42-school Docker project that builds a small multi-service stack for learning containerized infrastructure. The stack includes:
- nginx (reverse-proxy, HTTPS)
- WordPress (PHP-FPM)
- MariaDB (database)
- Static website (PHP)
- Adminer for DB management

Everything is defined under `srcs/` so the repository acts as a builder for the Compose stack and images.

# Quick overview / features
- Services: `nginx` (443), `wordpress` (php-fpm, internal 9000), `mariadb` (internal 3306), `website`, `adminer`
- Secrets handled via Docker Compose secrets (files in `srcs/secrets/`)
- Host bind volumes for persistent data: `/home/stripet/data/wordpress` and `/home/stripet/data/mariadb`
- Entrypoint scripts perform service readiness checks and initial setup (DB init, WordPress config)

# Prerequisites
- Docker
- Docker Compose
- Make
- .env
- secrets/

# Instructions
1. From the repository root create the required host directories and ensure secrets exist (the Makefile already does directory creation during `make build`):

```bash
# ensure secret files exist under srcs/secrets/:
# srcs/secrets/.db_password
# srcs/secrets/.db_root_password
# srcs/secrets/.wp_user_password
# srcs/secrets/.wp_admin_password
```

2. Build and start the stack via `make`:

```bash
make         # runs `make build make up`
make build   # builds images
make up      # start the stack
make down    # stop and remove containers
make logs    # follow logs
```

# Ressources Used
- https://docs.docker.com/get-started/docker-concepts/building-images/writing-a-dockerfile/
- Claude (used mainly to scout the web for documentation with some code generated and reviewed / modified)

# Domains / hosts
This project expects the following domain names (used by nginx configuration):
- `stripet.42.fr` -> WordPress site
- `cv.stripet.42.fr` -> bonus static website
- `adminer.stripet.42.fr` -> manager for the DB

Add all three names to your `/etc/hosts` pointing to the machine or VM where you run the stack.

# Usage example
After `make`, open your browser at:

- https://stripet.42.fr  (WordPress)
- https://cv.stripet.42.fr (bonus website — served through the nginx reverse proxy)
- https://adminer.stripet.42.fr (bonus - manager for the DB)

Because the TLS certificate is self-signed, your browser will warn about the certificate — accept the warning to proceed.

