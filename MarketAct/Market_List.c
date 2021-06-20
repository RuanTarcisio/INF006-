#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Market_Head.h"


/* INSERT, CRIAR FUNÇÃO PARA VERIFICAR O SE O VALOR É MENOR EM CASO DE VENDA, NO CASO DE COMPRA VALOR PAGO > */


void inicializar()
{
    PETR4 = Create_List();
    LAME3 = Create_List();
    VALE5 = Create_List();
}

List* Create_List()
{

    List *list = (List*) malloc (2 * sizeof(List));

    for(int ndx = 0; ndx < 2; ndx++)
    {
        list[ndx].head = NULL;
        list[ndx].size = 0;
    }

    return list;
}


bool isEmpty (List* list, int opcao)
{
    return (list[opcao].size == 0);
}


void push(List *list, DataNode data, int opcao)
{
    Node* node = (Node*) malloc(sizeof(Node));

    node->data = data;
    node->next = list[opcao].head;
    list[opcao].head = node;
    list[opcao].size ++;
}


void insert (List* list, DataNode data, int opcao)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;

    int index = -2;

    index = indexOf(list, node, opcao);

    if (index == 0)
    {
        push(list, data, opcao);
    }
    else
    {
        Node* nodeCurrent = atPos(list, index, opcao);

        if (nodeCurrent != NULL)
        {
            Node* nodePrevious = atPos(list, index -1, opcao);

            Node* newNode = (Node*) malloc (sizeof (Node));
            newNode->data = data;

            nodePrevious->next = newNode;
            newNode->next = nodeCurrent;
            list[opcao].size++;
        }
        else if (nodeCurrent == NULL)
        {
            Node* nodePrevious = atPos(list, index -1, opcao);

            Node* newNode = (Node*) malloc (sizeof (Node));
            newNode->data = data;

            nodePrevious->next = newNode;

            newNode->next = nodeCurrent;
        }
    }
    free(node);

}

/* OPCÃO 0 == COMPRA VALOR PAGO FOR MAIOR ASSUME A POSIÇÃO ...  OPÇÃO 1 == VENDA VALOR OFERTADO FOR MENOR RECEBE O INDICE */
int indexOf(List* list, Node* node, int opcao)
{
    int index = 0;

    if(opcao == 0)
    {
        if (list[opcao].head == NULL)
        {
            return 0;
        }
        else if (node != NULL)
        {
            Node* pointer = list[opcao].head;

            while (pointer != NULL)
            {
                if(node->data.valor > pointer->data.valor)
                {
                    break;
                }

                pointer = pointer->next;
                index++;
            }
        }
    }

    else if(opcao == 1)
    {
        if (list[opcao].head == NULL)
        {
            return 0;
        }
        else if (node != NULL)
        {
            Node* pointer = list[opcao].head;

            while (pointer != NULL)
            {
                if(node->data.valor < pointer->data.valor)
                {
                    break;
                }

                pointer = pointer->next;
                index++;
            }
        }
    }

    return index;
}


Node* atPos(List* list, int index, int opcao)
{
    if (index >= 0 && index < list[opcao].size++)
    {
        Node* node = list[opcao].head;

        int i;
        for (i = 0; i < index; i++)

            node = node->next;

        return node;
    }

    return NULL;
}



void imprimir(List *list, int opcao)
{
    if(isEmpty(list, opcao))
    {
        printf("\nLISTA VAZIA");
    }

    Node* pointer = list[opcao].head;

    while (pointer != NULL)
    {
        printf("\n%.2f  ", pointer->data.valor);
        printf("%d  ", pointer->data.qntd);
        printf("\n quebra ;)");
        pointer = pointer->next;
    }

    free(pointer);
    printf("\n");
}

