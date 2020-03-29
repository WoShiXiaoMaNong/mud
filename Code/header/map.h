 #ifndef MAP_H_
 
 struct mapNode{
	unsigned int id;
	char *desc;
	
	 
 };
 struct world{
	 struct mapNode *head;
	 int totalNode;
	 
 };
 
 void initWorld(struct world* mud,char *mapConfig);
 
 
 #endif