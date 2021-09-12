FROM debian:buster

RUN apt-get update && apt-get upgrade && apt-get install -y python3-sphinx && apt-get install -y python3-pip && pip3 install furo
RUN mkdir ./src
COPY ./conf.py ./src
COPY build.sh /
RUN mkdir ./sphinx
RUN mkdir ./doc
CMD sh build.sh