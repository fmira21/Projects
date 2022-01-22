FROM  alpine:3.12

RUN apk update && apk upgrade
RUN apk add nginx bash wget

RUN apk add php7 php7-fpm php7-gd php7-mysqli \
	php7-zlib php7-curl php7-mbstring php7-json php7-session

RUN adduser -D -g 'fmira' fmira \
	&& mkdir -p /www/wordpress \
	&& chown -R fmira:fmira /var/lib/nginx \
	&& chown -R fmira:fmira /www

RUN mkdir -p var/run/nginx

RUN mv /etc/nginx/nginx.conf /etc/nginx/nginx.conf.orig
COPY ./nginx.conf /etc/nginx/

RUN wget https://wordpress.org/wordpress-5.6.tar.gz \
	&& tar -C /www/wordpress/ -xvzf wordpress-5.6.tar.gz --strip-components 1\
	&& rm -rf wordpress-5.6.tar.gz \
	&& chown -R fmira:fmira /www/wordpress/ \
	&& chmod -R 755 /www/wordpress/

# Telegraf section
RUN apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/ --allow-untrusted --no-cache
COPY	telegraf.conf			/etc/telegraf/

COPY wp-config.php /www/wordpress/
COPY start_wordpress.sh /tmp/start_wordpress.sh
RUN chmod 644 /tmp/start_wordpress.sh

EXPOSE 5050

ENTRYPOINT ["bash", "/tmp/start_wordpress.sh"]
