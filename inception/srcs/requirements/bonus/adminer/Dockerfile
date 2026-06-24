FROM alpine:3.19

RUN apk add --no-cache nginx php83 php83-fpm php83-session php83-pdo php83-pdo_mysql php83-mysqli wget



RUN mkdir -p /var/www/html && \
	wget -O /var/www/html/adminer.php https://www.adminer.org/latest.php

COPY conf/nginx.conf /etc/nginx/http.d/default.conf
COPY conf/php-fpm.conf /etc/php83/php-fpm.d/www.conf
COPY tools/entrypoint.sh /entrypoint.sh

RUN chmod +x /entrypoint.sh \
    && mkdir -p /var/run/nginx \
    && chmod 755 /var/www/html/adminer.php

EXPOSE 80

ENTRYPOINT ["/entrypoint.sh"]
