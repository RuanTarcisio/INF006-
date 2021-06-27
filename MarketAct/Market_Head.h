#ifndef MARKET_HEAD_H_INCLUDED
#define MARKET_HEAD_H_INCLUDED

#define Compra 0
#define Venda 1


typedef struct datanode
{
    int qntd;
    float valor;
    float valor_unidade;
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

List *PETR4, *VALE5, *LAME3, *USIM5, *ITSA4;

void inicializar();
List* Create_List();
void push(List *list, DataNode* data, int opcao);
void insert (List* list, DataNode* data, int opcao);
void pop(List *list, int opcao);
int remover(List* list);
void imprimir (List* list);
bool isEmpty (List* list, int opcao);
Node* atPos(List* list, int index, int opcao);
int indexOf(List* list, Node* node, int opcao);

DataNode *RecebeDados();

void menuGeral();
void menuVendas();
void menuCompras();
void menuListar();

#endif // MARKET_HEAD_H_INCLUDED
