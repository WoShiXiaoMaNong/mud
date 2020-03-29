INCPATH  = ./header
TOOLPATH = ./tool
GCC = gcc -g
MAKE = make
DEL      = del

default :
	$(MAKE) mud

logger.o: $(TOOLPATH)/logger.c $(INCPATH)/logger.h Makefile
	$(GCC) -c $(TOOLPATH)/logger.c -I $(INCPATH) -o logger.o

stringTool.o : $(TOOLPATH)/stringTool.c $(INCPATH)/stringTool.h Makefile
	$(GCC) -c $(TOOLPATH)/stringTool.c -I $(INCPATH) -o stringTool.o
	
map.o : map.c $(INCPATH)/map.h Makefile
	$(GCC) -c map.c -I $(INCPATH) -o map.o	

mud.o: mud.c Makefile
	$(GCC) -c mud.c -I $(INCPATH) -o mud.o	

mud : mud.o logger.o stringTool.o map.o
	$(GCC) -o mud mud.o logger.o stringTool.o map.o




clean:
	-$(DEL) *.o
	-$(DEL) mud.exe