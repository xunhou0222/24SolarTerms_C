LIB = -L../lib -lsofa_c_20210512 -lephcom
EXE_PATH = ../bin
CC = gcc-11    # Modify this to your own C compiler
EXE_TAR = SolarTerms


OBJ = jd2cst.o main.o sun2earth.o TermsCheck.o split.o

$(EXE_PATH)/$(EXE_TAR) : $(OBJ)
	@-mkdir -p $(EXE_PATH)
	$(CC) -o $@ $^ $(LIB)


.PHONY : clean cleanall
clean :
	rm *.o
cleanall :
	-rm -rf $(EXE_PATH) *.o