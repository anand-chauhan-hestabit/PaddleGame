
CC = x86_64-w64-mingw32-g++
CFLAGS = -Wall
LDFLAGS = -L/home/hestabit/Desktop/PaddleGame/Library/SFML/lib
# LIBS = -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-main -lopengl32 -lfreetype -lwinmm -lgdi32 -static-libgcc -static-libstdc++
LIBS =-lsfml-network-s -lws2_32 -lsfml-graphics-s -lsfml-window-s  -lsfml-system-s -lsfml-main -lopengl32 -lfreetype -lwinmm -lgdi32 -static-libgcc -static-libstdc++

# List of source files
SOURCES = main.cpp MainMenu.cpp 

# Generate corresponding object file names
OBJECTS = $(SOURCES:.cpp=.o)

main.exe: $(OBJECTS)
	$(CC) $(CFLAGS) -o mainmenu.exe $(OBJECTS) $(LDFLAGS) $(LIBS)

# Rule to compile each source file
%.o: %.cpp
	$(CC) $(CFLAGS) -I/home/hestabit/Desktop/PaddleGame/Library/SFML/include -c $< -o $@ -DSFML_STATIC

clean:
	rm -f $(OBJECTS) mainmenu.exe