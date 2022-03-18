# ===================================================================
# Makefile for PlaymobilCGI
# ===================================================================
BUILD_FLAGS= -Wall
LINK_FLAGS= -lm -lGL -lGLU -lglut

Executable=PlaymobilCGI
Sources= $(wildcard src/*.c)
Object= $(patsubst src/%.c,obj/%.o,$(Sources))

all: setup_directories build/$(Executable)

setup_directories:
	mkdir -p obj build

# rules	
build/$(Executable): $(Object)
	gcc -o $@ $(Object) $(LINK_FLAGS)
	
obj/%.o: src/%.c
	gcc -c -o $@ $< $(BUILD_FLAGS)

# clean
clean:
	rm -rf build obj