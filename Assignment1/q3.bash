#!/bin/bash
#Name: Wei Zhe (Richard) Ni
#Student ID: 260674646

if [ -f "result.jpg" ]
then
	rm "result.jpg"
fi

if [ "$1" = "alpha" ]
then
	animals=`find *.jpg | sort`
	convert $animals -append result.jpg
	for x in $animals
	do
		echo `echo $x | cut -d'.' -f1`
	done
	eog result.jpg
fi

if [ "$1" = "weight" ]
then
	files=`find *.dat`
	weight=$(for file in $files
	do
		data="`cat $file | cut -d'k' -f1`"';'${file}
		echo $data
	done | sort -n )
	animal=$(for i in $weight
	do
		name=`echo ${i} | cut -d';' -f2 | cut -d'.' -f1`
		namepic=$name".jpg"
		echo $namepic
		
	done) 
	convert $animal -append result.jpg
	for x in $animal
	do
		echo `echo $x | cut -d'.' -f1`
	done
	eog result.jpg
fi

if [ "$1" = "length" ]
then
	files=`find *.dat`
	length=$(for file in $files
	do
		data="`cat $file | cut -d' ' -f2 | tr 'm' ';'`"${file}
		echo $data
	done | sort -n)
	animal=$(for i in $length
	do
		name=`echo ${i} | cut -d';' -f2 | cut -d'.' -f1`
		namepic=$name".jpg"
		echo $namepic
		
	done) 
	convert $animal -append result.jpg
	for x in $animal
	do
		echo `echo $x | cut -d'.' -f1`
	done
	eog result.jpg
fi







