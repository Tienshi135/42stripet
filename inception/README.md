# Inception

A Docker-based infrastructure project that sets up a complete web server stack with nginx, WordPress, and MariaDB on Alpine Linux containers.

## Project Overview

Inception is a 42 School project that demonstrates containerization and infrastructure-as-code principles. It creates a multi-container application using Docker Compose, featuring:

- **nginx** — reverse proxy and web server (TLS 1.2/1.3)
- **WordPress + PHP-FPM** — content management system
- **MariaDB** — relational database

All services run on Alpine Linux 3.19 for minimal footprint, communicate via a custom Docker bridge network, and persist data using named volumes.

## Requirements

- Docker Engine (20.10+)
- Docker Compose (2.0+)
- Linux VM or VirtualBox with bridged networking
- `make` command-line tool

## Quick Start

### 1. Clone and Enter the Project

```bash
cd inception
```

### 2. Configure Your Domain

Add your VM's IP to your local `/etc/hosts` (on your host machine):

```bash
sudo vim /etc/hosts
```

Add the line:
192.168.1.100  stripet.42.fr

(Replace `192.168.1.100` with your VM's actual IP if different.)

### 3. Build and Start the Stack

```bash
make build
```

This will:
- Create directories for persistent data at `/home/stripet/data/wordpress` and `/home/stripet/data/mariadb`
- Build three Docker images (nginx, wordpress, mariadb)
- Start all containers
- Initialize the MariaDB database
- Generate self-signed TLS certificates

### 4. Access WordPress

Open your browser and navigate to:
https://stripet.42.fr

You'll be prompted to complete the WordPress installation wizard. Create an admin user (username cannot contain "admin") and configure your site.

## Available Commands

```bash
make up       # Start containers (without rebuilding)
make down     # Stop and remove containers (keeps data)
make build    # Full rebuild (clean and build)
make logs     # Stream logs from all containers
make clean    # Stop containers and remove volumes
make fclean   # Complete reset (removes all data and images)
make re       # Full reset and rebuild
```

## Project Structure
inception/

├── README.md              # This file

├── USER_DOC.md           # End-user documentation

├── DEV_DOC.md            # Developer/technical documentation

├── Makefile              # Build automation

├── secrets/              # Docker secrets (not in git)

│   ├── db_password

│   └── db_root_password

└── srcs/

├── .env              # Environment variables

├── docker-compose.yml # Container orchestration

└── requirements/     # Service definitions

├── nginx/

│   ├── Dockerfile

│   ├── conf/

│   └── tools/

├── wordpress/

│   ├── Dockerfile

│   ├── conf/

│   └── tools/

└── mariadb/

├── Dockerfile

├── conf/

└── tools/

## Architecture

### Networking

All containers communicate via a custom `inception` bridge network:
- **nginx** (public): listens on VM's port 443 (HTTPS)
- **wordpress**: exposes port 9000 internally for PHP-FPM
- **mariadb**: exposes port 3306 internally for database connections

### Data Persistence

Named volumes with local driver bind mounts:
- `wordpress_volume` → `/home/stripet/data/wordpress`
- `mariadb_volume` → `/home/stripet/data/mariadb`

Data persists across container restarts but is deleted with `make fclean`.

### Security

- All traffic is encrypted with TLS 1.2 and 1.3
- Database passwords stored in Docker secrets (not in Dockerfiles or `.env`)
- No hardcoded credentials in images
- MariaDB only accepts local socket connections during initialization, then binds to network

## Troubleshooting

### "Unable to connect to server"

1. Verify containers are running: `docker ps`
2. Check logs: `docker logs nginx`
3. Ensure `/etc/hosts` has the correct VM IP
4. Accept the self-signed certificate warning in your browser

### "Connection refused on port 3306"

1. Verify MariaDB initialized: `docker logs mariadb | grep "ready for connections"`
2. Check network connectivity: `docker exec wordpress ping mariadb`
3. Rebuild cleanly: `make fclean && make build`

### Data persists after `make down` but not `make fclean`

This is by design. `make down` preserves `/home/stripet/data/` for quick restarts. `make fclean` removes everything for a complete reset.

## Author

stripet (stripet.42.fr)

## License

This project is part of the 42 School curriculum.
