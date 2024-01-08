#include <stdio.h>

int main(){
   char str[100];
   printf("Input a string: ");
   gets(str);
   char* ptr = str;
   char* start = str;

   while(*ptr != 0){ //loop until point to end of string
    ptr++;
   }
   //if(ptr != start)  //make sure user didn't enter empty string
       ptr--; //make pointer point to character before the end
   printf("String in reverse: ");
   while(ptr != start){
       printf("%c",*ptr);
       ptr--;
   }
   printf("%c",*ptr);

}