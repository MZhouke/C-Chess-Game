CXX = g++-5
CXXFLAGS = -g -std=c++14 -Wall -MMD -Werror=vla 
#CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = chess
OBJECTS = main.o cell.o grid.o human.o textDisplay.o aiOne.o aiTwo.o subject.o player.o graphicsDisplay.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
