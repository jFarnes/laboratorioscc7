#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX 100

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

/*      This code is the data structure that stores all the process list inputed by user                **/ 
/** --------------------------------------------------------------------------------------------------- **/
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
/**--------------------------------------------------------------------------------------------------------**/
int printMyArray(){
   int data = intArray[front++];
   int intPrint[size()];

   
   int i = 0;
   while(i < size()) {
      intPrint[i] = intArray[i];           
      i++;
   }

   printf("El listado es: ");
   for(int loop = 0; loop < size(); loop++)
      printf("%d ", intPrint[loop]);
   printf("\n");

}
  
void fillTheProcessArray(int taskDelimiter){
   int inputTask;

   for(int i = 0; i < taskDelimiter; i++){
      printf("Input the current task \n");
      scanf("%d", &inputTask);
      insert(inputTask);

   }
}
/* calculating the @promeio variable*/
float operationsMidPoint(int startingHead){
   float collector = 0.00;

   /* first step for the average is to susbtract the startingHead - intArray in the first position*/

   collector = abs(intArray[0] - startingHead); 

   for(int i = 0; i < size() -1 ; i++){
      collector = collector + abs(intArray[i] - intArray[i + 1]);
   }

   return collector;
}

/* calculating the standar deviation*/
float standarDeviation(int startingHead){
   float u = 0, upside = 0, temp = 0; 
   
   u = operationsMidPoint(startingHead)/size();
   upside = pow(startingHead - intArray[0]-u,2);

   for(int i = 0; i < size() - 1 ; i++)
   {
      temp = abs(intArray[i] - intArray[i + 1]);
      upside = upside + pow( temp - u,2);
   }

   return sqrt(upside/(size() - 1));;
}

int shortestPointToHead(int startingHead){
   int pivot = abs(startingHead - intArray[0]);
   int temp, pivotLocation; 

   for (int i = 1; i < size(); i++)
   {
      temp = abs(startingHead - intArray[i]);
      if(temp < pivot){
         pivot = temp;
         pivotLocation = i;
      }
   }

   return pivotLocation;
}

float scanArrangeLeft(int startingHead ,int pivotLocation){

   float collector = collector + abs(startingHead - intArray[pivotLocation]);

   for (int i = pivotLocation; i > 0 ; i--)
      collector = collector + abs(startingHead - intArray[i - 1]);
   
   for (int i = pivotLocation + 1; i < size() -1 ; i++)
      collector = collector + abs(startingHead - intArray[i + 1]);

   return collector/size();
}

float scanArrangeRight(int startingHead ,int pivotLocation){

   float collector = collector + abs(startingHead - intArray[pivotLocation]);

   for (int i = pivotLocation + 1; i < size() -1 ; i++)
      collector = collector + abs(startingHead - intArray[i + 1]);

   for (int i = pivotLocation; i > 0 ; i--)
      collector = collector + abs(startingHead - intArray[i - 1]);
   
   return collector/size();
}

/* REFERENCE FOR DISK SCHEDULING ALGORITHMS http://www.cs.iit.edu/~cs561/cs450/disksched/disksched.html */
void FIFO(void *vargp, int startingHead) {
   float average, eDeviation;

	printf("First In First Out\n");
	printf("Posicion Actual: %d\n", startingHead);
   printMyArray();
   average = operationsMidPoint(startingHead);
	printf("Total seek time: %.2f\n", average);
   eDeviation = standarDeviation(startingHead);
	printf("Promedio: %.2f\n", average/size());
	printf("Desviacion estandar: %.2f \n", eDeviation);  
} 
/* REFERENCE FOR DISK SCHEDULING ALGORITHMS http://www.cs.iit.edu/~cs561/cs450/disksched/disksched.html */
int SCAN(void *vargp,int startingHead) {
	
   char headDirection[100];
   int pivotLocation = shortestPointToHead(startingHead);
   float midPoint, eDeviation;

   /* requesting the movement (left of right) for the head of the disk*/
   printf("Where the head should move Right(r) or Left(l):\n");
   scanf("%s", headDirection);

  if(strcmp("r",headDirection) == 0){
      printf("The head is moving right\n");
      printf("Elevator Algorithm(Scan)\n");
      printf("Posicion Actual: %d \n",  startingHead);
      printMyArray();
      midPoint = scanArrangeRight(startingHead,pivotLocation);
      printf("Promedio: %.2f \n", midPoint);
      eDeviation = standarDeviation(startingHead);
      printf("Desviacion estandar: %.2f \n", eDeviation);
   } else if(strcmp("l",headDirection) == 0){
      printf("The head is moving left\n");
      printf("Elevator Algorithm(Scan)\n");
      printf("Posicion Actual: %d \n",  startingHead);
      printMyArray();
      midPoint = scanArrangeLeft(startingHead,pivotLocation);
      printf("Promedio: %.2f \n", midPoint);
      eDeviation = standarDeviation(startingHead);
      printf("Desviacion estandar: %.2f \n", eDeviation);
   } else { 
      printf("Wrong head direction, please input 'r' for right and 'l' for left.\n");
      return 0;
   }


} 

