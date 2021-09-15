output: main.o passent.o drivent.o rident.o passcol.o drivcol.o ridcol.o econ.o basic.o group.o lux.o
	g++ -o output main.o passent.o drivent.o rident.o passcol.o drivcol.o ridcol.o econ.o basic.o group.o lux.o
main.o: main.cpp passent.h drivent.h rident.h passcol.h drivcol.h ridcol.h
	g++ -c main.cpp
passent.o: passent.cpp passent.h
	g++ -c passent.cpp
drivent.o: drivent.cpp drivent.h
	g++ -c drivent.cpp
rident.o: rident.cpp rident.h
	g++ -c rident.cpp
passcol.o: passcol.cpp passcol.h drivcol.h ridcol.h
	g++ -c passcol.cpp
drivcol.o: drivcol.cpp drivcol.h passcol.h ridcol.h
	g++ -c drivcol.cpp
ridcol.o: ridcol.cpp ridcol.h passcol.h drivcol.h ridcol.h
	g++ -c ridcol.cpp
econ.o: drivent.h econ.h
	g++ -c econ.cpp
basic.o: drivent.h basic.h
	g++ -c basic.cpp
group.o: drivent.h group.h
	g++ -c group.cpp
lux.o: drivent.h lux.h
	g++ -c lux.cpp
