# Here I have attached a query to demonstrate that the command works.

cd ./srcs
docker-compose exec mysql mysql -u fmira -ppass -h mysql wordpress -e "SELECT * from wp_posts;"
