#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char abrev[10];
    char nome[10];
    char **mus;
} Playlist;
int main()
{
    Playlist *play;
    play = (Playlist*)malloc(sizeof(Playlist));//cria espaço para 1 plalist
    play[0].mus = malloc(sizeof(char *) * 10); //maximo 10 Chars
    strcpy(play[0].mus, "variavel auxiar que recebe o valor do obter_substring");

    // paa alterares o tamanho do Play
    play = (Playlist*)realloc(play, sizeof(Playlist)*2);//aloca espaço para mais 1
}