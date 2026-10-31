#include <stdio.h>

int main() {
  char cadena[] = "hola mundo";
  puts(cadena);
  printf("%s\n", cadena);

  char entrada[10];
  //scanf("%s", entrada);

  fgets(entrada, 11, stdin);

  puts(entrada);

  for (int i = 0; i < 10; i++) {
    putchar(entrada[i]);
  }
  return 0;
}
