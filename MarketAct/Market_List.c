#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
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


DataNode *RecebeDados()
{
    DataNode *Dados = malloc(sizeof(DataNode));

    printf("\n Informe o preço R$: ");
    scanf("%f", &Dados->valor);
    printf("\n Informe quantas ações: ");
    scanf("%d", &Dados->qntd);
    Dados->valor_unidade = Dados->valor / Dados->qntd;

return Dados;
}


bool isEmpty (List* list, int opcao)
{
    return (list[opcao].size == 0);
}


void pop(List* list, int opcao)
{
    if (!isEmpty(list, opcao))
    {
        Node* pointer = list[opcao].head;

        list[opcao].head = pointer->next;
        free(pointer);
        list[opcao].size--;
    }

}


int remover(List* dados, int opcao)
{
    float valor_m;
    Node* cache = (Node*) malloc(sizeof(Node));
    cache = dados->head;


    if(dados[Compra].head == NULL)
    {
        return 0;
    }
    else if (dados[Venda].head == NULL)
    {
        return 0;
    }

    else if(cache[Compra].data.valor > cache[Venda].data.valor)
    {
        do
        {
            if(cache[Compra].data.qntd < cache[Venda].data.qntd)
            {
                valor_m = cache[Compra].data.valor_unidade  - ((cache[Compra].data.valor_unidade - cache[Venda].data.valor_unidade) / 2);
                cache[Venda].data.qntd -= cache[Compra].data.qntd;
                pop(dados, Compra);
                cache[Compra].data = cache[Compra].next[Compra].data;

                if(opcao == Compra)
                {
                    printf("\n\n Foram compradas %d ações, ao valor de R$%.2f", cache[Compra].data.qntd, (valor_m * cache[Compra].data.qntd));
                }
                else if(opcao == Venda)
                {
                    printf("\n\n Foram vendidas %d ações, ao valor de R$%.2f", cache[Compra].data.qntd, (valor_m * cache[Compra].data.qntd));
                }
            }

            else if(cache[Compra].data.qntd > cache[Venda].data.qntd)
            {
                valor_m = cache[Compra].data.valor_unidade  - ((cache[Compra].data.valor_unidade - cache[Venda].data.valor_unidade) / 2);
                cache[Compra].data.qntd -= cache[Venda].data.qntd;
                pop(dados, Venda);
                cache[Venda].data = cache[Venda].next[Venda].data;

                if(opcao == Compra)
                {
                    printf("\n\n Foram compradas %d ações, ao valor de R$%.2f", cache[Compra].data.qntd, (valor_m * cache[Venda].data.qntd));
                }
                else if(opcao == Venda)
                {
                    printf("\n\n Foram vendidas %d ações, ao valor de R$%.2f", cache[Compra].data.qntd, (valor_m * cache[Venda].data.qntd));
                }
            }
        }
        while(cache[Compra].data.valor > cache[Venda].data.valor);
        /*  1- SUBTRAIR A DIFERENÇA DE PREÇO E DIVIDIR POR 2
            2- VERIFICAR A QUANTIDADE, QUEM TIVER MENOS RECEBE POP
            3- VERIFICAR SE O PROXIMO É COMPATIVEL, CASO NÃO PERMANECER EM ESPERA.*/
    }
    system("pause");
    return 1;
}


void push(List *list, DataNode *data, int opcao)
{
    Node* node = (Node*) malloc(sizeof(Node));

    node->data = *data;
    node->next = list[opcao].head;
    list[opcao].head = node;
    list[opcao].size ++;
}


void insert (List* list, DataNode* data, int opcao)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = *data;

    int index = -2;

    index = indexOf(list, node, opcao);

    if (index == 0)
    {
        push(list, data, opcao);
    }
    else
    {
        Node* nodeCurrent = atPos(list, index, opcao);

        /*if (nodeCurrent != NULL)
        {*/
        Node* nodePrevious = atPos(list, index -1, opcao);

        Node* newNode = (Node*) malloc (sizeof (Node));
        newNode->data = *data;

        nodePrevious->next = newNode;
        newNode->next = nodeCurrent;
        list[opcao].size++;

        /*else if (nodeCurrent == NULL)
        {
            Node* nodePrevious = atPos(list, index -1, opcao);

            Node* newNode = (Node*) malloc (sizeof (Node));
            newNode->data = data;

            nodePrevious->next = newNode;

            newNode->next = nodeCurrent;
            list[opcao].size++;
        */
    }
    free(node);
}

/* OPCÃO 0 == COMPRA VALOR PAGO FOR MAIOR ASSUME A POSIÇÃO ...  OPÇÃO 1 == VENDA VALOR OFERTADO FOR MENOR RECEBE O INDICE */
int indexOf(List* list, Node* node, int opcao)
{
    int index = 0;

    if(opcao == Compra)
    {
        if (list[Compra].head == NULL)
        {
            return 0;
        }
        else if (node != NULL)
        {
            Node* pointer = list[Compra].head;

            while (pointer != NULL)
            {
                if(node->data.valor_unidade > pointer->data.valor_unidade)
                {
                    break;
                }

                pointer = pointer->next;
                index++;
            }
        }
    }

    else if(opcao == Venda)
    {
        if (list[Venda].head == NULL)
        {
            return 0;
        }
        else if (node != NULL)
        {
            Node* pointer = list[Venda].head;

            while (pointer != NULL)
            {
                if(node->data.valor_unidade < pointer->data.valor_unidade)
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



void imprimir(List *list)
{
    printf("\n|-----------------------------------------------------------------------|");
    printf("\n                AÇÕES DISPONIVEIS PARA COMPRAR. ");
    printf("\n|-----------------------------------------------------------------------|");

    if(isEmpty(list, Compra))
    {
        printf("\n\nLISTA VAZIA");
    }
    printf("\n\n\n");
    Node* pointer = list[Compra].head;

    while (pointer != NULL)
    {
        printf("\n%.2f  ", pointer->data.valor);
        printf("%d  ", pointer->data.qntd);
        printf("\n quebra ;)");
        pointer = pointer->next;
    }
    free(pointer);
printf("\n|-----------------------------------------------------------------------|");
printf("\n                 AÇÕES DISPONIVEIS PARA VENDER. ");
printf("\n|-----------------------------------------------------------------------|");

    if(isEmpty(list, Venda))
    {
        printf("\n\nLISTA VAZIA");
    }
    printf("\n\n\n");
    Node* _pointer = list[Venda].head;

    while (_pointer != NULL)
    {
        printf("\n%.2f  ", _pointer->data.valor);
        printf("%d  ", _pointer->data.qntd);
        printf("\n quebra ;)");
        _pointer = _pointer->next;
    }

    free(_pointer);
    printf("\n\n\n\n");
    system("pause");
}
