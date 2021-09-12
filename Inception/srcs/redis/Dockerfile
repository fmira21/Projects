FROM debian:buster
RUN apt-get update && apt-get upgrade && apt-get install -y redis-server
COPY ./redis.conf /etc/redis/redis.conf
CMD redis-server /etc/redis/redis.conf