#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "logger.h"

void loginfo(char *info)
{
	myLog("Info",info);
}

void logerror(char *info)
{
	myLog("Error",info);
}


static void myLog(char *infoType,char *info)
{
	time_t now ;
    struct tm *tm_now ;
	time(&now) ;
	tm_now = localtime(&now) ;
	printf("[%d-%02d-%02d %02d:%02d:%02d] %s : %s\r\n",
	tm_now->tm_year+1900, tm_now->tm_mon+1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec
	,infoType
	,info) ;
	
}

