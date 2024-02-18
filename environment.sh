#!/bin/bash

force_rebuild=0
if [ $# -ne 0 ]; then
  for arg in "$@"
  do
    case $arg in
      --force-rebuild)
        force_rebuild=1
        ;;
      *)
        ;;
    esac
  done
fi

IMAGE_NAME="openframeworks-ubuntu"
IMAGE_TAG="0.12.0"

PROJECTS_DIR="$(dirname "$0")/projects"

if [[ "$(docker images -q $IMAGE_NAME:$IMAGE_TAG 2> /dev/null)" == "" || force_rebuild -ne 0 ]]; then
  echo "Image does not exist, building..."
  docker build --no-cache -t $IMAGE_NAME:$IMAGE_TAG .
fi

# Taken from
# https://github.com/ybycode/docker-openframeworks/blob/master/run.sh
XSOCK=/tmp/.X11-unix
XAUTH=/tmp/.docker.xauth
touch $XAUTH
xauth nlist $DISPLAY | sed -e 's/^..../ffff/' | xauth -f $XAUTH nmerge -

docker run -it --rm \
  -v "$PROJECTS_DIR:/projects" \
  --volume=$XSOCK:$XSOCK \
  --volume=$XAUTH:$XAUTH \
  --env="XAUTHORITY=${XAUTH}" \
  --env="DISPLAY" \
  --device=/dev/dri:/dev/dri \
  --volume=/run/user/$(id -u)/pulse:/run/pulse \
  --volume=$(pwd)/of:/of \
  $IMAGE_NAME:$IMAGE_TAG
