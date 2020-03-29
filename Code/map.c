 #include "map.h"
 #include "logger.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 void initWorld(struct world* mud,char *mapConfig)
 {
	loginfo("im initworld, map config path is ");
	loginfo(mapConfig);
	
	struct mapNodeMataData* head = createEmptyMataData();
	if(head == NULL){
		logerror("Alloc memory for map node mata data head failed!");
		return;
	}

	loginfo("Alloc memory for map node mata data head succeed!");
	
	initMapNodeMataData(head, mapConfig);
	
	
	
	freeMapNodeMataData(head);
 }
 
 
 
 static void initMapNodeMataData(struct mapNodeMataData* head, char *mapConfig)
 {
	struct mapNodeMataData* tempMataData = head;
	struct mapNodeMataData* previous = head;
	tempMataData->next = NULL;
	
	FILE *fp;
	fp = fopen(mapConfig, "r");
	if(fp == NULL){
		logerror("Open map config error!");
		return;
	}
	loginfo("Open map config succeed.");
	int index = 0;
	char temp = fgetc(fp);
	char line[1024];
	
	while(temp != '\0' && temp != EOF){
		if(temp == '\n'){
			temp = '\0';
			line[index] = temp;
			buildNodeMataData(tempMataData,line);
			index = 0;
			tempMataData->next = createEmptyMataData();
			tempMataData->next->id = 0;
			previous = tempMataData;
			tempMataData = tempMataData->next;
		}else{
			line[index] = temp;
			index++;
		}
		temp = fgetc(fp);
	}
	fclose(fp);
	free(previous->next);
	previous->next = NULL;
	 
 }
 
 static void buildNodeMataData(struct mapNodeMataData* mataData, char * mataStr)
 {
	int count = 0;
	char ** splitResult = split(mataStr,SPLIT_CHAR,&count);
	char *idStr = *splitResult;
	int id = stringToInt(idStr);
	mataData->id = id;
	
	int i = 1;
	int directCount = 0;
	for (int i = 1 ; i < count ; i ++){
		char **directions = split(*(splitResult + i),SPLIT_DIRECT_ID,&directCount);
		char direct = **directions;
		char *directIdStr = *(directions + 1);
		int directId = stringToInt(directIdStr);
		
		mapNodeMataDataSetDirectId(mataData, direct,directId);
		freeSplitResult(directions,directCount);
	}
	
	freeSplitResult(splitResult,count);
 }
 
 static void mapNodeMataDataSetDirectId(struct mapNodeMataData* mataData,char direct,int id)
 {
	 if(DIRECTOIN_N == direct){
			mataData->directoin_n_id = id;
		}else if(DIRECTOIN_S == direct){
			mataData->directoin_s_id = id;
		}else if(DIRECTOIN_W == direct){
			mataData->directoin_w_id = id;
		}else if(DIRECTOIN_E == direct){
			mataData->directoin_e_id = id;
		}
 }
 
 static void freeMapNodeMataData(struct mapNodeMataData* head)
 {
	 loginfo("Free map node mata data...");
	 struct mapNodeMataData* next;
	 while(head != NULL){
		 next = head->next;
		 printf("Free node id %d, n:%d, s:%d, w:%d, e:%d,\r\n",head->id,
		 head->directoin_n_id,
		 head->directoin_s_id,
		 head->directoin_w_id,
		 head->directoin_e_id
		 );
		 free(head);
		 head = next;
	 }
	 
 }
 
 static struct mapNodeMataData* createEmptyMataData()
 {
	 struct mapNodeMataData* mata = malloc(sizeof(struct mapNodeMataData));
	 mata->next = NULL;
	 mata->directoin_n_id = 0;
	 mata->directoin_s_id = 0;
	 mata->directoin_w_id = 0;
	 mata->directoin_e_id = 0;
	 return mata;
	 
 }
 
 