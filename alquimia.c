#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "alquimia.h"

node_t * h = NULL;
node_t * n = NULL;
node_t * o = NULL;

/*Initializers*/
pthread_mutex_t count_mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_mutex = PTHREAD_COND_INITIALIZER;
pthread_cond_t  condition_cond  = PTHREAD_COND_INITIALIZER;
pthread_cond_t *conditions[2] = { &condition_cond, &condition_mutex };

int reacciones, least_nitrogeno, nitro, least_hidrogeno, hidro, least_oxigeno, oxi, nh3=0, o2=0;

/* Possible elements */
char *elementos[] = { "Nitrógeno", "Hidrógeno", "Oxígeno" };

/*Methond for Nitrogeno element*/
void *Ni(void *i){
  struct Elemento *ele = i;
  pthread_mutex_lock(&count_mutex);
  /*Save the element ID*/
  push(n, ele->id);
  nitro++;

	/*Waiting on a condition variable. */
	while (hidro < 3)
		pthread_cond_wait(conditions[0], &count_mutex);

  pthread_mutex_unlock(&count_mutex);

  //NH3+O2
  NH3_O2(ele);
}

/*Method for Hidrogeno Element*/
void *Hi(void *i){
  struct Elemento *ele = i;
  pthread_mutex_lock(&count_mutex);
  hidro++;
  /*Save the hidro element ID*/
  push(h, ele->id);

  /*Waiting on a condition variable. */
  while (hidro < 3 && nitro < 1)
    pthread_cond_wait(conditions[0], &count_mutex);

  pthread_mutex_unlock(&count_mutex);

  //NH3+O2
  NH3_O2(ele);
}

/*Method for Oxigeno Element*/
void *Ox(void *i){
  struct Elemento *ele = i;
  pthread_mutex_lock(&count_mutex);
  oxi++;
  /*Save the Oxigeno element ID*/
  push(o, ele->id);

	/*Waiting on a condition variable. */
	while (oxi < 2)
	   pthread_cond_wait(conditions[0], &count_mutex);

  pthread_mutex_unlock(&count_mutex);

  //NH3+O2
  NH3_O2(ele);
}

/*Method to get the quimical reaction*/
void *NH3_O2(void *i){
  struct Elemento *ele = i;
  pthread_mutex_lock(&count_mutex);

	if (nitro > 0 && hidro > 2) {
    nitro--;
    hidro-=3;
		pthread_cond_signal(conditions[0]);
    printf(">>>>>>>>>>>> Una molécula de NH3.\n");
    nh3++;
	}

  if (oxi >= 2) {
    oxi-=2;
    pthread_cond_signal(conditions[0]);
    printf(">>>>>>>>>>>> Una molécula de O2.\n");
    o2++;
  }

	if(o2>0 && nh3>0){
    o2--;
    nh3--;
    printf("FUEGO!!!!!!!!!\n");
    for(int i=0; i<3; i++) printf("id:%02d Hidrógeno\n", pop(h));
    printf("id:%02d Nitrógeno\n", pop(n));
    for(int i=0; i<2; i++ ) printf("id:%02d Oxígeno\n", pop(o));

    printf("##### Reacción Exitosa! Convertimos un Ácido en Monóxido de Nitrógeno y Agua.\n");
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

/*Removing element*/
int pop(node_t * head) {
    int retval = -1;
    node_t * next_node = NULL;
    if (head == NULL) {
        return -1;
    }
    /*We are going to keep the default head, and just removing nodes from heap*/
    next_node = head->next;
    //get the value of first node after head
    retval = next_node->val;
    head->next = next_node->next;
    free(next_node);
    return retval;
}

void main(){
  int id =0;
  int total_elements = reacciones*6;
  struct Elemento ele[total_elements];

  printf("\nNH3 + O2 ➝ Agua?\n");
  printf("Cuántas reacciones crear?: ");
  scanf("%d", &reacciones);
  least_nitrogeno = reacciones;
  least_hidrogeno = reacciones*3;
  least_oxigeno = reacciones*2;
  printf("\nSe crearán %02d Nitrógeno, %02d Hidrógeno y %02d Oxígeno.\n\n", least_nitrogeno, least_hidrogeno, least_oxigeno);
  nitro = 0;
  hidro = 0;
  oxi = 0;

  h = (node_t *) malloc(sizeof(node_t));
  n = (node_t *) malloc(sizeof(node_t));
  o = (node_t *) malloc(sizeof(node_t));

  for(int i=0; i<total_elements; i++){
    ele[i].id = ++id;
    ele[i].element = rand() % 3;  // [0-2]
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
