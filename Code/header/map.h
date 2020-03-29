 #ifndef MAP_H_
 
 #define SPLIT_CHAR ','
 #define SPLIT_DIRECT_ID ':'
 #define DIRECTOIN_N 'n'
 #define DIRECTOIN_S 's'
 #define DIRECTOIN_W 'w'
 #define DIRECTOIN_E 'e'
 
 struct mapNodeMataData{
	unsigned int id;
	unsigned int directoin_n_id;
	unsigned int directoin_s_id;
	unsigned int directoin_w_id;
	unsigned int directoin_e_id;
	struct mapNodeMataData *next;
 };
 
struct mapNode{
	unsigned int id;
	char *desc;
	struct mapNode* exit_n;
	struct mapNode* exit_s;
	struct mapNode* exit_w;
	struct mapNode* exit_e;
 };
 
struct world{
	 struct mapNode *head;
	 int totalNode;
	 
 };
 
void initWorld(struct world* mud,char *mapConfig);
  
 
 //static methoc
 static struct mapNodeMataData* createEmptyMataData();
 static void mapNodeMataDataSetDirectId(struct mapNodeMataData* mataData,char direct,int id);
 static void initMapNodeMataData(struct mapNodeMataData* head, char *mapConfig);
 static void buildNodeMataData(struct mapNodeMataData* mataData, char * mataStr);
 static void freeMapNodeMataData(struct mapNodeMataData* head);
 
 
 
 #endif