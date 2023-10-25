#include <stdio.h>

#define red_text "\x1b[31m"
#define reset_color "\x1b[0m"



int main(void){
   
   char nome[] = red_text "Respostas invalida, tente novamente.\n" reset_color;

   puts(nome);

    return 0;
}