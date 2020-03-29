#include "stringTool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int stringToInt(char *number)
{
	int result = 0;
	int size = strlen(number);
	int index = 0;
	for(index = 0 ; index < size; index ++){
		char temp = *(number + index);
		char tempNum = temp - '0';
		result += tempNum * round(pow(10,size - index - 1));
	}
	
	
	return result;
}
char** split(char *str,char split,int * count)
{
	int* subStrSizeList = (int *) malloc(sizeof(int) * strlen(str));
	initSubStrSizeList(str, split,count,subStrSizeList);
	
	int subStrCount = *count;
	char ** splitResult =(char **) malloc(sizeof(char*) * subStrCount);
	memset(splitResult,sizeof(char*) * subStrCount,0);
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
		int subStrSize = *(subStrSizeList + index) + 1;
		char * t = (char *)malloc(sizeof(char) * subStrSize);
		memset(t,sizeof(char) * subStrSize,0);
		*(splitResult + index) = t;
	}
	
}