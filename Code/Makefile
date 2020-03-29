INCPATH  = ./header
GCC = gcc -g
MAKE = ./tool/make
DEL      = del

default :
	$(MAKE) mud

logger.o: logger.c $(INCPATH)/logger.h Makefile
	$(GCC) -c logger.c -I $(INCPATH) -o logger.o

stringTool.o : stringTool.c $(INCPATH)/stringTool.h Makefile
	$(GCC) -c stringTool.c -I $(INCPATH) -o stringTool.o
	
map.o : map.c $(INCPATH)/map.h Makefile
	$(GCC) -c map.c -I $(INCPATH) -o map.o	

mud.o: mud.c Makefile
	$(GCC) -c mud.c -I $(INCPATH) -o mud.o	

mud : mud.o logger.o stringTool.o map.o
	$(GCC) -o mud mud.o logger.o stringTool.o map.o




clean:
	-$(DEL) *.o
	-$(DEL) mud.exe