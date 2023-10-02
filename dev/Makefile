#Makefile for dev folder

FLAGS = -std=c++17 -g

ms : mod_search.cxx toolbox.o
	g++ mod_search.cxx toolbox.o $(FLAGS) -o ../bin/ms

derive : derive.cxx toolbox.o
	g++ derive.cxx toolbox.o $(FLAGS) -o ../bin/derive

afm : afindmod.cxx Makefile
	g++ afindmod.cxx toolbox.cxx $(FLAGS) -o ../bin/afm

combi : combi.cpp Makefile
	g++ combi.cpp $(FLAGS) -o ../bin/combi

bdev : bdev.cxx toolbox.cxx Makefile
	g++ bdev.cxx toolbox.cxx $(FLAGS) -o ../bin/bdev

adev : adev.cxx toolbox.cxx Makefile
	g++ adev.cxx toolbox.cxx $(FLAGS) -o ../bin/adev
	
toolbox.o : toolbox.cxx ../inc/toolbox.hxx
	g++ -c toolbox.cxx -o toolbox.o 
