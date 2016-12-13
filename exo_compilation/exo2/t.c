#include <stdlib.h>
#include <stdio.h>

int main() 
{
    int x = 3;
    int y = 4;
    int* ptr = malloc(sizeof(int));
    int tab[2];

    printf("adresse de x = %p, y = %p, ptr = %p, tab[0]:%p, tab[1]:%p\n", &x, &y, ptr, &tab[0], &tab[1]);
    
    free(ptr);

    return 0;
}
