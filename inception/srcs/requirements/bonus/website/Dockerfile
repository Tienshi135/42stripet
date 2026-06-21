FROM alpine:3.19


RUN apk add --no-cache nginx


COPY conf/nginx.conf /etc/nginx/http.d/default.conf
COPY html/ /var/www/html


RUN mkdir -p /var/run/nginx


EXPOSE 80


ENTRYPOINT ["nginx", "-g", "daemon off;"]
