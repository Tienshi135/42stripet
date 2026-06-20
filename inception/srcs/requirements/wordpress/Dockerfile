FROM alpine:3.19


RUN apk add --no-cache \
	php83 \
	php83-fpm \
	php83-mysqli \
	php83-json \
	php83-curl \
	php83-dom \
	php83-exif \
	php83-fileinfo \
	php83-mbstring \
	php83-openssl \
	php83-xml \
	wget \
	unzip \
	openssl \
	mariadb-client


RUN mkdir -p /var/www/html && \
	wget https://wordpress.org/latest.tar.gz -P /tmp && \
	tar -xzf /tmp/latest.tar.gz -C /var/www/html --strip-components=1 && \
	rm /tmp/latest.tar.gz


COPY conf/www.conf /etc/php83/php-fpm.d/www.conf
COPY tools/entrypoint.sh /entrypoint.sh


RUN chmod +x /entrypoint.sh && \
	chown -R nobody:nobody /var/www/html


EXPOSE 9000


ENTRYPOINT ["/entrypoint.sh"]
