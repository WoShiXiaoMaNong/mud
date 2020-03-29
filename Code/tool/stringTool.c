#include "stringTool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char** split(char *str,char split,int * count)
{
	int* subStrSizeList = (int *) malloc(sizeof(int) * strlen(str));
	initSubStrSizeList(str, split,count,subStrSizeList);
	
	int subStrCount = *count;
	char ** splitResult =(char **) malloc(sizeof(char*) * subStrCount);
	initSplitResult(splitResult, subStrCount,subStrSizeList);
	
	
	char ** tempReulst = splitResult;
	char temp = *str;
	str++;
	int index = 0;
	while(temp != '\0'){
		*(*(tempReulst) + index) = temp;
		index++;
		if(temp == split){
			*(*(tempReulst) + index - 1) = '\0';
			tempReulst ++;
			index = 0;
		}
		temp = *str;
		str++;
	}
	*(*(tempReulst) + index) = '\0';
	free(subStrSizeList);
	
	return splitResult ;
}

void freeSplitResult(char ** splitResult, int count)
{
	int i = 0;
	for(i = 0 ; i < count; i++){
		free(splitResult[i]);
	}
	free(splitResult);	
}


//static
static void initSubStrSizeList(char *str,char split,int *count,int *subStrSizeList)
{
	int subStrSize = 0;
	
	char *tempptr = str;
	char temp = *tempptr;
	tempptr++;
	int subStrSizeListTemp = 0;
	
	while(temp != '\0'){
		subStrSizeListTemp ++;
		if(temp == split){
			*(subStrSizeList+subStrSize) = subStrSizeListTemp;
			subStrSize ++;
			subStrSizeListTemp = 0;
		}
		temp = *tempptr;
		tempptr++;
	}
	*(subStrSizeList+subStrSize) = subStrSizeListTemp;
	
	
		subStrSize++;
	
	
	*count = subStrSize;
	
}

static void initSplitResult(char ** splitResult,int subStrCount,int *subStrSizeList)
{
	int index = 0 ;
	for(index = 0 ; index < subStrCount; index ++){
		char * t = (char *)malloc(sizeof(char) * (*(subStrSizeList + index) + 1));
		*(splitResult + index) = t;
	}
	
}