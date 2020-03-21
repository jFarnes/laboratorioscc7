#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "alquimia.h"

node_t * h = NULL;
node_t * n = NULL;
node_t * o = NULL;

char *elementos[] = { "Nitrogeno", "Hidrogeno", "Oxi­geno" };


/* preparacion de condicionales para crear la condicion de variable entre "semaforos"*/ 
pthread_mutex_t count_mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_mutex = PTHREAD_COND_INITIALIZER;
pthread_cond_t  condition_cond  = PTHREAD_COND_INITIALIZER;
pthread_cond_t *conditions[2] = { &condition_cond, &condition_mutex };

int reacciones, least_nitrogeno, nitro, least_hidrogeno, hidro, least_oxigeno, oxi, nh3=0, o2=0;


void *Ni(void *i){
  struct Elemento *ele = i;
  pthread_mutex_lock(&count_mutex);
  push(n, ele->id);
  nitro++;

	while (hidro < 3)
		pthread_cond_wait(conditions[0], &count_mutex);

  pthread_mutex_unlock(&count_mutex);

  NH3_O2(ele);
}

void *Hi(void *i){
  struct Elemento *ele = i;
  pthread_mutex_lock(&count_mutex);
  hidro++;
  push(h, ele->id);

  while (hidro < 3 && nitro < 1)
    pthread_cond_wait(conditions[0], &count_mutex);

  pthread_mutex_unlock(&count_mutex);

  NH3_O2(ele);
}

void *Ox(void *i){
  struct Elemento *ele = i;
  pthread_mutex_lock(&count_mutex);
  oxi++;
  push(o, ele->id);

	while (oxi < 2)
	   pthread_cond_wait(conditions[0], &count_mutex);
  
  pthread_mutex_unlock(&count_mutex);
  NH3_O2(ele);
}

void *NH3_O2(void *i){
  struct Elemento *ele = i;
  pthread_mutex_lock(&count_mutex);

	if (nitro > 0 && hidro > 2) {
    nitro--;
    hidro-=3;
		pthread_cond_signal(conditions[0]);
    printf("--> molecula de NH3.\n");
    nh3++;
	}

  if (oxi >= 2) {
    oxi-=2;
    pthread_cond_signal(conditions[0]);
    printf("--> molecula de O2.\n");
    o2++;
  }

	if(o2>0 && nh3>0){
    o2--;
    nh3--;
    printf("FUEGO!\n");

    for(int i=0; i<3; i++) printf("id:%02d Hidrogeno\n", pop(h));
      printf("id:%02d NitrÃ³geno\n", pop(n));
    
    for(int i=0; i<2; i++ ) printf("id:%02d Oxi­geno\n", pop(o));
      printf("Reaccion Exitosa! Convertimos un acido en... Agua?\n");
  }

  pthread_mutex_unlock(&count_mutex);
}

void push(node_t * head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
  }

int pop(node_t * head) {
    int retval = -1;
    node_t * next_node = NULL;
    if (head == NULL) {
        return -1;
    }
    next_node = head->next;
    retval = next_node->val;
    head->next = next_node->next;
    free(next_node);
    return retval;
}

void createReactions(int reacciones){
  int id =0;

  h = (node_t *) malloc(sizeof(node_t));
  n = (node_t *) malloc(sizeof(node_t));
  o = (node_t *) malloc(sizeof(node_t));

  //printf("\nNH3 + O2 -> Agua?\n");
  //printf("Cuantas reacciones crear?: ");
  //scanf("%d", &reacciones);
  least_nitrogeno = reacciones;
  least_hidrogeno = reacciones*3;
  least_oxigeno = reacciones*2;
  printf("\nSe crearan %02d Nitrogeno, %02d Hidrogeno y %02d Oxigeno.\n\n", least_nitrogeno, least_hidrogeno, least_oxigeno);
  nitro = 0;
  hidro = 0;
  oxi = 0;
  
  int total_elements = reacciones*6;  
  struct Elemento ele[total_elements];

  for(int i=0; i<total_elements; i++){
    ele[i].id = ++id;
    ele[i].element = rand() % 3;
    if(ele[i].element == 0 && least_nitrogeno != 0){
      pthread_create(&ele[i].thr_id, NULL, Ni, (void *) (&ele[i]));
      printf("Se crea id:%02d %s\n", ele[i].id, elementos[ele[i].element]);
      sleep(1);
      least_nitrogeno--;
    }else if (ele[i].element == 1 && least_hidrogeno != 0){
      pthread_create(&ele[i].thr_id, NULL, Hi, (void *) (&ele[i]));
      printf("Se crea id:%02d %s\n", ele[i].id, elementos[ele[i].element]);
      sleep(1);
      least_hidrogeno--;
    }else if (ele[i].element == 2 && least_oxigeno != 0){
      pthread_create(&ele[i].thr_id, NULL, Ox, (void *) (&ele[i]));
      printf("Se crea id:%02d %s\n", ele[i].id, elementos[ele[i].element]);
      sleep(1);
      least_oxigeno--;
    }else{
      i--;
      id--;
     }
  }

  free(h);
  free(n);
  free(o);
}

int menu(){
	int tmp;
	printf("############\n1 - Calcular una reaccion\n0 - Salir \n\nSeleccione una opcion: ");
	scanf("%d", &tmp);
	return tmp;
}

int main( ) {

   int reacciones;
   int op = 9;

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
        printf("\nNH3 + O2 -> Agua?\n");
        printf("Cuantas reacciones crear?: ");
        scanf("%d", &reacciones);
        createReactions(reacciones);
			break;
		}
	}
   return 0;
}