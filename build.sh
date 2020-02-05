#!/bin/bash

OldPath=$(pwd)
ScriptFile=$(readlink -f $0)
ScriptPath=$(dirname $ScriptFile)
Build=$ScriptPath'/build'
ACTResult=$ScriptPath'/LibRayMarching_component'

case $1 in
act)
	cd $ScriptPath
	rm -rf $ACTResult/
	act libraymarching.act.xml
	rm interface/*
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
	rm -rf $ACTResult/
	act libraymarching.act.xml
	
	Package=$Build'/package'
	Artifact=$Build'/libraymarching.zip'
	Bin=$Package'/bin'
	BinWin=$Bin'/win'
	BinLinux=$Bin'/linux'
	Bindings=$Package'/bindings'
	Lib=$Package'/lib/win'
  
	rm -rf $Package
	mkdir -p $Package
	mkdir -p $Bin
	mkdir -p $BinWin
	mkdir -p $BinLinux
	mkdir -p $Bindings
	mkdir -p $Lib

	cp $Build'/libraymarching.so' $BinLinux
	cp -r $ACTResult/Bindings/* $Bindings

	cd $Package
	zip -r $Artifact .
;;
*)
  echo "Useage: build (act|compile|package)"
esac

cd $OldPath
