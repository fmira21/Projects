# Basic rule: build or rebuild the composed containers
all:
	docker-compose -f srcs/docker-compose.yml --env-file ./srcs/.env up --build
# Assign 42.fr to the localhost
hosts:
	echo "127.0.0.1 fmira.42.fr" | tee -a /etc/hosts
# Copy the RST docs to the volume
docs:
	cp -r ./srcs/sphinx/sphinx-docs/* /home/fmira/data/sphinx/
# Stop the containers
clean:
	docker-compose -f srcs/docker-compose.yml down
# Remove the volumes. To remove the images, use the RELOAD rule
fclean: clean
	docker system prune -a --volumes
# Remove all volumes and images. In order to stop all containers, remove them and clear volume directories, launch the separate reload.sh script.
reload: clean
	docker stop $(docker ps -qa)
	docker rm $(docker ps -qa)
	docker rmi -f $(docker images -qa)
	docker volume rm $(docker volume ls -q)
	docker network rm $(docker network ls -q) 2>/dev/null
# Remove all volumes and rebuild
re: fclean all
