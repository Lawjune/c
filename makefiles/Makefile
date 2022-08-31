# -*- MakeFile -*-

# target: dependencies 
#    actions

# Use `cat -e -t -v Makefile` to check the tab

all: geom tip

geom: geom.o get_double.o
	gcc geom.o get_double.o -o geom -l m

geom.o: geom.c get_double.h
	gcc -c geom.c 

get_double.o: get_double.c
	gcc -c get_double.c 

tip: tip.o get_double.o
	gcc tip.o get_double.o -o tip 

tip.o: tip.c get_double.h
	gcc -c tip.c 

clean: 
	rm -f *.o tip geom