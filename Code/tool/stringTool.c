#include "stringTool.h"
#include <stdio.h>
#include <stdlib.h>

char** split(char *str,char split,int * count)
{
	int splitSize = 0;
	int* tokenSize = (int *) malloc(sizeof(int) * strlen(str));
	char *tempptr = str;
	char temp = *tempptr;
	tempptr++;
	int tokenSizeTemp = 0;
	
	while(temp != '\0'){
		tokenSizeTemp ++;
		if(temp == split){
			
			*(tokenSize+splitSize) = tokenSizeTemp;
			splitSize ++;
			tokenSizeTemp = 0;
		}
		temp = *tempptr;
		tempptr++;
	}
	*(tokenSize+splitSize) = tokenSizeTemp;
	
	splitSize++;
	*count = splitSize;
	char ** splitResult =(char **) malloc(sizeof(char*) * splitSize);
	
	
	int index = 0 ;
	for(index = 0 ; index < splitSize; index ++){
		char * t = (char *)malloc(sizeof(char) * (*(tokenSize + index) + 1));
		if (t == NULL){
			printf("error \r\n");
		}else{
			printf("succeed \r\n");
		}
		*(splitResult + index) = t;
	}
	
	char ** tempReulst = splitResult;
	temp = *str;
	str++;
	index = 0;
	while(temp != '\0'){
		*(*(tempReulst) + index) = temp;
		index++;
		if(temp == split){
			*(*(tempReulst) + index) = '\0';
			tempReulst ++;
			index = 0;
		}
		temp = *str;
		str++;
	}
	
	free(tokenSize);
	
	return splitResult ;
}
