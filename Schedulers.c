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
	printf("|-------|-------|-------|-------|-------|-------|-------| \n");
} 

void FCFS(void *vargp) {

	int throughputBT = 0;
	int throughputTT = 0;
	int throughputWT = 0;
	printf(" --> FCFS\n");

	/*We proccess all Exit time and store them in arr_process.ET*/
	for(int i = 0; i< sizeof(arr_process)/sizeof(arr_process[0]) ; i++){
		throughputBT = throughputBT + arr_process[i].BT; 
		arr_process[i].ET = throughputBT;
	}

	/*We proccess all Turnaround Time and store them in arr_process.TT*/
	for(int i = 0; i< sizeof(arr_process)/sizeof(arr_process[0]) ; i++){
		throughputTT = arr_process[i].ET - arr_process[i].AT;
		arr_process[i].TT = throughputTT;
	}

	/*We proccess all Wait Time and store them in arr_process.WT*/
	for(int i = 0; i< sizeof(arr_process)/sizeof(arr_process[0]) ; i++){
		throughputWT = arr_process[i].TT - arr_process[i].BT;
		arr_process[i].WT = throughputWT;
	}

	outputFCFS(0);
	for(int i = 0; i< sizeof(arr_process)/sizeof(arr_process[0]) ; i++){
		printf("|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n", i, arr_process[i].AT, arr_process[i].BT, arr_process[i].ET, arr_process[0].WT, arr_process[0].RT, arr_process[i].TT);

	}
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
	arr_process[0].ET = 0;
	arr_process[0].QM = 0;
	arr_process[0].QU = 0;
	arr_process[0].RT = 0;
	arr_process[0].TT = 0;
	arr_process[0].WT = 0;
	
	arr_process[1].AT = 1;
	arr_process[1].BT = 5;
	arr_process[1].priority = 1;
	arr_process[0].ET = 0;
	arr_process[0].QM = 0;
	arr_process[0].QU = 0;
	arr_process[0].RT = 0;
	arr_process[0].TT = 0;
	arr_process[0].WT = 0;

	arr_process[2].AT = 2;
	arr_process[2].BT = 5;
	arr_process[2].priority = 1;
	arr_process[2].ET = 0;
	arr_process[2].QM = 0;
	arr_process[2].QU = 0;
	arr_process[2].RT = 0;
	arr_process[2].TT = 0;
	arr_process[2].WT = 0;

	arr_process[3].AT = 3;
	arr_process[3].BT = 5;
	arr_process[3].priority = 1;
	arr_process[3].ET = 0;
	arr_process[3].QM = 0;
	arr_process[3].QU = 0;
	arr_process[3].RT = 0;
	arr_process[3].TT = 0;
	arr_process[3].WT = 0;

	arr_process[4].AT = 4;
	arr_process[4].BT = 5;
	arr_process[4].priority = 1;
	arr_process[4].ET = 0;
	arr_process[4].QM = 0;
	arr_process[4].QU = 0;
	arr_process[4].RT = 0;
	arr_process[4].TT = 0;
	arr_process[4].WT = 0;

	arr_process[5].AT = 0;
	arr_process[5].BT = 8;
	arr_process[5].priority = 2;
	arr_process[5].ET = 0;
	arr_process[5].QM = 0;
	arr_process[5].QU = 0;
	arr_process[5].RT = 0;
	arr_process[5].TT = 0;
	arr_process[5].WT = 0;

	arr_process[6].AT = 1;
	arr_process[6].BT = 10;
	arr_process[6].priority = 2;
	arr_process[6].ET = 0;
	arr_process[6].QM = 0;
	arr_process[6].QU = 0;
	arr_process[6].RT = 0;
	arr_process[6].TT = 0;
	arr_process[6].WT = 0;

	arr_process[7].AT = 2;
	arr_process[7].BT = 7;
	arr_process[7].priority = 2;
	arr_process[7].ET = 0;
	arr_process[7].QM = 0;
	arr_process[7].QU = 0;
	arr_process[7].RT = 0;
	arr_process[7].TT = 0;
	arr_process[7].WT = 0;

	arr_process[8].AT = 0;
	arr_process[8].BT = 8;
	arr_process[8].priority = 3;
	arr_process[8].ET = 0;
	arr_process[8].QM = 0;
	arr_process[8].QU = 0;
	arr_process[8].RT = 0;
	arr_process[8].TT = 0;
	arr_process[8].WT = 0;

	arr_process[9].AT = 3;
	arr_process[9].BT = 6;
	arr_process[9].priority = 2;
	arr_process[9].ET = 0;
	arr_process[9].QM = 0;
	arr_process[9].QU = 0;
	arr_process[9].RT = 0;
	arr_process[9].TT = 0;
	arr_process[9].WT = 0;

	arr_process[10].AT = 7;
	arr_process[10].BT = 3;
	arr_process[10].priority = 1;
	arr_process[10].ET = 0;
	arr_process[10].QM = 0;
	arr_process[10].QU = 0;
	arr_process[10].RT = 0;
	arr_process[10].TT = 0;
	arr_process[10].WT = 0;

	arr_process[11].AT = 9;
	arr_process[11].BT = 5;
	arr_process[11].priority = 2;
	arr_process[11].ET = 0;
	arr_process[11].QM = 0;
	arr_process[11].QU = 0;
	arr_process[11].RT = 0;
	arr_process[11].TT = 0;
	arr_process[11].WT = 0;

	arr_process[12].AT = 12;
	arr_process[12].BT = 3;
	arr_process[12].priority = 1;
	arr_process[12].ET = 0;
	arr_process[12].QM = 0;
	arr_process[12].QU = 0;
	arr_process[12].RT = 0;
	arr_process[12].TT = 0;
	arr_process[12].WT = 0;

	arr_process[13].AT = 0;
	arr_process[13].BT = 7;
	arr_process[13].priority = 3;
	arr_process[13].ET = 0;
	arr_process[13].QM = 0;
	arr_process[13].QU = 0;
	arr_process[13].RT = 0;
	arr_process[13].TT = 0;
	arr_process[13].WT = 0;

	arr_process[14].AT = 2;
	arr_process[14].BT = 4;
	arr_process[14].priority = 3;
	arr_process[14].ET = 0;
	arr_process[14].QM = 0;
	arr_process[14].QU = 0;
	arr_process[14].RT = 0;
	arr_process[14].TT = 0;
	arr_process[14].WT = 0;

	arr_process[15].AT = 4;
	arr_process[15].BT = 1;
	arr_process[15].priority = 3;
	arr_process[15].ET = 0;
	arr_process[15].QM = 0;
	arr_process[15].QU = 0;
	arr_process[15].RT = 0;
	arr_process[15].TT = 0;
	arr_process[15].WT = 0;

	arr_process[16].AT = 5;
	arr_process[16].BT = 4;
	arr_process[16].priority = 3;
	arr_process[16].ET = 0;
	arr_process[16].QM = 0;
	arr_process[16].QU = 0;
	arr_process[16].RT = 0;
	arr_process[16].TT = 0;
	arr_process[16].WT = 0;

	arr_process[17].AT = 0;
	arr_process[17].BT = 7;
	arr_process[17].priority = 1;
	arr_process[17].ET = 0;
	arr_process[17].QM = 0;
	arr_process[17].QU = 0;
	arr_process[17].RT = 0;
	arr_process[17].TT = 0;
	arr_process[17].WT = 0;

	arr_process[18].AT = 2;
	arr_process[18].BT = 3;
	arr_process[18].priority = 1;
	arr_process[18].ET = 0;
	arr_process[18].QM = 0;
	arr_process[18].QU = 0;
	arr_process[18].RT = 0;
	arr_process[18].TT = 0;
	arr_process[18].WT = 0;

	arr_process[19].AT = 3;
	arr_process[19].BT = 5;
	arr_process[19].priority = 1;
	arr_process[19].ET = 0;
	arr_process[19].QM = 0;
	arr_process[19].QU = 0;
	arr_process[19].RT = 0;
	arr_process[19].TT = 0;
	arr_process[19].WT = 0;

	arr_process[20].AT = 6;
	arr_process[20].BT = 4;
	arr_process[20].priority = 1;
	arr_process[20].ET = 0;
	arr_process[20].QM = 0;
	arr_process[20].QU = 0;
	arr_process[20].RT = 0;
	arr_process[20].TT = 0;
	arr_process[20].WT = 0;

	arr_process[21].AT = 0;
	arr_process[21].BT = 4;
	arr_process[21].priority = 1;
	arr_process[21].ET = 0;
	arr_process[21].QM = 0;
	arr_process[21].QU = 0;
	arr_process[21].RT = 0;
	arr_process[21].TT = 0;
	arr_process[21].WT = 0;

	arr_process[22].AT = 0;
	arr_process[22].BT = 3;
	arr_process[22].priority = 1;
	arr_process[22].ET = 0;
	arr_process[22].QM = 0;
	arr_process[22].QU = 0;
	arr_process[22].RT = 0;
	arr_process[22].TT = 0;
	arr_process[22].WT = 0;

	arr_process[23].AT = 0;
	arr_process[23].BT = 8;
	arr_process[23].priority = 2;
	arr_process[23].ET = 0;
	arr_process[23].QM = 0;
	arr_process[23].QU = 0;
	arr_process[23].RT = 0;
	arr_process[23].TT = 0;
	arr_process[23].WT = 0;

	arr_process[24].AT = 10;
	arr_process[24].BT = 5;
	arr_process[24].priority = 1;
	arr_process[24].ET = 0;
	arr_process[24].QM = 0;
	arr_process[24].QU = 0;
	arr_process[24].RT = 0;
	arr_process[24].TT = 0;
	arr_process[24].WT = 0;

	arr_process[25].AT = 0;
	arr_process[25].BT = 10;
	arr_process[25].priority = 1;
	arr_process[25].ET = 0;
	arr_process[25].QM = 0;
	arr_process[25].QU = 0;
	arr_process[25].RT = 0;
	arr_process[25].TT = 0;
	arr_process[25].WT = 0;

	arr_process[26].AT = 0;
	arr_process[26].BT = 2;
	arr_process[26].priority = 2;
	arr_process[26].ET = 0;
	arr_process[26].QM = 0;
	arr_process[26].QU = 0;
	arr_process[26].RT = 0;
	arr_process[26].TT = 0;
	arr_process[26].WT = 0;

	arr_process[27].AT = 0;
	arr_process[27].BT = 7;
	arr_process[27].priority = 1;
	arr_process[27].ET = 0;
	arr_process[27].QM = 0;
	arr_process[27].QU = 0;
	arr_process[27].RT = 0;
	arr_process[27].TT = 0;
	arr_process[27].WT = 0;

	arr_process[28].AT = 7;
	arr_process[28].BT = 6;
	arr_process[28].priority = 1;
	arr_process[28].ET = 0;
	arr_process[28].QM = 0;
	arr_process[28].QU = 0;
	arr_process[28].RT = 0;
	arr_process[28].TT = 0;
	arr_process[28].WT = 0;
}

int strucSort (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void arrangeMyProces(){	
	//arranging the processList.cpu by Arraving time into arr_process
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