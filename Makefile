CXX = clang++
CXXFLAGS = -std=c++20
TARGET = program
LIBRARY = libmylib.dylib

all: $(TARGET)

$(TARGET): main.cpp $(LIBRARY)
	$(CXX) $(CXXFLAGS) main.cpp -L. -lmylib -o $(TARGET)

$(LIBRARY): mylib.cpp mylib.h
	$(CXX) $(CXXFLAGS) -dynamiclib mylib.cpp -o $(LIBRARY)

clean:
	rm -f $(TARGET) $(LIBRARY)