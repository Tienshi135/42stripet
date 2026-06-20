From alpine:3.19


RUN apk add --no-cache nginx openssl


COPY conf/nginx.conf /etc/nginx/http.d/default.conf
COPY tools/entrypoint.sh /entrypoint.sh


RUN chmod +x /entrypoint.sh && mkdir -p /var/www/html


EXPOSE 443


ENTRYPOINT ["/entrypoint.sh"]
