cd srcs 
docker-compose build --no-cache sphinx
docker-compose up -d --force-recreate --no-deps sphinx