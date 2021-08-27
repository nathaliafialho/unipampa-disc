#include <stdio.h>
#include <stdlib.h>

int main () {
  void *pp; 
  int *p1, p2 = 10;

  p1 = &p2;

  pp = &p2; // endereço de int
  printf("Endereco em pp: %p \n", pp);
  pp=&p1; // end de int*
  printf("Endereco em pp: %p \n", pp);
  pp=p1; // end de int 
  printf("Endereco em pp: %p \n", pp);

system("pause");
return 0;
}