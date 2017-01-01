#!/bin/bash
#Name: Wei Zhe (Richard) Ni
#Student ID: 260674646


if [ -f "result.jpg" ]
then
	rm "result.jpg"
fi

number_of_images="$1"
images=$(find *.jpg)



while [ 1 ]
do
	while [ $number_of_images -gt 0 ]
	do
		this_image=`echo $images | cut -d' ' -f1`
		eog -n $this_image &
		images="`echo $images | cut -d' ' -f2-` ${this_image}"
		number_of_images=$[number_of_images-1]

		
	
	done
	
	processes=`ps | grep eog| wc -l`
	if [ $processes -ne "$1" ]
	then
		this_image=`echo $images | cut -d' ' -f1`
		eog -n $this_image &
		images="`echo $images | cut -d' ' -f2-` ${this_image}"
	fi
	
done
