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
            menuCompras();
        }
        else
            insert(LAME3, data, Compra);

        remover(LAME3);

        ArqSalvar(LAME3, LAME3_, Compra);
    }
    else if(escolha == '2')
    {
        data = RecebeDados();

        if(data == NULL)
        {
            getch();
            menuCompras();
        }
        else
            insert(PETR4, data, Compra);

        remover(PETR4);

        ArqSalvar(PETR4, PETR4_, Compra);
    }
    else if(escolha == '3')
    {
        data = RecebeDados();

        if(data == NULL)
        {
            getch();
            menuCompras();
        }
        else
            insert(ITSA4, data, Compra);

        remover(ITSA4);

        ArqSalvar(ITSA4, ITSA4_, Compra);
    }
    else if(escolha == '4')
    {
        data = RecebeDados();

        if(data == NULL)
        {
            getch();
            menuCompras();
        }
        else
            insert(VALE5, data, Compra);

        remover(VALE5);

        ArqSalvar(VALE5, VALE5_, Compra);
    }
    else if(escolha == '5')
    {
        data = RecebeDados();

        if(data == NULL)
        {
            getch();
            menuCompras();
        }
        else
            insert(USIM5, data, Compra);

        remover(USIM5);

        ArqSalvar(USIM5, USIM5_, Compra);
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
    int escolha;
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

        ArqSalvar(LAME3, LAME3_, Venda);
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

        ArqSalvar(PETR4, PETR4_, Venda);
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

        ArqSalvar(ITSA4, ITSA4_, Venda);
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

        ArqSalvar(VALE5,VALE5_, Venda);
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

        ArqSalvar(USIM5, USIM5_, Venda);
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
    escolha = getche();
    getch();

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


void ArqSalvar(List *list, int tittle, int opcao)
{
    Node* cache;
    FILE *Comprar, *Vender;

    if(tittle == LAME3_)
    {
        Comprar = fopen("LAME3_C.txt", "w");
        if(!Comprar)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
        Vender = fopen("LAME3_V.txt", "w");
        if(!Vender)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
    }
    else if(tittle == PETR4_)
    {
        Comprar = fopen("PETR4_C.txt", "w");
        if(!Comprar)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
        Vender = fopen("PETR4_V.txt", "w");
        if(!Vender)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
    }
    else if(tittle == ITSA4_)
    {
        Comprar = fopen("ITSA4_C.txt", "w");
        if(!Comprar)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
        Vender = fopen("ITSA4_V.txt", "w");
        if(!Vender)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
    }
    else if(tittle == VALE5_)
    {
        Comprar = fopen("VALE5_C.txt", "w");
        if(!Comprar)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
        Vender = fopen("VALE5_V.txt", "w");
        if(!Vender)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
    }
    else if(tittle == USIM5_)
    {
        Comprar = fopen("USIM5_C.txt", "w");
        if(!Comprar)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
        Vender = fopen("USIM5_V.txt", "w");
        if(!Vender)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
    }

    for(cache = list[Compra].head; cache != NULL; cache = cache->next)
    {
        fprintf(Comprar, "%d  %f  %f    ", cache->data.qntd, cache->data.valor, cache->data.valor_unidade);
    }
    fclose(Comprar);

    for(cache = list[Venda].head; cache != NULL; cache = cache->next)
    {
        fprintf(Vender, "%d  %f  %f    ", cache->data.qntd, cache->data.valor, cache->data.valor_unidade);
    }
    fclose(Vender);


}


List *ler_Arq(int tittle)
{
    DataNode cache;
    List *lista = Create_List();
    FILE *Comprar, *Vender;

    if(tittle == LAME3_)
    {
        Comprar = fopen("LAME3_C.txt", "r");
        if(!Comprar)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
        Vender = fopen("LAME3_V.txt", "r");
        if(!Vender)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
    }
    else if(tittle == PETR4_)
    {
        Comprar = fopen("PETR4_C.txt", "r");
        if(!Comprar)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
        Vender = fopen("PETR4_V.txt", "r");
        if(!Vender)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
    }
    else if(tittle == ITSA4_)
    {
        Comprar = fopen("ITSA4_C.txt", "r");
        if(!Comprar)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
        Vender = fopen("ITSA4_V.txt", "r");
        if(!Vender)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
    }
    else if(tittle == VALE5_)
    {
        Comprar = fopen("VALE5_C.txt", "r");
        if(!Comprar)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
        Vender = fopen("VALE5_V.txt", "r");
        if(!Vender)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
    }
    else if(tittle == USIM5_)
    {
        Comprar = fopen("USIM5_C.txt", "r");
        if(!Comprar)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
        Vender = fopen("USIM5_V.txt", "r");
        if(!Vender)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }
    }
    cache.qntd = 0;
    cache.valor = 0;
    cache.valor_unidade = 0;
    insert(lista, &cache, Compra);
    while (!feof(Comprar))
    {
        /* fscanf(arq,"%s  %s", &texto, &data.nome);*/
        fscanf(Comprar, "%d  %f  %f  ", &cache.qntd, &cache.valor, &cache.valor_unidade);
        if(cache.qntd != 0 && cache.valor != 0 && cache.valor_unidade != 0)
        {
            insert(lista, &cache, Compra);
        }
    }
    fclose(Comprar);

    cache.qntd = 0;
    cache.valor = 0;
    cache.valor_unidade = 0;
    insert(lista, &cache, Venda);
    while (!feof(Vender))
    {
        /* fscanf(arq,"%s  %s", &texto, &data.nome);*/
        fscanf(Vender, "%d  %f  %f  ", &cache.qntd, &cache.valor, &cache.valor_unidade);
        if(cache.qntd != 0 && cache.valor != 0 && cache.valor_unidade != 0)
        {
            insert(lista, &cache, Venda);
        }
    }

    fclose(Vender);
    /*}
    else if(titulo == USIM5_)
    {
        FILE *arqC = fopen("USIM5_Compra.txt", "r");
        if(!arqC)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }

        while (!feof(arqC))
        {

            fscanf(arqC, "%d  %f  %f  ", &cache.qntd, &cache.valor, &cache.valor_unidade);
            if(cache.qntd != 0)
            {
                insert(lista, &cache, Compra);
            }
        }
        fclose(arqC);

        FILE *arqV = fopen("USIM5_Venda.txt", "r");
        if(!arqV)
        {
            printf("\n ERROR FILE  \n");
            getch();
            exit(0);
        }

        while (!feof(arqV))
        {

            fscanf(arqV, "%d  %f  %f  ", &cache.qntd, &cache.valor, &cache.valor_unidade);
            if(cache.qntd != 0)
            {
                insert(lista, &cache, Venda);
            }
        }
        fclose(arqV);
    }*/
    return lista;
}
