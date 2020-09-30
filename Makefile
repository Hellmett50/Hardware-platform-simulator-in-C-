CFLAGS = -Wall -std=c++11
EXEC = platform
SRC = main.cpp $(wildcard ./src/*.cpp)
INCLUDES = $(wildcard ./include/*.hpp)
OBJ = $(SRC:.cpp=.o)


$(EXEC):	$(OBJ)
	@g++ -o $@ $^

#mem.o:	./src/mem.cpp
	#g++ -o $@ -c $^ $(CFLAGS)
main.o:	$(INCLUDES)

#main.o:	main.cpp $(INCLUDES)
%.o:	%.cpp
	@g++ -o $@ -c $< $(CFLAGS)

clean	:
	@rm -f *.o ./src/*.o $(EXEC)
