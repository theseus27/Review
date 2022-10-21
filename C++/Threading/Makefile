CXX = g++
CXXFLAGS = -Wall -Wextra -pthread

default: threading

threading: threading.cpp clean
	$(CXX) $(CXXFLAGS) threading.cpp -o threading

run: threading clean
	./threading
clean:
	rm -rf *.o *.dSYM