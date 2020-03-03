#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int peek() {
   return intArray[front];
}

bool isEmpty() {
   return itemCount == 0;
}

bool isFull() {
   return itemCount == MAX;
}

int size() {
   return itemCount;
}  

void insert(int data) {

   if(!isFull()) {
	
      if(rear == MAX-1) {
         rear = -1;            
      }       

      intArray[++rear] = data;
      itemCount++;
   }
}

int removeData() {
   int data = intArray[front++];
	
   if(front == MAX) {
      front = 0;
   }
	
   itemCount--;
   return data;  
}

void fillTheProcessArray(int taskDelimiter){
   int inputTask;

   for(int i = 0; i < taskDelimiter; i++){
      printf("Input the current task \n");
      scanf("%d", &inputTask);
      insert(inputTask);

   }
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
      fillTheProcessArray(numberOfTasks);

   /*requesting in what block should the head start*/
   printf("Where should the head start?:\n");
   scanf("%d", &startingHead);

   if(startingHead < 0 || startingHead > 100){
      printf("Starting head block must be whithin [1-100].\n");
   }

   return 0;
}
