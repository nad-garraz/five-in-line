CXX := g++
OUTPUT := five-in-line


# if you need to manually specify your SFML install dir, do so here
# SFML_DIR := .
# IMGUI-SFML_DIR := src/imgui-SFML
# IMGUI_DIR := $(IMGUI-SFML_DIR)/imgui
# BACKENDS_DIR := $(IMGUI_DIR)/backends

# compiler and linker flags
CXX_FLAGS := -O3 -std=c++20 -Wno-unused-result -Wunused-variable -pedantic -Wall -Wno-strict-aliasing
# INCLUDES := -I./src -I./$(IMGUI-SFML_DIR) -I./$(IMGUI_DIR) -I./$(BACKENDS_DIR)
# LDFLAGS := -O3 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lGL

# the source files for the ecs game engine
# SRC_FILES := $(wildcard src/*.cpp $(IMGUI-SFML_DIR)/*.cpp $(IMGUI_DIR)/*.cpp $(BACKENDS_DIR)/*.cpp)
SRC_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(SRC_FILES:.cpp=.o)

#all of these targets will be made if you just type make
all:$(OUTPUT)

#define the main executable requirements /command
$(OUTPUT):$(OBJ_FILES) Makefile
	# $(CXX) $(OBJ_FILES) $(LDFLAGS) -o ./bin/$@
	$(CXX) $(OBJ_FILES) -o ./bin/$@

# specifies how the object files are compiled from cpp files
.cpp.o:
	$(CXX) -c $(CXX_FLAGS) $< -o $@

#typing 'make clean' will remove all intermediate build files
clean:
	rm -f $(OBJ_FILES) ./bin/${OUTPUT}

# typing 'make run' will complie an drun the program
run: $(OUTPUT)
	cd bin && ./${OUTPUT} && cd ..
