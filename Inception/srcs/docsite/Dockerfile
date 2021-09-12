FROM debian:buster

RUN apt-get update && apt-get upgrade && apt-get install -y nginx openssl
RUN openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Russia/L=Moscow/O=CAO/OU=Moscow21/CN=fmira" -newkey rsa:2048 -keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt;
COPY ./default.conf /etc/nginx/sites-available/default.conf
COPY ./default.conf /etc/nginx/sites-enabled/default.conf
WORKDIR /var/www/html/
RUN chown -R www-data:www-data *
RUN chmod 755 -R *
CMD ["nginx", "-g", "daemon off;"]