#include <stdio.h>
#include <pthread.h>
#include <windows.h>
#include "logger.h"
#include "stringTool.h"

void test4( )
{
	
	while(1 ){
	loginfo("12345");
	}
}

void test2()
{

	while(1){
	 logerror("abced");
	}
}

int main(void)
{
	int a = 1;
	int b = 2;
	pthread_t thread1, thread2;

	int ret_thrd1, ret_thrd2;

    ret_thrd1 = pthread_create(&thread1, NULL, (void *)&test2,NULL);
     ret_thrd2 = pthread_create(&thread2, NULL, (void *)&test4,NULL);
	
	if (ret_thrd1 != 0) {
        printf("1 faild\n");
    } else {
        printf("1 succeed\n");
    }

    if (ret_thrd2 != 0) {
        printf("2 faild\n");
    } else {
        printf("2 succeed\n");
    }
	 pthread_join(ret_thrd1, NULL);
 pthread_join(ret_thrd2, NULL);

	system("pause"); 
	
}
