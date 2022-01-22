#NB:
# The Telegraf pod here works in the Minikube only using the standard Docker inputs from the system Docker socket.
# Probably, it will not work in the real deployment, but looks functional for Docker-based VM's like Minikube.


minikube start --driver=hyperv --memory 2000 --cpus 2
minikube addons enable metrics-server
minikube addons enable metallb
minikube addons enable dashboard

minikube -p minikube docker-env --shell powershell | Invoke-Expression

kubectl apply -f srcs/metallb/configmap.yaml

docker build -t nginx_image srcs/nginx
kubectl apply -f srcs/nginx/nginx.yaml

docker build -t mysql_image srcs/mysql
kubectl apply -f srcs/mysql/mysql.yaml

docker build -t wordpress_image srcs/wordpress
kubectl apply -f srcs/wordpress/wordpress.yaml

docker build -t phpmyadmin_image srcs/phpmyadmin
kubectl apply -f srcs/phpmyadmin/phpmyadmin.yaml

docker build -t ftps_image srcs/ftps
kubectl apply -f srcs/ftps/ftps.yaml

docker build -t influxdb_image srcs/influxdb
kubectl apply -f srcs/influxdb/influxdb.yaml

docker build -t telegraf_image srcs/telegraf
kubectl apply -f srcs/telegraf/telegraf.yaml

docker build -t grafana_image srcs/grafana
kubectl apply -f srcs/grafana/grafana.yaml

minikube dashboard