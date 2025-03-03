FROM docker.io/library/ubuntu:latest

RUN apt-get update
RUN apt-get install -y build-essential git tree
RUN apt-get install -y libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev

RUN apt-get install -y software-properties-common
RUN add-apt-repository ppa:pipewire-debian/pipewire-upstream
RUN apt-get update

RUN apt update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y lubuntu-desktop

RUN wget https://github.com/rustdesk/rustdesk/releases/download/1.3.8/rustdesk-1.3.8-x86_64.deb && apt-get install -fy rustdesk-1.3.8-x86_64.deb

RUN mkdir /root/Game
WORKDIR /root/Game
COPY . .
WORKDIR /root/Game/build
RUN premake5 gmake2
WORKDIR /root/Game
RUN make
RUN chmod +x /root/Game/bin/Debug/Game

RUN rustesk --get-id
RUN rustedsk --password remote

CMD rustdesk

LABEL org.opencontainers.image.licenses=GPL-3.0-or-later
LABEL org.opencontainers.image.description="Container image for The Tiny Marmalade Game"
LABEL org.opencontainers.image.source=https://github.com/JTech-Labs/TheTinyMArmaladeGame
LABEL version="0.0.0"
