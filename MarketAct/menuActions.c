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

        ArqSalvar(LAME3, LAME3_, Compra); imprimir(LAME3);
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

        ArqSalvar(PETR4, PETR4_, Compra);
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

        ArqSalvar(ITSA4, ITSA4_, Compra);
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

        ArqSalvar(VALE5, VALE5_, Compra);
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


void ArqSalvar(List *list, int tittle, int opcao)
{
    Node* cache;
    FILE *Comprar, *Vender;

    if (tittle == LAME3_)
    {
        Comprar = fopen("LAME3_Compra.txt", "w");
        if(Comprar != NULL){
        printf("\n OK 0 \n");}

        fprintf(Comprar, "    AÇÕES PARA COMPRAR < LAME3 >  \n");
        for(cache = list[Compra].head; cache != NULL; cache = cache->next)
        {
            fprintf(Comprar, "\n\n Quantidade: %d ", cache->data.qntd);
            fprintf(Comprar, "\n Preço: %.2f ", cache->data.valor);
            fprintf(Comprar, "\n Preço unidade: %.5f \n", cache->data.valor_unidade);
        }
        fclose(Comprar);

        Vender = fopen("LAME3_Venda.txt", "w");
        if(Vender != NULL){
        printf("\n OK 0 \n");
        }

        fprintf(Vender, "    AÇÕES PARA VENDER < LAME3 >  \n");
        for(cache = list[Venda].head; cache != NULL; cache = cache->next)
        {
            fprintf(Vender, "\n\n Quantidade: %d ", cache->data.qntd);
            fprintf(Vender, "\n Preço: %.2f ", cache->data.valor);
            fprintf(Vender, "\n Preço unidade: %.5f \n", cache->data.valor_unidade);
        }
        fclose(Vender);
    }

    else if (tittle == PETR4_)
    {
        Comprar = fopen("PETR4_Compra.txt", "w");
        if(Comprar != NULL){
        printf("\n OK 0 \n");}

        fprintf(Comprar, "    AÇÕES PARA COMPRAR < PETR4 >  \n");
        for(cache = list[Compra].head; cache != NULL; cache = cache->next)
        {
            fprintf(Comprar, "\n\n Quantidade: %d ", cache->data.qntd);
            fprintf(Comprar, "\n Preço: %.2f ", cache->data.valor);
            fprintf(Comprar, "\n Preço unidade: %.5f \n", cache->data.valor_unidade);
        }
        fclose(Comprar);

        Vender = fopen("PETR4_Venda.txt", "w");
        if(Vender != NULL){
        printf("\n OK 0 \n");}

        fprintf(Vender, "    AÇÕES PARA VENDER < PETR4 >  \n");
        for(cache = list[Venda].head; cache != NULL; cache = cache->next)
        {
            fwrite(&cache->data, sizeof(Node*), 1, Vender);
        }
        fclose(Vender);
    }

    else if (tittle == ITSA4_)
    {
        Comprar = fopen("ITSA4_Compra.txt", "w");
        if(Comprar != NULL){
        printf("\n OK 0 \n");}

        fprintf(Comprar, "    AÇÕES PARA COMPRAR < ITSA4 >  \n");
        for(cache = list[Compra].head; cache != NULL; cache = cache->next)
        {
            fprintf(Comprar, "\n\n Quantidade: %d ", cache->data.qntd);
            fprintf(Comprar, "\n Preço: %.2f ", cache->data.valor);
            fprintf(Comprar, "\n Preço unidade: %.5f \n", cache->data.valor_unidade);
        }
        fclose(Comprar);

        Vender = fopen("ITSA4_Venda.txt", "w");
        if(Vender != NULL){
        printf("\n OK 0 \n");}

        fprintf(Vender, "    AÇÕES PARA VENDER < ITSA4 >  \n");
        for(cache = list[Venda].head; cache != NULL; cache = cache->next)
        {
            fwrite(&cache->data, sizeof(Node*), 1, Vender);
        }
        fclose(Vender);
    }

    else if (tittle == VALE5_)
    {
        Comprar = fopen("VALE5_Compra.txt", "w");

        fprintf(Comprar, "    AÇÕES PARA COMPRAR < VALE5 >  \n");
        for(cache = list[Compra].head; cache != NULL; cache = cache->next)
        {
            fprintf(Comprar, "\n\n Quantidade: %d ", cache->data.qntd);
            fprintf(Comprar, "\n Preço: %.2f ", cache->data.valor);
            fprintf(Comprar, "\n Preço unidade: %.5f \n", cache->data.valor_unidade);
        }
        fclose(Comprar);

        Vender = fopen("VALE5_Venda.txt", "w");

        fprintf(Vender, "    AÇÕES PARA VENDER < VALE5 >  \n");
        for(cache = list[Venda].head; cache != NULL; cache = cache->next)
        {
            fwrite(&cache->data, sizeof(Node*), 1, Vender);
        }
        fclose(Vender);
    }

    else if (tittle == USIM5_)
    {

        Comprar = fopen("USIM5_Compra.txt", "w");

        fprintf(Comprar, "    AÇÕES PARA COMPRAR < USIM5 >  \n");
        for(cache = list[Compra].head; cache != NULL; cache = cache->next)
        {
            fprintf(Comprar, "\n\n Quantidade: %d ", cache->data.qntd);
            fprintf(Comprar, "\n Preço: %.2f ", cache->data.valor);
            fprintf(Comprar, "\n Preço unidade: %.5f \n", cache->data.valor_unidade);
        }
        fclose(Comprar);

        Vender = fopen("USIM5_Venda.txt", "w");

        fprintf(Vender, "    AÇÕES PARA COMPRAR < USIM5 >  \n");
        for(cache = list[Venda].head; cache != NULL; cache = cache->next)
        {
            fprintf(Vender, "\n\n Quantidade: %d ", cache->data.qntd);
            fprintf(Vender, "\n Preço: %.2f ", cache->data.valor);
            fprintf(Vender, "\n Preço unidade: %.5f \n", cache->data.valor_unidade);
        }
        fclose(Vender);
    }
}
