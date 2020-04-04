
#include "logger.h"
#include "map.h"


int main(void)
{
	char * filePath = "../design/testMap.txt";
	struct world* mud = (struct world*)malloc(sizeof(struct world*));
	//while(1){
	initWorld(mud,filePath);
	//}
	return 0;
}
