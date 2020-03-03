#include <stdio.h>
#include <string.h>

void fillTheProcess(){

   
}

int main( ) {

   int numberOfTasks, startingHead; 
   char headDirection[100];

   printf("Where the head should move Right(r) or Left(l):\n");
   scanf("%s", headDirection);

  if(strcmp("r",headDirection) == 0)
      printf("The head is moving right\n");
   else if (strcmp("l",headDirection) == 0)
      printf("The head is moving left\n");
   else
      printf("Wrong head direction, please input 'r' for right and 'l' for left.\n");

   printf("Enter a the number of tasks to add:\n");
   scanf("%d", &numberOfTasks);

   if(numberOfTasks > 100){
      printf("There is a maximun of 100 disk blocks\n");
      return 0;
   } else if (numberOfTasks < 100 AND > 0)


   printf("Where should the head start?:\n");
   scanf("%d", &startingHead);

   return 0;
}
