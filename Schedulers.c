//Para compilar Scheulers.c escribimos en consola
//gcc -o Schedulers Schedulers.c
//./Schedulers

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct processParameters {
	int AT;
	int BT;
	int priority;
};

struct processParameters arr_process[29];

struct processParameters p01 = {1,5,1};
struct processParameters p02 = {2,5,1};
struct processParameters p03 = {3,5,1};
struct processParameters p04 = {4,5,1};
struct processParameters p05 = {0,8,2};
struct processParameters p06 = {1,10,2};
struct processParameters p07 = {2,7,2};
struct processParameters p08 = {0,8,3};
struct processParameters p09 = {3,6,2};
struct processParameters p10 = {7,3,1};
struct processParameters p11 = {9,5,2};
struct processParameters p12 = {12,3,1};
struct processParameters p13 = {0,7,3};
struct processParameters p14 = {2,4,3};
struct processParameters p15 = {4,1,3};
struct processParameters p16 = {5,4,3};
struct processParameters p17 = {0,7,1};
struct processParameters p18 = {2,3,1};
struct processParameters p19 = {3,5,1};
struct processParameters p20 = {6,4,1};
struct processParameters p21 = {0,4,1};
struct processParameters p22 = {0,3,1};
struct processParameters p23 = {0,8,2};
struct processParameters p24 = {10,5,1};
struct processParameters p25 = {0,10,1};
struct processParameters p26 = {0,2,1};
struct processParameters p27 = {0,7,2};
struct processParameters p28 = {7,6,1};

void output(void *vargp) {
	printf("|-------|-------|-------|-------|-------|-------|-------|-------|-------| \n");
	printf("|PXX\t|QU\t|QM\t|AT\t|BT\t|ET\t|WT\t|RT\t|TT\t|\n");
	printf("|-------|-------|-------|-------|-------|-------|-------|-------|-------| \n\n");
} 

void FCFS(void *vargp) {
	printf(" --> FCFS\n");
	output(0);
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

// C Concepts 
// https://gist.github.com/Integralist/6c35d4f26c0c7bf5bdce7b95cfa906b3
int main ( int argc , char * argv []) {
	int op = 9;
	pid_t pid;

	arr_process[0].AT = 0;
	arr_process[0].BT = 5;
	arr_process[0].priority = 1;

	printf("process P25 AT time is: ");
	printf("%d \n", arr_process[0].AT);
	printf("%d \n", arr_process[0].BT);
	printf("%d \n", arr_process[0].priority);


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