#Makefile for dev folder

FLAGS = -std=c++17 -g

afm :afindmod.cxx Makefile
	g++ afindmod.cxx toolbox.cxx $(FLAGS) -o ../bin/afm

combi : combi.cpp Makefile
	g++ combi.cpp $(FLAGS) -o ../bin/combi

bdev : bdev.cxx toolbox.cxx Makefile
	g++ bdev.cxx toolbox.cxx $(FLAGS) -o ../bin/bdev

adev : adev.cxx toolbox.cxx Makefile
	g++ adev.cxx toolbox.cxx $(FLAGS) -o ../bin/adev
