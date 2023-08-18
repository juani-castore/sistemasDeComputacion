#include <stdio.h>
#include <stdlib.h>


// usar make para compilar

// correr el siguiente comando para chequear que no esten perdiendo memoria
// valgrind --leak-check=full --show-leak-kinds=all -v ./clase01.out


/**********Ejercicio 1**********/
char* superConcatenate(char* a[], int size) {
     //COMPLETAR
    int i = 0;
    int totalLen = 0;
    int j;
    int resIter = 0;
    while (i < size)
    {
        j = 0;
        while (a[i][j]!= 0)
        {
            totalLen++;
            j++;
        }
        i++;
    }
    char* res = (char*)malloc(sizeof(char) * (totalLen + 1));
    i = 0;
    while (i < size)
    {
        j = 0;
        while (a[i][j]!= 0)
        {
            res[resIter] = a[i][j];
            j++;
            resIter++;
        }
        i++;
    }
    res[totalLen] = '\0';
    return res;
}

//---------------auxiliares Ejercicio 2--------------
struct node {
  int data;
  struct node *next;
};

struct list
{
    struct node *first;
    int size;
};

struct list* createList(){
    struct list* l = (struct list*) malloc(sizeof(struct list));
    l->first = NULL;
    l->size = 0;
    return l;
}


void printList(struct list* l){
    printf("Lista: ");
    struct node* aux = l->first;
    while(aux != NULL){
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");    
}

void addLast (struct list* l, int data){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(l->first == NULL){
        l->first = newNode;
    }else{
        struct node* aux = l->first;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = newNode;
    }
    l->size++;
}

void deleteList(struct list* l){
    struct node* aux = l->first;
    while(aux != NULL){
        struct node* aux2 = aux;
        aux = aux->next;
        free(aux2);
    }
    free(l);
}



/**********Ejercicio 2**********/

// getLast
void getLast(struct list** twoLists, struct node** a, struct node** b){
    //COMPLETAR
}

// getMerge
struct list* getMerge(struct list** twoLists){
    //COMPLETAR
    return NULL;
}


int main() {

    char* v[5] = {"hola", "como", "va", "el", "dia"};

    /**********Ejercicio 1**********/
    char* sc = superConcatenate(v, 5);
    // Imprimir sc:
    printf("la concatenacion es : %s \n",sc);
    // Liberar sc
    free(sc);
    

    /**********Ejercicio 2**********/
    // Crear dos listas
    struct list* twoLists[2];
    twoLists[0] = createList();
    twoLists[1] = createList();
    // Agregar elementos a las listas
    addLast(twoLists[0], 53);
    addLast(twoLists[0], 13);
    addLast(twoLists[0], -92);
    addLast(twoLists[0], 42);
    addLast(twoLists[1], 10);
    addLast(twoLists[1], 71);
    addLast(twoLists[1], 81);
    // Imprimir las listas
    printList(twoLists[0]);
    printList(twoLists[1]);

    // Obtener el ultimo nodo de cada lista
    struct node* lastA;
    struct node* lastB;
    getLast(twoLists, &lastA, &lastB);
    // Imprimir los ultimos nodos
    printf("Ultimo nodo de la lista 1: %d\n", lastA->data);
    printf("Ultimo nodo de la lista 2: %d\n", lastB->data);

    // Obtener la lista que resulta de concatenar las dos listas
    struct list* mergedList = getMerge(twoLists);
    // Imprimir la lista resultante
    printList(mergedList);
    
    //LIBERAR LA MEMORIA QUE SE HAYA PEDIDO
    




    return 0;
}
