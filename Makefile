INCLUDES = -I C:/Dev/vcpkg/installed/x64-mingw-dynamic/include -I include/
CXXFLAGS = -g -std=c++14 -m64
LDFLAGS = -L C:/Dev/vcpkg/installed/x64-mingw-dynamic/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

all: main.cpp

main.cpp: ./src/*.cpp 
	ccache g++ $(CXXFLAGS) ./src/*.cpp $(INCLUDES) $(LDFLAGS) -o main
clean:
	rm main
