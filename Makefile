build_osx:
	g++ *.cpp -lraylib -framework OpenGL -framework OpenAL -framework Cocoa -framework IOKit -std=c++11 -o game