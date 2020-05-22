CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++17

__start__: dron
	./dron

dron: obj/main.o obj/wek.o obj/macierz.o obj/Dr3D_gnuplot_api.o\
	 obj/prost.o obj/gran.o obj/dron.o
	 g++ -Wall -pedantic -o dron obj/main.o obj/wek.o obj/macierz.o\
	  obj/Dr3D_gnuplot_api.o obj/prost.o obj/gran.o obj/dron.o -lpthread

obj/main.o: src/main.cpp inc/macierz.hh inc/prost.hh\
	 inc/Dr3D_gnuplot_api.hh inc/dron.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/wek.o: src/wekC.cpp inc/wek.hh
	g++ ${CPPFLAGS} -o obj/wek.o src/wekC.cpp

obj/macierz.o: src/macierzC.cpp inc/macierz.hh
	g++ ${CPPFLAGS} -o obj/macierz.o src/macierzC.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

obj/prost.o: inc/prost.hh src/prost.cpp inc/bryla.hh
	g++ ${CPPFLAGS} -o obj/prost.o src/prost.cpp

obj/gran.o: inc/gran.hh src/gran.cpp inc/bryla.hh
	g++ ${CPPFLAGS} -o obj/gran.o src/gran.cpp

obj/dron.o: inc/dron.hh src/dron.cpp inc/prost.hh inc/gran.hh
	g++ ${CPPFLAGS} -o obj/dron.o src/dron.cpp

clear:
	rm -f obj/*.o dron
