FROM ubuntu:latest

WORKDIR /root
RUN mkdir Game
WORKDIR /root/Game
COPY . .
WORKDIR /root/Game/build

RUN apt-get update
RUN apt-get install -y build-essential git tree
RUN apt install -y libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev

RUN ./premake5 gmake2
WORKDIR /root/Game
RUN make
RUN apt-get install -y x11vnc xvfb
RUN tree .
RUN chmod +x bin/Debug/Game
RUN echo "exec ~/Game/bin/Debug/Game" > ~/.xinitrc && chmod +x ~/.xinitrc
EXPOSE 5900/tcp
EXPOSE 5900/udp

RUN export DISPLAY=:20
RUN Xvfb :20 -screen 0 1366x768x16 &
CMD ["x11vnc", "-create", "-display", ":20", "-N", "-forever", "&"]

LABEL org.opencontainers.image.licenses=GPL-3.0-or-later
LABEL org.opencontainers.image.description="Container image for The Tiny Marmalade Game"
LABEL org.opencontainers.image.source=https://github.com/JTech-Labs/TheTinyMArmaladeGame
LABEL version="0.0.0"
