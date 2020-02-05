#!/bin/bash

OldPath=$(pwd)
ScriptFile=$(readlink -f $0)
ScriptPath=$(dirname $ScriptFile)
Build=$ScriptPath'/build'
ACTResult=$ScriptPath'/LibRayMarching_component'

function failed {
	echo "$1" 1>&2
	exit 1;
}

function win_compile {
	mkdir -p $Build || failed "Error making build directory"
	cd $Build

	cmake -G "Visual Studio 14 2015 Win64" .. || failed "Error during cmake"
	cmake --build . --config Release || failed "Error during compiling"
}

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
	if [[ "$OSTYPE" == "linux-gnu" ]]; then
		mkdir -p $Build || failed "Error making build directory"
		cd $Build
		cmake .. || failed "Error during cmake"
		make || failed "Error during make"
	elif [[ "$OSTYPE" == "darwin"* ]]; then
		mkdir -p $Build || failed "Error making build directory"
		cd $Build
		cmake .. || failed "Error during cmake"
		make || failed "Error during make"
	elif [[ "$OSTYPE" == "cygwin" ]]; then
		win_compile
	elif [[ "$OSTYPE" == "msys" ]]; then
		win_compile
	elif [[ "$OSTYPE" == "win32" ]]; then
		win_compile
	else
		echo "Unknown system: "$OSTYPE
		exit 1
	fi
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
