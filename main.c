#include <stdio.h>
#define QNTD 10

int main(void) 
{
  int icont;
  int kcont;
  int idade[QNTD];
  int somatorio=0;
  double media;

  for(icont=0;icont<QNTD;icont++)
  {
    scanf("%d", &idade[icont]);
    somatorio+=idade[icont];
  }
  
  media=somatorio/(QNTD*1.0);

  for(kcont=0;kcont<QNTD;kcont++)
    if(idade[kcont]>media)
      printf("%d ", idade[kcont]);
}