/* REFERENCE FOR DISK SCHEDULING ALGORITHMS http://www.cs.iit.edu/~cs561/cs450/disksched/disksched.html */
int CSCAN(void *vargp, int startingHead) {

   char headDirection[100];
   int pivotLocation = shortestPointToHead(startingHead);
   float midPoint, eDeviation;

   /* requesting the movement (left of right) for the head of the disk*/
   printf("Where the head should move Right(r) or Left(l):\n");
   scanf("%s", headDirection);

  if(strcmp("r",headDirection) == 0){
      printf("The head is moving right\n");
      printf("Elevator Algorithm(Scan)\n");
      printf("Posicion Actual: %d \n",  startingHead);
      printMyArray();
      midPoint = scanArrangeRight(startingHead,pivotLocation);
      printf("Promedio: %.2f \n", midPoint);
      eDeviation = standarDeviation(startingHead);
      printf("Desviacion estandar: %.2f \n", eDeviation);
   } else if(strcmp("l",headDirection) == 0){
      printf("The head is moving left\n");
      printf("Elevator Algorithm(Scan)\n");
      printf("Posicion Actual: %d \n",  startingHead);
      printMyArray();
      midPoint = scanArrangeLeft(startingHead,pivotLocation);
      printf("Promedio: %.2f \n", midPoint);
      eDeviation = standarDeviation(startingHead);
      printf("Desviacion estandar: %.2f \n", eDeviation);
   } else { 
      printf("Wrong head direction, please input 'r' for right and 'l' for left.\n");
      return 0;
   }
} 

/* REFERENCE FOR DISK SCHEDULING ALGORITHMS http://www.cs.iit.edu/~cs561/cs450/disksched/disksched.html */
void SSTF(void *vargp, int startingHead) {
   float average, eDeviation;

	printf("Shortest Seek Time First\n");
	printf("Posicion Actual: %d\n", startingHead);
   printMyArray();
   average = operationsMidPoint(startingHead);
	printf("Promedio: %.2f\n", average);
   eDeviation = standarDeviation(startingHead);
	printf("Desviacion estandar: %.2f \n", eDeviation);  
} 

int menu(){
	int tmp;
	printf("\n############\n1 - FIFO\n2 - SCAN\n3 - CSCAN\n4 - SSTF\n0 - EXIT\n\nSeleccione Opción: ");
	scanf("%d", &tmp);
	return tmp;
}

int main( ) {

   int numberOfTasks, startingHead; 
   int op = 9;

   /*Requesting the number of tasks to be in the array*/
   printf("Enter a the number of tasks to add:\n");
   scanf("%d", &numberOfTasks);

   if(numberOfTasks < 0 || numberOfTasks > 100){
      printf("Number of block must be whithin [1-100].\n");
      return 0;
   } else if (numberOfTasks < 100 && numberOfTasks > 0)
      fillTheProcessArray(numberOfTasks);

   /*requesting in what block should the head start*/
   printf("Where should the head start?:\n");
   scanf("%d", &startingHead);

   if(startingHead < 0 || startingHead > 100){
      printf("Starting head block must be whithin [1-100].\n");
   }

	while (op > 0){
		op = menu();
		printf("Procesando opción: %d\n", op);
		if ( op >5 || op<=0 ){
			printf("\n### END ###\n");
			break;
		}
		printf("\n### BEGIN ###\n");
		switch(op){
			case 1:
			FIFO(0, startingHead);
			break;
			case 2:
			SCAN(0, startingHead);
			break;
			case 3:
			CSCAN(0, startingHead);
			break;
			default:
			case 4:
			SSTF(0, startingHead);
			break;
		}
	}

   return 0;
}