.DEFAULT_GOAL := inception
.PHONY: up down build logs clean re fclean inception

up:
	docker compose -f srcs/docker-compose.yml up -d

down:
	docker compose -f srcs/docker-compose.yml down

build:
	mkdir -p /home/stripet/data/wordpress
	mkdir -p /home/stripet/data/mariadb
	docker compose -f srcs/docker-compose.yml build

logs:
	docker compose -f srcs/docker-compose.yml logs -f

clean:
	docker image prune -af

fclean: down
	docker system prune -af --volumes

re: fclean build up

inception: build up
