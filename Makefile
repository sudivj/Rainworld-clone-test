CXX = g++
CXXFLAGS = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_gfx -lm

SOURCESFOLDER = src

SOURCES = main.cpp $(wildcard $(SOURCESFOLDER)/*.cpp) $(wildcard $(SOURCESFOLDER)/**/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = GAME

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)