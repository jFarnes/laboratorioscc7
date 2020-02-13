//Para compilar Scheulers.c escribimos en consola
//gcc -o Schedulers Schedulers.c
//./Schedulers~

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct processParameters {
	int AT,BT,priority,ET,WT,RT,TT,TH;
	int QM; //quantum
	int QU; //queue
};

struct processParameters arr_process[29];

void output(void *vargp) {
	printf("|-------|-------|-------|-------|-------|-------|-------|-------|-------| \n");
	printf("|PXX\t|QU\t|QM\t|AT\t|BT\t|ET\t|WT\t|RT\t|TT\t|\n");
	printf("|-------|-------|-------|-------|-------|-------|-------|-------|-------| \n\n");
} 

void outputFCFS(void *vargp) {
	printf("|-------|-------|-------|-------|-------|-------|-------| \n");
	printf("|PXX\t|AT\t|BT\t|ET\t|WT\t|RT\t|TT\t|\n");
	printf("|-------|-------|-------|-------|-------|-------|-------| \n\n");
} 

void FCFS(void *vargp) {
	printf(" --> FCFS\n");
	outputFCFS(0);
} 

void PS(void *vargp) {
	printf(" --> PS\n");
	output(0);
} 

void RR(void *vargp) {
	printf(" --> RR\n");
	output(0);
} 

void MLFQS(void *vargp) {
	printf(" --> MLFQS\n");
	output(0);
} 

int menu(){
	int tmp;
	printf("############\n1 - FCFS\n2 - PS\n3 - RR\n4 - MLFQS\n0 - EXIT\n\nSeleccione Opción: ");
	scanf("%d", &tmp);
	return tmp;
}

void fillMyProcess(){
	/*Insertando cada proceso listsado en listProcess.cpu dentro de un arreglo de structs*/
	arr_process[0].AT = 0;
	arr_process[0].BT = 5;
	arr_process[0].priority = 1;

	arr_process[1].AT = 1;
	arr_process[1].BT = 5;
	arr_process[1].priority = 1;

	arr_process[2].AT = 2;
	arr_process[2].BT = 5;
	arr_process[2].priority = 1;

	arr_process[3].AT = 3;
	arr_process[3].BT = 5;
	arr_process[3].priority = 1;

	arr_process[4].AT = 4;
	arr_process[4].BT = 5;
	arr_process[4].priority = 1;

	arr_process[5].AT = 0;
	arr_process[5].BT = 8;
	arr_process[5].priority = 2;

	arr_process[6].AT = 1;
	arr_process[6].BT = 10;
	arr_process[6].priority = 2;

	arr_process[7].AT = 2;
	arr_process[7].BT = 7;
	arr_process[7].priority = 2;

	arr_process[8].AT = 0;
	arr_process[8].BT = 8;
	arr_process[8].priority = 3;

	arr_process[9].AT = 3;
	arr_process[9].BT = 6;
	arr_process[9].priority = 2;

	arr_process[10].AT = 7;
	arr_process[10].BT = 3;
	arr_process[10].priority = 1;

	arr_process[11].AT = 9;
	arr_process[11].BT = 5;
	arr_process[11].priority = 2;

	arr_process[12].AT = 12;
	arr_process[12].BT = 3;
	arr_process[12].priority = 1;

	arr_process[13].AT = 0;
	arr_process[13].BT = 7;
	arr_process[13].priority = 3;

	arr_process[14].AT = 2;
	arr_process[14].BT = 4;
	arr_process[14].priority = 3;

	arr_process[15].AT = 4;
	arr_process[15].BT = 1;
	arr_process[15].priority = 3;

	arr_process[16].AT = 5;
	arr_process[16].BT = 4;
	arr_process[16].priority = 3;

	arr_process[17].AT = 0;
	arr_process[17].BT = 7;
	arr_process[17].priority = 1;

	arr_process[18].AT = 2;
	arr_process[18].BT = 3;
	arr_process[18].priority = 1;

	arr_process[19].AT = 3;
	arr_process[19].BT = 5;
	arr_process[19].priority = 1;

	arr_process[20].AT = 6;
	arr_process[20].BT = 4;
	arr_process[20].priority = 1;

	arr_process[21].AT = 0;
	arr_process[21].BT = 4;
	arr_process[21].priority = 1;

	arr_process[22].AT = 0;
	arr_process[22].BT = 3;
	arr_process[22].priority = 1;

	arr_process[23].AT = 0;
	arr_process[23].BT = 8;
	arr_process[23].priority = 2;

	arr_process[24].AT = 10;
	arr_process[24].BT = 5;
	arr_process[24].priority = 1;

	arr_process[25].AT = 0;
	arr_process[25].BT = 10;
	arr_process[25].priority = 1;

	arr_process[26].AT = 0;
	arr_process[26].BT = 2;
	arr_process[26].priority = 2;

	arr_process[27].AT = 0;
	arr_process[27].BT = 7;
	arr_process[27].priority = 1;

	arr_process[28].AT = 7;
	arr_process[28].BT = 6;
	arr_process[28].priority = 1;
}

int strucSort (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void arrangeMyProces(){	
	//arranging the processList.cpu into Arraving time into arr_process
	qsort(arr_process, 29, sizeof(struct processParameters), strucSort ); 
}

// C Concepts 
// https://gist.github.com/Integralist/6c35d4f26c0c7bf5bdce7b95cfa906b3
int main ( int argc , char * argv []) {
	int op = 9;
	int i;
	pid_t pid;

	fillMyProcess();
	arrangeMyProces();

	for(i = 0; i< sizeof(arr_process)/sizeof(arr_process[0]) ; i++) {
	printf("process %d %d %d %d time is:\n ", i, arr_process[i].AT, arr_process[i].BT, arr_process[i].priority);
	}


	while (op > 0){
		op = menu();
		printf("Procesando opción: %d\n", op);
		if ( op >5 || op<=0 ){
			printf("### END ###\n");
			break;
		}
		printf("### BEGIN ###\n");
		switch(op){
			case 1:
			FCFS(0);
			break;
			case 2:
			PS(0);
			break;
			case 3:
			RR(0);
			break;
			default:
			case 4:
			MLFQS(0);
			break;
		}
	}
	return 0;
}