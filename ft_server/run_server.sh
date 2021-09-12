docker-machine restart
eval "$(docker-machine env default)"
docker build -t fmira .
docker run -it --rm --publish 80:80 443:443 fmira