#include <stdio.h>
#include <string.h>

void fillTheProcessArray(){

   
}

int main( ) {

   int numberOfTasks, startingHead; 
   char headDirection[100];

   /* requesting the movement (left of right) for the head of the disk*/
   printf("Where the head should move Right(r) or Left(l):\n");
   scanf("%s", headDirection);

  if(strcmp("r",headDirection) == 0)
      printf("The head is moving right\n");
   else if (strcmp("l",headDirection) == 0)
      printf("The head is moving left\n");
   else{
      printf("Wrong head direction, please input 'r' for right and 'l' for left.\n");
      return 0;
   }

   /*Requesting the number of tasks to be in the array*/
   printf("Enter a the number of tasks to add:\n");
   scanf("%d", &numberOfTasks);

   if(numberOfTasks < 0 || numberOfTasks > 100){
      printf("Number of block must be whithin [1-100].");
   } else if (numberOfTasks < 100 && numberOfTasks > 0)
      fillTheProcessArray();

   /*requesting in what block should the head start*/
   printf("Where should the head start?:\n");
   scanf("%d", &startingHead);

   if(startingHead < 0 || startingHead > 100){
      printf("Starting head block must be whithin [1-100].\n");
   }

   return 0;
}
