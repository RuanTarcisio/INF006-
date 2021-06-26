#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

#include "Market_Head.h"


void menuGeral()
{
    char escolha;
    setbuf(stdin, NULL);
    system("cls");
    printf("\n\n       *********************** IFBA INVESTIMENTOS ***********************\n\n");
    printf("\n Digite: \n(1)- COMPRAR \n(2)- VENDER  \n(3)- OFERTAS ATUAIS \n(0)- SAIR:  ");
    printf("\n\n   ");
    escolha = getch();
    setbuf(stdin, NULL);


    switch(escolha)
    {
    case '0':
        printf("\n\nEncerrando o programa.");
        exit(0);
    case '1':
        menuCompras();
        break;
    case '2':
        menuVendas();
        break;
    case '3':
        menuListar();
    default:
        system("cls");
        setbuf(stdin, NULL);
        menuGeral();
        break;
    }
    menuGeral();
}


void menuCompras()
{
    int escolha, OK_Compra;
    DataNode *data;

    system("cls");
    printf("\n### Compra de Ações ###\n");
    printf("\n Selecione: \n(1)- LAME3 \n(2)- PETR4 \n(3)- VALE5  \n(9)- VOLTAR  \n(0)- SAIR  ");
    escolha = getch();

    if(escolha == '1')
    {
        data = RecebeDados();
        insert(LAME3, data, 0);

        OK_Compra = remover(LAME3, Compra);
    }

    else if(escolha == '2')
    {
        data = RecebeDados();
        insert(PETR4, data, 0);

        OK_Compra = remover(PETR4, Compra);
    }
    else if(escolha == '3')
    {
        data = RecebeDados();
        insert(VALE5, data, 0);

        OK_Compra = remover(VALE5, Compra);
    }
    else if(escolha == '9')
    {
        menuGeral();
    }
    else if(escolha == '0')
    {
        printf("\n\n Encerrando o programa. \n\n");
        system("exit");
    }
    else
        menuCompras();

    if(OK_Compra == 1)
    {
        printf("\n\n Ações compradas com sucesso. ");
    }
    else
        printf("\n\n Aguardando ações à venda. ");

    menuCompras();
}


void menuVendas()
{
int escolha, OK_Venda;
    DataNode *data;

    system("cls");
    printf("\n### Venda de Ações ###\n");
    printf("\n Selecione: \n(1)- LAME3 \n(2)- PETR4 \n(3)- VALE5 \n(9) p/ VOLTAR \n(0) p/ SAIR ");
    escolha = getch();

    if(escolha == '1')
    {
        data = RecebeDados();
        insert(LAME3, data, 1);

        OK_Venda = remover(LAME3, Venda);
    }

    else if(escolha == '2')
    {
        data = RecebeDados();
        insert(PETR4, data, 1);

        OK_Venda = remover(PETR4, Venda);
    }
    else if(escolha == '3')
    {
        data = RecebeDados();
        insert(VALE5, data, 1);

        OK_Venda = remover(VALE5, Venda);
    }
    else if(escolha == '9')
    {
        menuGeral();
    }
    else if(escolha == '0')
    {
        printf("\n\n Encerrando o programa. \n\n");
        system("exit");
    }
    else
        menuVendas();


    if(OK_Venda == 1)
    {
        printf("\n\n Ações vendidas com sucesso. ");
    }
    else
        printf("\n\n Aguardando compradores. ");

    menuVendas();
}


void menuListar()
{
    int escolha;

    system("cls");

    printf("\n\n Para visualizar selecione: \n(1)- LAME3 \n(2)- PETR4  \n(3)- VALE5 \n(9)- VOLTAR  \n(0)- SAIR ");
    escolha = getch();

    if(escolha == '1')
    {
        imprimir(LAME3);
    }
    else if(escolha == '2')
    {
        imprimir(PETR4);
    }
    else if(escolha == '3')
    {
        imprimir(VALE5);
    }
    else if(escolha == '9')
    {
        menuGeral();
    }
    else if(escolha == '0')
    {
        printf("\n\n Encerrando o programa. \n\n");
        system("exit");
    }

    menuListar();
}
