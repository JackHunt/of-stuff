FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive

WORKDIR /root

RUN apt-get update && apt-get install -y \
    build-essential \
    git \
    cmake \
    wget \
    unzip \
    sudo \
    lsb-release \
    && rm -rf /var/lib/apt/lists/*

RUN git clone --depth 1 --branch 0.12.0 https://github.com/openframeworks/openFrameworks.git

ENV OF_SILENT=1

WORKDIR /root/openFrameworks/scripts/linux/ubuntu
RUN ./install_dependencies.sh

WORKDIR /root/openFrameworks/scripts/linux
RUN ./download_libs.sh
RUN ./compileOF.sh -j8

WORKDIR /root/openFrameworks/
RUN git submodule init && git submodule update

WORKDIR /root/openFrameworks/apps/projectGenerator/commandLine
RUN make Release

RUN mkdir /projects && ln -s /projects /root/openFrameworks/apps/myApps
WORKDIR /root/openFrameworks/apps/myApps

# Drop into a shell when the container starts
CMD ["/bin/bash"]
