#!/bin/sh

for x in c sc uc s i l us u ul f d ld
do
    echo "			case $x:"
    for i in c sc uc s i l us u ul f d ld
    do
	    echo "				else if (dat->type == $i)"
	    echo "					dat->t.$x = ($x) dat->t.$i;"
    done
    echo "				break;"
done
