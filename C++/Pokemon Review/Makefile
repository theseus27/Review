CXX = g++
CXXFLAGS = -g3 -Wall -Wextra
LDFLAGS = -g3

# Build main executable
Game: main.o game.o trainer.o pokemon.o
	$(CXX) main.o game.o trainer.o pokemon.o -o Game

#Build main.o
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

#Build game class
game.o: game.cpp game.h
	$(CXX) $(CXXFLAGS) -c game.cpp -o game.o

# Build pokemon class
pokemon.o: pokemon.cpp pokemon.h
	$(CXX) $(CXXFLAGS) -c pokemon.cpp -o pokemon.o

# Build trainer class
trainer.o: trainer.cpp trainer.h
	$(CXX) $(CXXFLAGS) -c trainer.cpp -o trainer.o

# Clean
clean:
	rm *.o