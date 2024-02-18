#!/bin/bash
OF_DIR=/root/openFrameworks
PROJ_GEN_BIN=$OF_DIR/apps/projectGenerator/commandLine/bin/projectGenerator

# if [ $(pwd) != $(dirname "$(realpath $0)") ]; then
#   echo "ERROR: $0 must be run from within the projects directory!"
#   exit 1
# fi

if [ $# -eq 0 ]; then
  echo "Error: No project name provided."
  exit 1
fi

project_name=$1
echo "$project_name"

if [ -d "$project_name" ]; then
  echo "Error: The project $project_name already exists."
  exit 1
fi

addons=""
for arg in "$@"
do
  case $arg in
    --opencv)
      resultString+="ofxOpenCv,"
      ;;
    --gui)
      resultString+="ofxGui,"
      ;;
    *)
      ;;
  esac
done

export PG_OF_PATH=$OF_DIR

if [ -n "$addons" ]; then
  $PROJ_GEN_BIN \
    --verbose \
    --addons "'$addons'" \
    "./$project_name"
else
  $PROJ_GEN_BIN \
    --verbose \
    "./$project_name"
fi

# Nasty but I CBA to work around it.
echo "Remember to chown -R user:user outside of the container."
