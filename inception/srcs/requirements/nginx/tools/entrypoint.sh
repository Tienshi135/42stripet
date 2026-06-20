#!/bin/sh


if [ ! -f "/etc/nginx/certs/server.crt" ]; then
	mkdir -p /etc/nginx/certs
	openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-keyout /etc/nginx/certs/server.key \
	-out /etc/nginx/certs/server.crt \
	-subj "/CN=stripet.42.fr"
fi


exec nginx -g "daemon off;"
