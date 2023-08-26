
# this code is building and statically compiled run for windows

# CC = x86_64-w64-mingw32-g++
# CFLAGS = -Wall
# LDFLAGS = -L/home/hestabit/Desktop/PaddleGame/Library/SFML/lib
# # LIBS = -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main -static-libgcc -static-libstdc++
# LIBS =-lsfml-network-s -lws2_32 -lsfml-graphics-s -lsfml-window-s  -lsfml-system-s -lsfml-main -lopengl32 -lfreetype -lwinmm -lgdi32 -static-libgcc -static-libstdc++

# # List of source files
# SOURCES = scoketMain.cpp sourceFiles/client.cpp sourceFiles/server.cpp

# # Generate corresponding object file names
# OBJECTS = $(SOURCES:.cpp=.o)

# main.exe: $(OBJECTS)
# 	$(CC) $(CFLAGS) -o socketmain.exe $(OBJECTS) $(LDFLAGS) $(LIBS)

# # Rule to compile each source file
# %.o: %.cpp
# 	$(CC) $(CFLAGS) -I/home/hestabit/Desktop/PaddleGame/Library/SFML/include -c $< -o $@ -DSFML_STATIC

# clean:
# 	rm -f $(OBJECTS) socketmain.exe 




CC = x86_64-w64-mingw32-g++
CFLAGS = -Wall
LDFLAGS = -L/home/hestabit/Desktop/PaddleGame/Library/SFML/lib
# LIBS = -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-main -lopengl32 -lfreetype -lwinmm -lgdi32 -static-libgcc -static-libstdc++
LIBS =-lsfml-network-s -lws2_32 -lsfml-graphics-s -lsfml-window-s  -lsfml-system-s -lsfml-main -lopengl32 -lfreetype -lwinmm -lgdi32 -static-libgcc -static-libstdc++

# List of source files
SOURCES = MainMenu.cpp sourceFiles/online.cpp sourceFiles/offline.cpp sourceFiles/UserInterFace.cpp  sourceFiles/ball.cpp sourceFiles/player.cpp sourceFiles/paddle.cpp sourceFiles/inputSystem.cpp sourceFiles/client.cpp sourceFiles/server.cpp sourceFiles/rpc.cpp

# Generate corresponding object file names
OBJECTS = $(SOURCES:.cpp=.o)

main.exe: $(OBJECTS)
	$(CC) $(CFLAGS) -o NewPongGame.exe $(OBJECTS) $(LDFLAGS) $(LIBS)

# Rule to compile each source file
%.o: %.cpp
	$(CC) $(CFLAGS) -I/home/hestabit/Desktop/PaddleGame/Library/SFML/include -c $< -o $@ -DSFML_STATIC

clean:
	rm -f $(OBJECTS) NewPongGame.exe
