CC = gcc-11
LIB_TAR = libephcom.a


all : $(LIB_TAR) install


OBJ = ephcom.o gnulliver.o

$(LIB_TAR) : $(OBJ)
	ar -rc $@ $^

install : 
	mv libephcom.a ..


.PHONY : clean
clean :
	rm *.o