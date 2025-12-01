CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = lab13
SRC = lab13.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
