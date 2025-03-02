FROM docker.io/library/golang:1.24.0-bookworm AS easy-novnc-build
WORKDIR /src
RUN go mod init build && \
    go get github.com/geek1011/easy-novnc@v1.1.0 && \
    go build -o /bin/easy-novnc github.com/geek1011/easy-novnc

    
FROM docker.io/library/ubuntu:latest

RUN groupadd --gid 1001 app && \
    useradd --home-dir /data --shell /bin/bash --uid 1001 --gid 1001 app && \
    mkdir -p /data \
    mkdir /data/Game
COPY . /data/Game/

WORKDIR /data/Game
COPY . .
WORKDIR /data/Game/build

RUN apt-get update
RUN apt-get install -y build-essential git tree
RUN apt install -y libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev

RUN ./premake5 gmake2
WORKDIR /data/Game
RUN make


RUN apt-get update -y && \
    apt-get install -y --no-install-recommends openbox tigervnc-standalone-server supervisor gosu && \
    rm -rf /var/lib/apt/lists && \
    mkdir -p /usr/share/desktop-directories
RUN apt-get update -y && \
    apt-get install -y --no-install-recommends lxterminal nano wget openssh-client rsync ca-certificates xdg-utils htop tar xzip gzip bzip2 zip unzip && \
    rm -rf /var/lib/apt/lists

COPY --from=easy-novnc-build /bin/easy-novnc /usr/local/bin/
COPY menu.xml /etc/xdg/openbox/
COPY supervisord.conf /etc/
EXPOSE 8080


RUN tree .
RUN chmod +x /data/Game/bin/Debug/Game
VOLUME /data

CMD ["sh", "-c", "chown app:app /data /dev/stdout && exec gosu app supervisord"]

LABEL org.opencontainers.image.licenses=GPL-3.0-or-later
LABEL org.opencontainers.image.description="Container image for The Tiny Marmalade Game"
LABEL org.opencontainers.image.source=https://github.com/JTech-Labs/TheTinyMArmaladeGame
LABEL version="0.0.0"
