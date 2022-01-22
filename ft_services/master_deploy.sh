kubectl apply -f srcs/metallb/configmap.yaml
docker build -t nginx_image srcs/nginx
docker build -t mysql_image srcs/mysql
docker build -t wordpress_image srcs/wordpress
docker build -t phpmyadmin_image srcs/phpmyadmin
docker build -t ftps_image srcs/ftps
docker build -t influxdb_image srcs/influxdb
#docker build -t telegraf_image srcs/telegraf
docker build -t grafana_image srcs/grafana

kubectl apply -f srcs/nginx/nginx.yaml
kubectl apply -f srcs/mysql/mysql.yaml
kubectl apply -f srcs/wordpress/wordpress.yaml
kubectl apply -f srcs/phpmyadmin/phpmyadmin.yaml
kubectl apply -f srcs/ftps/ftps.yaml
kubectl apply -f srcs/influxdb/influxdb.yaml
#kubectl apply -f srcs/telegraf/telegraf.yaml
kubectl apply -f srcs/grafana/grafana.yaml

# External IP's:
sudo kubectl patch svc nginx-service -p '{"spec":{"externalIPs":["185.15.87.188"]}}'
sudo kubectl patch svc wordpress-service -p '{"spec":{"externalIPs":["185.15.87.188"]}}'
sudo kubectl patch svc phpmyadmin-service -p '{"spec":{"externalIPs":["185.15.87.188"]}}'
sudo kubectl patch svc ftps-service -p '{"spec":{"externalIPs":["185.15.87.188"]}}'
sudo kubectl patch svc grafana-service -p '{"spec":{"externalIPs":["185.15.87.188"]}}'