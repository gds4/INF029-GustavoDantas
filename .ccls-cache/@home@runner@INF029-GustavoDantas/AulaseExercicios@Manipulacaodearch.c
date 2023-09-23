#include <stdio.h>

int main12gf(void){

    FILE *file;

    file = fopen("teste.txt","w");
    fprintf(file,"Pao com mortadela.");
    fclose(file);
 
    return 0;
}