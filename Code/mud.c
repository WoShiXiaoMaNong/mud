#include <stdio.h>
#include <pthread.h>
#include <windows.h>
#include "logger.h"
#include "stringTool.h"
#include "map.h"

void test()
{
	char * mapConfig = "1,2,3,4,12313123";
	
	int count = 0;
	char ** r = split(mapConfig,',',&count);
	int i = 0;
	printf("String %s| count :%d\r\n",mapConfig,count);
	for(i = 0 ; i < count; i++){
		loginfo(r[i]);
	}
	freeSplitResult(r,count);
	
}

int main(void)
{
	char * filePath = "C:\\Users\\Administrator\\Desktop\\Mud\\design\\testMap.txt";
	struct world* mud = (struct world*)malloc(sizeof(struct world*));
	initWorld(mud,filePath);
	system("pause"); 
	return 1;
	
}
