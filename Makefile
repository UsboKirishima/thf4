.SILENT: #don't echo commands as we run them.
SRC := $(foreach x, ./src, $(wildcard $(addprefix $(x)/*,.c*)))
LIB := $(foreach x, ./lib, $(wildcard $(addprefix $(x)/*,.c*)))
DIRS := $(foreach x, ./src/**, $(wildcard $(addprefix $(x)/*,.c*)))
INCLUDES:=$(shell pkg-config --cflags gtk4 )
LIBS=$(shell pkg-config --libs gtk4  )

out.o: 
	gcc ${SRC} -I include ${INCLUDES} ${DIRS} -o build/thf4 -pthread -lcurl ${LIBS} 2> /dev/null && ./build/thf4 

test: 
	gcc ${SRC} -I include ${INCLUDES} ${DIRS} -o build/thf4 -pthread -lcurl ${LIBS} && ./build/thf4
