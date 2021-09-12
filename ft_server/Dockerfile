FROM debian:buster

#Get necessary packages
RUN apt-get update && apt-get upgrade -y && apt-get -y install wget && apt-get -y install nginx && apt-get -y install mariadb-server && apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring

#Enable the working directory
WORKDIR /var/www/html/

#Dl and conf phpmyadmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
RUN tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz
RUN mv phpMyAdmin-5.0.1-english phpmyadmin
COPY ./srcs/config.inc.php phpmyadmin

#Dl and conf WP
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz && rm -rf latest.tar.gz
COPY ./srcs/wp-config.php /var/www/html
COPY ./srcs/nginx-aion.conf /etc/nginx/sites-available
COPY ./srcs/nginx-aion.conf /etc/nginx/sites-enabled
RUN rm -rf /etc/nginx/sites-enabled/default

#Get the SSL key and certificate
RUN openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Russia/L=Moscow/O=CAO/OU=Moscow21/CN=fmira" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt;

#Copy the autoindex switches
COPY ./srcs/nginx-aioff.conf ./
COPY ./srcs/nginx-aion.conf ./
COPY ./srcs/autoindex_on.sh ./
COPY ./srcs/autoindex_off.sh ./

COPY ./srcs/autoindex ./autoindex

#Copy the docs
COPY ./srcs/doc ./doc

#Grant privileges 
RUN chown -R www-data:www-data *
RUN chmod 755 -R *

#Copy the init script and execute on start
COPY ./srcs/init.sh ./
CMD bash init.sh

#Restrict the used ports
EXPOSE 80 443
