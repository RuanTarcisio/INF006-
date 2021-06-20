#ifndef MARKET_HEAD_H_INCLUDED
#define MARKET_HEAD_H_INCLUDED


typedef struct datanode
{
    int qntd;
    float valor;
} DataNode;

typedef struct node
{
    DataNode data;
    struct node *next;
} Node;

typedef struct list
{
    int size;
    Node *head;
} List;

List *PETR4, *VALE5, *LAME3;


List* Create_List();
void push(List *list, DataNode data, int opcao);
void imprimir (List* list, int opcao);
bool isEmpty (List* list, int opcao);
void pop(List *list);
Node* atPos(List* list, int index, int opcao);
int indexOf(List* list, Node* node, int opcao);
void erase(List* list, int index);
void insert (List* list, DataNode data, int opcao);


#endif // MARKET_HEAD_H_INCLUDED
