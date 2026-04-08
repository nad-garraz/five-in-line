CXX := g++
OUTPUT := five-in-line

# compiler and linker flags
CXX_FLAGS := -O3 -std=c++23 -Wno-unused-result -Wunused-variable -pedantic -Wall -Wno-strict-aliasing

SRC_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(SRC_FILES:.cpp=.o)

all:$(OUTPUT)

$(OUTPUT):$(OBJ_FILES) Makefile
	@[ -d bin ] || mkdir ./bin/
	$(CXX) $(OBJ_FILES) -o ./bin/$@

.cpp.o:
	$(CXX) -c $(CXX_FLAGS) $< -o $@

clean:
	rm -f $(OBJ_FILES) ./bin/${OUTPUT}

run: $(OUTPUT)
	cd bin && ./${OUTPUT} && cd ..
