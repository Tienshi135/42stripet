.PHONY: up down build logs clean re fclean

up:
	docker compose -f srcs/docker-compose.yml up -d

down:
	docker compose -f srcs/docker-compose.yml down

build:
	mkdir -p /home/stripet/data/wordpress
	mkdir -p /home/stripet/data/mariadb
	docker compose -f srcs/docker-compose.yml build
	make up

logs:
	docker compose -f srcs/docker-compose.yml logs -f

clean:
	docker compose -f srcs/docker-compose.yml down -v

fclean: clean
	docker system prune -af
	sudo rm -rf /home/stripet/data/wordpress
	sudo rm -rf /home/stripet/data/mariadb

re: fclean build
