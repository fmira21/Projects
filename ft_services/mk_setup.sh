#!/bin/bash

#NB:
# The Telegraf pod here works in the Minikube only using the standard Docker inputs from the system Docker socket.
# Probably, it will not work in the real deployment, but looks functional for Docker-based VMs like Minikube.

echo_green()
{
	echo -e "\033[0;32m[v] ${1}\033[0;0m\n"
}

echo_yellow()
{
	echo -e "\033[0;33m[ ] ${1}\033[0;0m\n"
}

echo_red()
{
	echo -e "\033[1;31mERROR:\n [-] ${1}\033[0;0m\n"
}

safe_run()
{
	echo_yellow "$1"
	$2 $3 $4 $5 $6 \
	&& echo_green "$1" \
	&& return
	echo_red "$1"
	exit 1
}

# Starting minikube
safe_run "Starting minikube" \
minikube start --driver=docker

# Enabling addons
for addon in dashboard metrics-server metallb
do
	safe_run "Enabling addon $addon" \
	minikube addons enable $addon
done

echo_yellow "Setup MetalLB"
kubectl apply -f srcs/metallb/configmap.yaml

# Use Docker inside the Minikube
safe_run "minikube docker-env" \
eval "$(minikube docker-env)"

# Building containers, deploying pods and services
for pod in nginx mysql phpmyadmin ftps wordpress influxdb telegraf grafana
do
	safe_run "Building $pod container" \
	docker build -t "$pod"_image srcs/$pod
	echo_yellow "Setup $pod Deployment and Service"
	kubectl apply -f srcs/$pod/$pod.yaml
done

# Opening the dashboard
echo_yellow "Open dashboard"
minikube dashboard
