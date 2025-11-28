TARGET = hdrcr
SRCS = main.cpp creator.cpp errors.cpp
CXX = g++
CXXFLAGS = -c -Wall

all: $(TARGET)

$(TARGET): $(SRCS:.cpp=.o)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o $(TARGET)
