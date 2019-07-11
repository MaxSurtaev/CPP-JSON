OUTPUT=small_test
SRC=$(addsuffix .cpp, $(OUTPUT)) 
OBJ=$(SRC:.cpp=.o)

CFLAGS= -std=c99
CPPFLAGS=$(INCLUDES) -g3 -O0 -ggdb -pipe -DDEBUG -MMD -Wall -Wextra
CXXFLAGS= -std=c++11
DEP=$(OBJ:.o=.d)
INCLUDES=-I..
LDFLAGS=-static-libstdc++ -static-libgcc -pthread -ldl -rdynamic
LDLIBS=
LINK.o= $(CXX) $(LDFLAGS) $(TARGET_ARCH)

-include $(DEP)

.PHONY: all clean debug test
.NOTPARALLEL: clean


all: $(OUTPUT) ../json.hpp

test:  $(OUTPUT) ../json.hpp
	./$(OUTPUT) -s

clean:
	-@rm -f $(OBJ) $(DEP) $(OUTPUT)
