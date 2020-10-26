CFLAGS = -Wall -std=c++11
EXEC = platform
SRC = main.cpp $(wildcard ./test/*.cpp) $(wildcard ./src/*.cpp)
INCLUDES = $(wildcard ./include/*.hpp) $(wildcard ./test/*.hpp)
IFLAGS=-I. -I./include
LFLAGS=-lcppunit -ldl
OBJ = $(SRC:.cpp=.o)


$(EXEC):	$(OBJ)
	@g++ $(CFLAGS) $(IFLAGS) $(LFLAGS) -o $@ $^

#mem.o:	./src/mem.cpp
	#g++ -o $@ -c $^ $(CFLAGS)
main.o:	$(INCLUDES)

%.o:	%.cpp
	@g++ -o $@ -c $< $(CFLAGS) $(IFLAGS) $(LFLAGS)

clean	:
	@rm -f *.o ./src/*.o ./test/*.o $(EXEC)
