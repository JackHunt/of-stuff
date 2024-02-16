#!/bin/bash

IMAGE_NAME="openframeworks-ubuntu"
IMAGE_TAG="0.12.0"

PROJECTS_DIR="$(dirname "$0")/projects"

if [[ "$(docker images -q $IMAGE_NAME:$IMAGE_TAG 2> /dev/null)" == "" ]]; then
  echo "Image does not exist, building..."
  docker build -t $IMAGE_NAME:$IMAGE_TAG .
fi

docker run -it --rm -v "$PROJECTS_DIR:/projects" $IMAGE_NAME:$IMAGE_TAG
