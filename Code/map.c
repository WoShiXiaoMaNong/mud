 #include "map.h"
 #include "logger.h"
 #include <stdio.h>
 
 void initWorld(struct world* mud,char *mapConfig)
 {
	loginfo("im initworld, map config path is ");
	loginfo(mapConfig);
	 
	FILE *fp;
	fp = fopen(mapConfig, "r");
	int index = 0;
	char temp = fgetc(fp);
	char tempArr[1024];
	while(temp != '\0' && temp != EOF){
		if(temp == '\n'){
			temp = '\0';
			tempArr[index] = temp;
			puts(tempArr);
			index = 0;
		}else{
			tempArr[index] = temp;
			index++;
		}
		temp = fgetc(fp);
	}
	fclose(fp);
 }
 
 /*
 
	//while(1){
		
		test();
	//}
 
 */