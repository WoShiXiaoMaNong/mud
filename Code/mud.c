#include <stdio.h>
#include <pthread.h>
#include <windows.h>
#include "logger.h"
#include "stringTool.h"


int main(void)
{
	char * mapConfig = "1,n:3,s:5,w:2,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4,e:4";
	
	int count = 0;
	char ** r = split(mapConfig,',',&count);
	int i = 0;
	printf("String %s, count :%d\r\n",mapConfig,count);
	for(i = 0 ; i < count; i++){
		printf("i %d",i);
		loginfo(r[i]);
		free(r[i]);
	}
	free(r);
	
	system("pause"); 
	return 1;
	
}
