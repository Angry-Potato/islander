from ubuntu:16.04

RUN apt-get update
RUN apt-get -y install g++ gdb libsdl1.2debian libglu1-mesa build-essential

COPY . /islander

WORKDIR /islander

CMD ["make"]
