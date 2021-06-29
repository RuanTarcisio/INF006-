#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

#include "Market_Head.h"

int main()
{
    setlocale( LC_ALL, "" );
    inicializar();
    menuGeral();

    return 0;
}
