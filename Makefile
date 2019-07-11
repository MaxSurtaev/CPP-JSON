OUTPUT=example
SRC=$(addsuffix .cpp, $(OUTPUT)) 
OBJ=$(SRC:.cpp=.o)

CFLAGS= -std=c99
CPPFLAGS=$(INCLUDES) -g3 -O0 -ggdb -pipe -DDEBUG -MMD -Wall -Wextra
CXXFLAGS= -std=c++11
DEP=$(OBJ:.o=.d)
INCLUDES=-I
LDFLAGS=-static-libstdc++ -static-libgcc -pthread -ldl -rdynamic
LDLIBS=
LINK.o= $(CXX) $(LDFLAGS) $(TARGET_ARCH)

-include $(DEP)

.PHONY: all clean
.NOTPARALLEL: clean

all: $(OUTPUT) json.hpp
	@$(MAKE) -C test $@
	./$(OUTPUT)

clean:
	-@rm -f $(OBJ) $(DEP) $(OUTPUT)
	@$(MAKE) -C test $@
