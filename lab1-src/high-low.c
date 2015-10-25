#include <stdio.h>
//

int main(int argc, char **argv) {
  char cont;
  printf("Welcome to the High Low game...\n");
  while(1)
  {
  printf("Think of a number between 1 and 100 and press <enter> \n");
  getchar();//this is used to take in the character input (in this case the \n and do nothing with it)
  int low = 1;
  int high = 100;
  int mid = (low + high) / 2;
  while(high >= low)
  {
  printf("Is it higher than %d? (y/n)\n", mid);
  char answer = getchar();
  getchar();
  if (answer == 'y')
  {
  low = mid + 1;
  mid = (high + low) / 2;
  continue;
  }
  else if (answer == 'n')
  {
  high = mid - 1;
  mid = (high + low) / 2;
  continue;
  }
  else 
  {
  printf("Type y or n\n");
  continue;
  }
  }
  printf("\n>>>>>> The number is %d\n", mid+1);
  printf("\nDo you want to continue playing (y/n)?");
  cont = getchar();
  getchar();
  if (cont == 'n')
  {
  printf("Thanks for playing!!!\n");
  break;
  }
  continue;
  // Write your implementation here...
return 0;
}
}

