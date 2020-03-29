
#include <windows.h>
#include "logger.h"
#include "map.h"


int main(void)
{
	char * filePath = "C:\\Users\\Administrator\\Desktop\\Mud\\design\\testMap.txt";
	struct world* mud = (struct world*)malloc(sizeof(struct world*));
	//while(1){
	initWorld(mud,filePath);
	//}
	system("pause"); 
	return 1;
	
}
