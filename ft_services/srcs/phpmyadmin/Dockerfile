FROM  alpine:3.12

RUN apk update && apk upgrade
RUN apk add nginx bash wget

RUN apk add php7 php7-fpm php7-gd php7-mysqli \
	php7-zlib php7-curl php7-mbstring php7-json php7-session

RUN adduser -D -g 'fmira' fmira \
	&& mkdir -p /www/phpmyadmin \
	&& chown -R fmira:fmira /var/lib/nginx \
	&& chown -R fmira:fmira /www

RUN mkdir -p var/run/nginx

RUN mv /etc/nginx/nginx.conf /etc/nginx/nginx.conf.orig
COPY ./nginx.conf /etc/nginx/

RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz\
	&& tar -C /www/phpmyadmin -xvzf phpMyAdmin-5.0.4-english.tar.gz --strip-components 1 \
	&& rm -rf phpMyAdmin-5.0.4-english.tar.gz

# Telegraf section
RUN apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/ --allow-untrusted --no-cache
COPY	telegraf.conf			/etc/telegraf/

COPY config.inc.php /www/phpmyadmin
COPY start_phpmyadmin.sh /tmp/start_phpmyadmin.sh
RUN chmod 644 /tmp/start_phpmyadmin.sh

#Look here: On my server, 5000 is already busy - slightly moved to 5001.
EXPOSE 5001

ENTRYPOINT ["bash", "/tmp/start_phpmyadmin.sh"]
