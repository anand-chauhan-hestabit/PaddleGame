CC = x86_64-w64-mingw32-g++
CFLAGS = -Wall
LDFLAGS = -L/home/hestabit/Desktop/PaddleGame/Library/SFML/lib
LIBS = \
    -lsfml-network-s \
    -lws2_32 \
    -lsfml-graphics-s \
    -lsfml-window-s \
    -lsfml-audio-s \
    -lsfml-system-s \
    -lsfml-main \
    -lopengl32 \
    -lfreetype \
    -lwinmm \
    -lgdi32 \
    -static-libgcc \
    -static-libstdc++ \
    -lopenal32 \
    -lFLAC \
    -lvorbisenc \
    -lvorbisfile \
    -lvorbis \
    -logg

# List of source files
SOURCES = \
    MainMenu.cpp \
    sourceFiles/SoundManager/soundManager.cpp \
    sourceFiles/online.cpp \
    sourceFiles/offline.cpp \
    sourceFiles/UserInterface/UserInterFace.cpp \
    sourceFiles/Ball/ball.cpp \
    sourceFiles/Player/player.cpp \
    sourceFiles/Player/paddle.cpp \
    sourceFiles/InputSystem/inputSystem.cpp \
    sourceFiles/NetworkManager/client.cpp \
    sourceFiles/NetworkManager/server.cpp \
    sourceFiles/NetworkManager/rpc.cpp \
    sourceFiles/about.cpp

# Generate corresponding object file names
OBJECTS = $(SOURCES:.cpp=.o)

main.exe: $(OBJECTS)
	$(CC) $(CFLAGS) -o NewPongGame.exe $(OBJECTS) $(LDFLAGS) $(LIBS)

# Rule to compile each source file
%.o: %.cpp
	$(CC) $(CFLAGS) -I/home/hestabit/Desktop/PaddleGame/Library/SFML/include -c $< -o $@ -DSFML_STATIC

clean:
	rm -f $(OBJECTS) NewPongGame.exe

run:
	wine NewPongGame.exe
