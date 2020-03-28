INCPATH  = ./header
TOOLPATH = ./tool
GCC = gcc
MAKE = make
DEL      = del

default :
	$(MAKE) mud

logger.o: $(TOOLPATH)/logger.c $(INCPATH)/logger.h Makefile
	$(GCC) -c $(TOOLPATH)/logger.c -I $(INCPATH) -o logger.o

stringTool.o : $(TOOLPATH)/stringTool.c $(INCPATH)/stringTool.h Makefile
	$(GCC) -c $(TOOLPATH)/stringTool.c -I $(INCPATH) -o stringTool.o

mud.o: mud.c logger.o Makefile
	$(GCC) -c mud.c -I $(INCPATH) -o mud.o	

mud : mud.o logger.o stringTool.o
	$(GCC) -o mud mud.o logger.o stringTool.o




clean:
	-$(DEL) *.o