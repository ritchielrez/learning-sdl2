INCLUDES = -I C:/Dev/vcpkg/installed/x64-mingw-dynamic/include -I include/
CXXFLAGS = -g -Wall -std=c++14 -m64
LDFLAGS = -L C:/Dev/vcpkg/installed/x64-mingw-dynamic/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
SRC=$(wildcard ./src/*.cpp)

all: debug

debug: $(SRC)
	g++ $(CXXFLAGS) $(SRC) $(INCLUDES) $(LDFLAGS) -o main
clean:
	rm main
