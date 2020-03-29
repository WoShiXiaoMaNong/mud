 #ifndef STRINGTOOL_H_
 

 char** split(char *str,char split ,int * count);
 
 void freeSplitResult(char ** splitResult, int count);
 
 int stringToInt(char *number);
 
 
 //static 
 static void initSubStrSizeList(char *str,char split,int *count,int *subStrSizeList);
 static void initSplitResult(char ** splitResult,int subStrCount,int *subStrSizeList);
 #endif