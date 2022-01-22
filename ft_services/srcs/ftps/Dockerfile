FROM  alpine:3.12

RUN apk update && apk upgrade \
	&& apk add openssl vsftpd bash \
	&& rm -rf /var/cache/apk/*

# Telegraf section
RUN apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/ --allow-untrusted --no-cache
COPY	telegraf.conf			/etc/telegraf/

# Generate the FTPS drectory
RUN mkdir -p /ftps/fmira \
	&& adduser --home=/ftps/fmira -D fmira \
	&& echo 'fmira:fmira' | chpasswd \
	&& chmod -R 777 /ftps \
	&& chown -R fmira:fmira /ftps

# Generate the SSL certificate: still, the Filezilla will detect the self-signed cert
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
	-out /etc/ssl/certs/vsftpd.pem -keyout /etc/ssl/certs/vsftpd.key \
	-subj "/C=RU/ST=Moscow/L=Moscow/O=21-school/OU=fmira/CN=fmira"

COPY ./vsftpd.conf /etc/vsftpd/
COPY start_ftps.sh /tmp/start_ftps.sh
RUN chmod 644 /tmp/start_ftps.sh

EXPOSE 20-21 21041-21044

ENTRYPOINT ["bash", "/tmp/start_ftps.sh"]
