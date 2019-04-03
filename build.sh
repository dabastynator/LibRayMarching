#!/bin/bash

OldPath=$(pwd)
ScriptFile=$(readlink -f $0)
ScriptPath=$(dirname $ScriptFile)
Build=$ScriptPath'/build'
ACTResult=$ScriptPath'/LibRayMarching_component'

case $1 in
act)
	cd $ScriptPath
	act libraymarching.act.xml
	cp $ACTResult/Implementations/Cpp/Interfaces/libraymarching* interface/
	cp $ACTResult/Bindings/Python/LibRayMarching.py example/
;;
compile)
	mkdir -p $Build
	cd $Build
	cmake ..
	make
;;
package)
  echo "push button"
  gpio -g write $light 1
  gpio -g write $off 1
  sleep 1
  echo "release button"
  gpio -g write $light 0
  gpio -g write $off 0
;;
*)
  echo "Useage: build (act|compile|package)"
esac

cd $OldPath
