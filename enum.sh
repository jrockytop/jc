#!/bin/sh

#for x in i l u ul f d ld
for x in i l u ul
do
    echo "	case $x:"
#    for i in c sc uc s i l us u ul f d ld
    for i in c sc uc s i l us u ul
    do
#	for j in c sc uc s i l us u ul f d ld
	for j in c sc uc s i l us u ul
	do
	    echo "		else if (a->type == $i && b->type == $j)"
	    echo "			res->t.$x = a->t.$i << b->t.$j;"
	done
    done
    echo "		break;"
done
