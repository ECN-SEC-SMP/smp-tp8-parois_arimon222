CXX      = g++
CXXFLAGS = -Wall -std=c++11 -Isrc

TARGET = jeu
SRCS   = main.cpp src/Attaque.cpp src/Animal.cpp src/Animaux.cpp
OBJS   = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean