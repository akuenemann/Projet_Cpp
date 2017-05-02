CC=g++

CFLAGS=-O3 -march=native -mtune=native -std=c++11

LDFLAGS=

EXEC=main

SRC=./src/main.cpp \
./src/Format/CBitmap.cpp \
./src/Image/CImage.cpp \
./src/Image/CLigne.cpp \
./src/Image/CPixel.cpp \
./src/Formes/ligne.cpp \
./src/Formes/carre.cpp \
./src/Formes/rectangle.cpp \
./src/Formes/triangle.cpp \
./src/Formes/arc.cpp \
./src/Formes/cercle.cpp \
./src/Formes/point.cpp \
./src/Traitement/traitement.cpp \
./src/Formes/forme.cpp


OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

main: $(OBJ)
	$(CC) $(CFLAGS) -o ./$@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean mrproper

clean:
	find ./ -name main -exec rm {} \;
	find ./src -name *.o  -exec rm {} \;

mrproper: clean
	rm $(EXEC)
