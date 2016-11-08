CPP		=	clang -g  -std=c++14 -fexceptions -fpermissive
NAME		=	series7copu
R2_PLUGIN_PATH	=	$(shell r2 -hh|grep LIBR_PLUGINS|awk '{print $$2}')
CFLAGS		=	-g -fPIC $(shell pkg-config --cflags r_asm)
LDFLAGS		=	-shared $(shell pkg-config --libs r_asm)
OBJS		=	$(NAME).o series7copudecoder.o
CSRC		= 	$(NAME).c
CPPSRC		= 	*.cpp
SO_EXT		=	$(shell uname|grep -q Darwin && echo dylib || echo so)
LIB		=	$(NAME).$(SO_EXT)

all:	$(LIB)

clean:
	rm -f $(LIB) $(OBJS)

$(LIB):	$(OBJS) series7copudecoder.o
	g++ -g  $(CFLAGS) $(LDFLAGS) -lstdc++  $(OBJS) -o $(LIB)
series7copudecoder.o: series7copudecoder.cpp	
	g++ -g -std=c++14 -fpermissive -fPIC -I/usr/include/libr -lstdc++ -c $< -o $@

install:
	cp -f $(NAME).$(SO_EXT) $(R2_PLUGIN_PATH)

uninstall:
	rm -f $(R2_PLUGIN_PATH)/$(NAME).$(SO_EXT)

