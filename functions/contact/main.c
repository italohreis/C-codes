#include <stdio.h>
#include <string.h>
#include "functions.h"

#define red_text "\x1b[31m"
#define green_text "\x1b[32m"
#define reset_color "\x1b[0m"


/* Crie um programa em C para gerenciar uma agenda de contatos. O programa deve permitir:

Adicionar contatos (cada contato terá um nome, telefone e email).
Buscar contatos pelo nome.
Excluir contatos.
editar contatos.

Listar todos os contatos da agenda. */

typedef struct{
    char name[30];
    int number;
    char email[50];

}contact;
    contact contacts[100];


int main(void){

    int cContacts = 0;

    printf("\n* Agenda de contatos *\n\n");

    while(1){

        int resp;
        printf("\n\n\nO que deseja fazer ?\n");
        printf("\n 1 - Adicionar contato.\n 2 - Editar contato.\n 3 - Excluir contato.\n 4 - Consultar contato por nome.\n "
                "5 - Listar todos os contatos.\n 6 - Finalizar.\n");
        scanf("%d", &resp);


        switch(resp){

            case 1:

                AddContact(&cContacts);
                break;
                
            case 2:

                EditContact(&cContacts);
                break;

            case 3:

                DeleteContact(&cContacts);
                break;

            case 4:

                ConsultContact(&cContacts);
                break;

            case 5:

                ConsultAllContacts(&cContacts);
                break;


            case 6:
                printf("\n\nFim.\n\n");
                return 0;

            default:
                printf(red_text "\nResposta invalida, tente novamente.\n" reset_color);

        }
    }

    return 0;
}


