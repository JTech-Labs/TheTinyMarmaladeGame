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
