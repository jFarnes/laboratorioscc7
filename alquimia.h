/*---------------------   UNIVERSIDAD GALILEO -----------------------*/
/*-----------------   Luis Florian - 0710082 - CC7 ------------------*/
/*---------------------   Prototype Functions -----------------------*/

/*For linkedList*/
typedef struct node {
    int val;
    struct node * next;
} node_t;

/*Struct to reference each element created*/
struct Elemento{
  int element;
  int id;
  pthread_t thr_id;
};

/*Nitrogeno*/
void *Ni(void *i);

/*Hidrogeno*/
void *Hi(void *i);

/*Oxigeno*/
void *Ox(void *i);

/*NH3 + O2 reaction*/
void *NH3_O2(void *i);

/*O2 Molecula*/
void *O2(void *i);

/*Inserting new element*/
void push(node_t * head, int val);

/*Removing element*/
int pop(node_t * head);
