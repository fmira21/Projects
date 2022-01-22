FROM  alpine:3.12

RUN apk update && apk upgrade \
	&& apk add -X http://dl-cdn.alpinelinux.org/alpine/edge/community/ grafana \
	&& rm -rf /var/cache/apk/*

COPY /config/dashboards/* /usr/share/grafana/conf/dashboards/
COPY /config/provisioning/dashboards/* /usr/share/grafana/conf/provisioning/dashboards/
COPY /config/provisioning/datasources/* /usr/share/grafana/conf/provisioning/datasources/

# After installation, Grafana will be able to use the standard config. Duplicated in the folder.

EXPOSE 3000

ENTRYPOINT [ "grafana-server", "--homepath=/usr/share/grafana" ]
