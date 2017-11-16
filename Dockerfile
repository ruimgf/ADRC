FROM debian
RUN apt-get update && apt-get install -y \
  gcc \
  make

ADD p1 /home/p1
ADD p2 /home/p2
WORKDIR /home
