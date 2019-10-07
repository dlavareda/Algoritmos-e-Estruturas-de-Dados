#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia, mes, ano;
} Data;
int compare_dates(Data d1, Data d2)
{
    if (d1.ano < d2.ano)
        return -1;

    else if (d1.ano > d2.ano)
        return 1;

    if (d1.ano == d2.ano)
    {
        if (d1.mes < d2.mes)
            return -1;
        else if (d1.mes > d2.mes)
            return 1;
        else if (d1.dia < d2.dia)
            return -1;
        else if (d1.dia > d2.dia)
            return 1;
        else
            return 0;
    }
}
int main()
{

    Data nascimento;
    Data now;
    now.ano = 2019;
    now.dia = 07;
    now.mes = 10;
    nascimento.ano = 1991;
    nascimento.dia = 8;
    nascimento.mes = 10;
    int anotmp = nascimento.ano;
    nascimento.ano = 2019;
    int resultado = compare_dates(nascimento, now);
    printf("%d", resultado);
    nascimento.ano = anotmp;
    if (resultado == -1 || resultado == 0)
    {
        printf("Tens %d anos\n", now.ano-nascimento.ano);
    }else
    {
        printf("Tens %d anos\n", (now.ano-nascimento.ano)-1);
    }

}