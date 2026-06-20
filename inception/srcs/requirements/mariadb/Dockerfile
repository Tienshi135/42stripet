FROM alpine:3.19


RUN apk add --no-cache mariadb mariadb-client


COPY conf/server.cnf /etc/my.cnf.d/mariadb-server.cnf
COPY tools/entrypoint.sh /entrypoint.sh


RUN chmod +x /entrypoint.sh


EXPOSE 3306


ENTRYPOINT ["/entrypoint.sh"]
