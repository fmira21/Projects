FROM  alpine:3.12

RUN apk update && apk upgrade \
	&& apk add mysql mysql-client bash \
	&& rm -rf /var/cache/apk/*

COPY start_mysql.sh /tmp/start_mysql.sh
COPY wordpress.sql my.cnf ./

# Telegraf section
RUN apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/ --allow-untrusted --no-cache
COPY	telegraf.conf			/etc/telegraf/

RUN mkdir -p /run/mysqld \
	&& mv my.cnf /etc/

RUN chmod 644 /tmp/start_mysql.sh

VOLUME ["/var/lib/mysql"]

EXPOSE 3306

ENTRYPOINT ["bash", "/tmp/start_mysql.sh"]
