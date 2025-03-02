LABEL org.opencontainers.image.licenses=GPL-3.0-or-later
LABEL org.opencontainers.image.description="Container image for The Tiny Marmalade Game"
LABEL org.opencontainers.image.source=https://github.com/JTech-Labs/TheTinyMArmaladeGame
LABEL version="0.0.0"

FROM ubuntu:latest
RUN mkdir Game
WORKDIR Game
COPY . .
WORKDIR build
RUN premake gmake2
WORKDIR ..
RUN make
RUN apt-get update && apt-get install -y x11vnc xvfb
RUN chmod +x bin/debug/TheTinyMarmaladeGame
RUN echo "exec ~/Game/bin/debug/TheTinyMarmaladeGame" > ~/.xinitrc && chmod +x ~/.xinitrc
EXPOSE 5900/tcp
EXPOSE 5900/udp
CMD ["v11vnc", "-create", "-forever"]
