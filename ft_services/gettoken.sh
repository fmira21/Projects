#You will see the unsafe warning in chrome. To bypass, type "thisisunsafe" in the same window of the browser

#To login the dashboard, you will need this.

kubectl describe secrets -n kube-system $(kubectl -n kube-system get secret | awk '/dashboard-admin/{print $1}')


#sudo kubectl patch svc nginx -p '{"spec":{"externalIPs":["185.15.87.188"]}}'