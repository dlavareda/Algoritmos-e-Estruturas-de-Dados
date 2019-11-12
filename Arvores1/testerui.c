#include <stdio.h>
void clean_stdin()
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
int main()
{
    char c;
    while ((c = getchar()) != EOF)
    {
        putchar(c);
        fflush(stdin);
        if (c == ' ')
        {
            printf("Carregaste no Espaço CARALHO");
        }
    }
}