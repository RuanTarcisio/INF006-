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
    int escolha;
    DataNode *data;
    setbuf(stdin, NULL);
    system("cls");
    printf("\n### Compra de Ações ###\n");
    printf("\n Selecione: \n\n(1)- LAME3 \n(2)- PETR4 \n(3)- ITSA4 \n(4)- VALE5 \n(5)- USIM5 \n(9)- p/ VOLTAR \n(0)- p/ SAIR ");
    escolha = getch();

    if(escolha == '1')
    {
        data = RecebeDados();
        if(data == NULL)
        {
            getch();
            menuVendas();
        }
        else
            insert(LAME3, data, Compra);

        remover(LAME3);
    }

    else if(escolha == '2')
    {
        data = RecebeDados();

        if(data == NULL)
        {
            getch();
            menuVendas();
        }
        else
            insert(PETR4, data, Compra);

        remover(PETR4);
        /*OK_Venda = remover(PETR4, Venda);*/
    }
    else if(escolha == '3')
    {
        data = RecebeDados();

        if(data == NULL)
        {
            getch();
            menuVendas();
        }
        else
            insert(ITSA4, data, Compra);

        remover(ITSA4);
        /*OK_Venda = remover(VALE5, Venda);*/
    }
    else if(escolha == '4')
    {
        data = RecebeDados();

        if(data == NULL)
        {
            getch();
            menuVendas();
        }
        else
            insert(VALE5, data, Compra);

        remover(VALE5);
        /*OK_Venda = remover(VALE5, Venda);*/
    }
    else if(escolha == '5')
    {
        data = RecebeDados();

        if(data == NULL)
        {
            getch();
            menuVendas();
        }
        else
            insert(USIM5, data, Compra);

        remover(USIM5);
        /*OK_Venda = remover(VALE5, Venda);*/
    }
    else if(escolha == '9')
    {
        menuGeral();
    }
    else if(escolha == '0')
    {
        printf("\n\n Encerrando o programa. \n\n");
        exit(1);
    }
    else
        menuCompras();

    /*if(OK_Compra == 1)
    {
        printf("\n\n Ações compradas com sucesso. ");
    }
    else
        printf("\n\n Aguardando ações à venda. ");
    */
    system("pause");

    menuCompras();
}


void menuVendas()
{
    int escolha, OK_Venda;
    DataNode *data;
    setbuf(stdin, NULL);
    system("cls");
    printf("\n### Venda de Ações ###\n");
    printf("\n Selecione: \n\n(1)- LAME3 \n(2)- PETR4 \n(3)- ITSA4 \n(4)- VALE5 \n(5)- USIM5 \n(9)- p/ VOLTAR \n(0)- p/ SAIR ");
    escolha = getch();

    if(escolha == '1')
    {
        data = RecebeDados();
        if(data == NULL)
        {
            getch();
            menuVendas();
        }
        else
            insert(LAME3, data, Venda);

        remover(LAME3);
    }

    else if(escolha == '2')
    {
        data = RecebeDados();

        if(data == NULL)
        {
            getch();
            menuVendas();
        }
        else
            insert(PETR4, data, Venda);

        remover(PETR4);
        /*OK_Venda = remover(PETR4, Venda);*/
    }
    else if(escolha == '3')
    {
        data = RecebeDados();

        if(data == NULL)
        {
            getch();
            menuVendas();
        }
        else
            insert(ITSA4, data, Venda);

        remover(ITSA4);
        /*OK_Venda = remover(VALE5, Venda);*/
    }
    else if(escolha == '4')
    {
        data = RecebeDados();

        if(data == NULL)
        {
            getch();
            menuVendas();
        }
        else
            insert(VALE5, data, Venda);

        remover(VALE5);
        /*OK_Venda = remover(VALE5, Venda);*/
    }
    else if(escolha == '5')
    {
        data = RecebeDados();

        if(data == NULL)
        {
            getch();
            menuVendas();
        }
        else
            insert(USIM5, data, Venda);

        remover(USIM5);
        /*OK_Venda = remover(VALE5, Venda);*/
    }
    else if(escolha == '9')
    {
        menuGeral();
    }
    else if(escolha == '0')
    {
        printf("\n\n Encerrando o programa. \n\n");
        exit(1);
    }
    else
        menuVendas();


    /*if(OK_Venda == 1)
    {
        printf("\n\n Ações vendidas com sucesso. ");
    }
    else
        printf("\n\n Aguardando compradores. ");*/
    system("pause");
    menuVendas();
}


void menuListar()
{
    int escolha;

    system("cls");

    printf("\n\n Para visualizar selecione: \n(1)- LAME3 \n(2)- PETR4  \n(3)- ITSA4 \n(4)- VALE5 \n(5)- USIM5 \n(9)- p/ VOLTAR  \n(0)- p/ SAIR ");
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
        imprimir(ITSA4);
    }
    else if(escolha == '4')
    {
        imprimir(VALE5);
    }
     else if(escolha == '5')
    {
        imprimir(USIM5);
    }
    else if(escolha == '9')
    {
        menuGeral();
    }
    else if(escolha == '0')
    {
        printf("\n\n Encerrando o programa. \n\n");
        exit(1);
    }

    menuListar();
}
