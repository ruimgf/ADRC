FROM ubuntu:16.04
RUN apt-get update && apt-get install -y \
  gcc 

ADD src /home/src
WORKDIR /home
