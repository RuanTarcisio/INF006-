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


    char qntd[8], valor[11];
    int validador = 1;
    system("cls");
    setbuf(stdin, NULL);
    printf("\n\n\n Informe quantas ações deseja: ");
    fgets(qntd, 8, stdin);
    qntd[strlen(qntd)-1] = '\0';
    setbuf(stdin, NULL);
    printf("\n Informe o preço R$: ");
    fgets(valor, 11, stdin);
    valor[strlen(valor)-1] = '\0';
    setbuf(stdin, NULL);

    for(int ndx = 0; ndx < strlen(qntd); ndx++)
    {
        if(!isdigit(qntd[ndx]))
        {
            validador = 0;
        }
    }

    for(int ndx = 0; ndx < strlen(valor); ndx++)
    {
        int ponto = 0;

        if(valor[ndx] == '.')
        {
            ponto++;

            if(ponto > 1)
            {
                validador = 0;
                break;
            }

        }

        if(!isdigit(valor[ndx]) && valor[ndx] != '.')
        {
            validador = 0;
            break;
        }
    }

    if(validador == 1)
    {
        Dados->valor = atof(valor);
        Dados->qntd = atoi(qntd);
    }
    else
    {
        printf("\n Algum valor invalido. \n");
        getch();
        return NULL;
    }

    Dados->valor_unidade = Dados->valor / Dados->qntd;

    if(Dados->valor_unidade < 0.50 || Dados->qntd < 1 || Dados->valor < 1)
    {
        printf("\n Algum valor invalido. \n");
        getch();
        return NULL;
    }


    printf("\n Valor unidade R$%.2f \n", Dados->valor_unidade);
    getch();

    return Dados;
}



bool isEmpty (List* list, int opcao)
{
    return (list[opcao].size == 0);
}


void push(List *list, DataNode* data, int opcao)
{
    Node* node = (Node*) malloc(sizeof(Node));

    node->data = *data;
    node->next = list[opcao].head;
    list[opcao].head = node;
    list[opcao].size ++;
}


void insert (List* list, DataNode *data, int opcao)
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

        if (nodeCurrent != NULL)
        {
            Node* nodePrevious = atPos(list, index -1, opcao);

            Node* newNode = (Node*) malloc (sizeof (Node));
            newNode->data = *data;

            nodePrevious->next = newNode;
            newNode->next = nodeCurrent;
            list[opcao].size++;
        }
        else if (nodeCurrent == NULL)
        {
            Node* nodePrevious = atPos(list, index -1, opcao);

            Node* newNode = (Node*) malloc (sizeof (Node));
            newNode->data = *data;

            nodePrevious->next = newNode;

            newNode->next = nodeCurrent;
        }
    }
    free(node);

}


void pop(List* list, int opcao)
{
    if(opcao == Compra)
    {
        if (!isEmpty(list, Compra))
        {
            Node* pointer = list[Compra].head;

            list[Compra].head = pointer->next;
            free(pointer);
            list[Compra].size--;
        }
    }
    else if(opcao == Venda)
    {
        if (!isEmpty(list, Venda))
        {
            Node* pointer = list[Venda].head;

            list[Venda].head = pointer->next;
            free(pointer);
            list[Venda].size--;
        }
    }
}


int remover(List* list)
{
    float valor_m;
    Node* buy = (Node*) malloc(sizeof(Node));
    Node* sell = (Node*) malloc(sizeof(Node));
    buy = list[Compra].head;
    sell = list[Venda].head;

    if(sell == NULL)
    {
        return 0;
    }
    else if(buy == NULL)
    {
        return 0;
    }

/*    if(opcao == Venda)
    {*/
        if(buy->data.valor_unidade >= sell->data.valor_unidade)
        {

            while(buy != NULL && sell != NULL)
            {
                if(buy->data.valor_unidade < sell->data.valor_unidade)
                {
                    printf("\n TO AQ 0");
                    break;
                }

                if(buy->data.qntd < sell->data.qntd)
                {
                    printf("\n TO AQ 1");
                    sell->data.qntd -= buy->data.qntd;
                    sell->data.valor = sell->data.qntd * sell->data.valor_unidade;
                    buy = buy->next;
                    pop(list, Compra);
                }

                else if(buy->data.qntd > sell->data.qntd)
                {
                    printf("\n TO AQ 2");
                    buy->data.qntd -= sell->data.qntd;
                    buy->data.valor = buy->data.qntd * buy->data.valor_unidade;
                    sell = sell->next;
                    pop(list, Venda);
                }

                else if(buy->data.qntd == sell->data.qntd)
                {
                    buy = buy->next;
                    sell = sell->next;
                    pop(list, Compra);
                    pop(list, Venda);

                }
            }

            return 1;
        }
/*    }

    else if(opcao == Compra)
    {
        if(sell->data.valor_unidade <= buy->data.valor_unidade)
        {

            while(buy != NULL && sell != NULL)
            {
                if(sell->data.valor_unidade > buy->data.valor_unidade)
                {
                    break;
                }

                if(sell->data.qntd < buy->data.qntd)
                {
                    printf("\nto aq 0\n");
                    buy->data.qntd -= sell->data.qntd;
                    pop(list, Venda);
                    break;
                }

                else if(sell->data.qntd > buy->data.qntd)
                {
                    printf("\nto aq 1\n");
                    sell->data.qntd -= buy->data.qntd;
                    pop(list, Compra);
                    break;
                }

                else if(sell->data.qntd == buy->data.qntd)
                {
                    printf("\nto aq 2\n");
                    pop(list, Compra);
                    pop(list, Venda);
                    break;
                }
            }

            return 1;
        }
    }*/

    return 0;
}

/* OPCÃO 0 == COMPRA VALOR PAGO FOR MAIOR ASSUME A POSIÇÃO ...  OPÇÃO 1 == VENDA VALOR OFERTADO FOR MENOR RECEBE O INDICE */
int indexOf(List* list, Node* node, int opcao)
{
    int index = 0;

    if(opcao == Compra)
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
        if (list[opcao].head == NULL)
        {
            return 0;
        }
        else if (node != NULL)
        {
            Node* pointer = list[opcao].head;

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
    printf("\n|                AÇÕES DISPONIVEIS PARA COMPRAR.                        |");
    printf("\n|-----------------------------------------------------------------------|");

    if(isEmpty(list, Compra))
    {
        printf("\n\nLISTA VAZIA");
    }
    printf("\n\n\n");
    Node* pointer;

    for(pointer = list[Compra].head; pointer != NULL; pointer = pointer->next)
    {
        printf("\nR$%.2f  ", pointer->data.valor);
        printf("\n%d Ações ", pointer->data.qntd);
        printf("\n R$%.5f  unidade ", pointer->data.valor_unidade);
        printf("\n ");

    }
    free(pointer);
printf("\n|-----------------------------------------------------------------------|");
printf("\n|                AÇÕES DISPONIVEIS PARA VENDER.                         |");
printf("\n|-----------------------------------------------------------------------|");

    if(isEmpty(list, Venda))
    {
        printf("\n\nLISTA VAZIA");
    }
    printf("\n\n\n");
    Node* _pointer;

    for(_pointer = list[Venda].head; _pointer != NULL; _pointer = _pointer->next)
    {
        printf("\nR$%.2f  ", _pointer->data.valor);
        printf("\n%d Ações ", _pointer->data.qntd);
        printf("\n R$%.5f  unidade ", _pointer->data.valor_unidade);
        printf("\n ");
    }

    free(_pointer);
    printf("\n\n\n\n");
    system("pause");
}
