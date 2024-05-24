/* 
	The code is shortcut for spliting the string and copy the content to other string 
	I have used  
	array of pointers 
	strtok function for spliting 
*/


#include <stdio.h>
#include <string.h>
int main()
{
    // printf("Hello World");
    char *x[10] = {0}; 
    //array of strings 
    
    char s[] = "This is the way again";
    char d[] =  " ";
    
    char *portion = strtok(s,d);
    int i=0;
    int len;
    
    while(portion != NULL){
        // printf("%s\n",portion);
        x[i] = portion;
        printf("%s\n",x[i]);
        i++;
        len = i;
        portion = strtok(NULL,d);
    }
    
    //accessing array of strings 
    for(int i=0; i<len;i++){
        printf("string is %s\n",x[i]);
    }
    
    
    
  

    return 0;
}
