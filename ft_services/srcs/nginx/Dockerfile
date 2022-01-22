FROM  alpine:3.12

RUN apk update && apk upgrade
RUN apk add nginx sudo bash openssh openssl \
	&& rm -rf /var/cache/apk/*

RUN adduser -D -g 'www' www \
	&& mkdir /www \
	&& chown -R www:www /var/lib/nginx \
	&& chown -R www:www /www

RUN mkdir -p var/run/nginx
RUN mv /etc/nginx/nginx.conf /etc/nginx/nginx.conf.orig
COPY nginx.conf /etc/nginx/

RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
	-out /etc/ssl/certs/nginx.pem -keyout /etc/ssl/certs/nginx.key \
	-subj "/C=RU/ST=Moscow/L=Moscow/O=21-school/OU=homeoffice/CN=fmira"

RUN adduser -D fmira && echo 'fmira:fmira' | chpasswd \
	&& addgroup fmira wheel && echo '%wheel ALL=(ALL) ALL' > /etc/sudoers.d/wheel \
	&& ssh-keygen -A

# Telegraf section
RUN apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/ --allow-untrusted --no-cache
COPY	telegraf.conf			/etc/telegraf/

COPY index.html /www/
COPY start_nginx.sh /tmp/start_nginx.sh
RUN chmod 644 /tmp/start_nginx.sh

EXPOSE 80 443 22

ENTRYPOINT ["bash", "/tmp/start_nginx.sh"]
