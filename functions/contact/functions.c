#include <stdio.h>
#include <string.h>
#include "functions.h"


#define red_text "\x1b[31m"
#define green_text "\x1b[32m"
#define reset_color "\x1b[0m"

typedef struct{
    char name[30];
    int number;
    char email[50];

}contact;
    contact contacts[100];
    

void AddContact(int *cContacts){
    char name[30];
    int number;
    char email[50];

    printf("\n\tQual o telefone do contato ? --> ");
    scanf("%d", &number);

    int i;
    for(i = 0; i < *cContacts; i++){        //verifica se o contato ja existe.

        if(number == contacts[i].number){
            printf(red_text "\n\tContato ja existente, tente novamente.\n" reset_color);
            return;
        }
    }

    printf("\n\tQual o nome do contato ? --> ");
    scanf(" %s", &name);

    printf("\n\tQual email do contato ? --> ");
    scanf("%s", &email);

    strcpy(contacts[i].name, name);
    strcpy(contacts[i].email, email);
    contacts[i].number = number;

    *cContacts += 1;

    printf(green_text "\n\tContato adicionado com sucesso!\n" reset_color);

    return;  
}

void EditContact(int *cContacts){
    char name[30];
    int number;
    char email[50];

    int op;
    printf("\n\tDigite o telefone do contato que deseja editar --> ");
    scanf("%d", &number);

    int i;
    for(i = 0; i < *cContacts; i++){
            
        if(number == contacts[i].number){
                
            int edit;
            do{

                printf("\n\tInforme o que deseja editar.\n");
                printf("\t1 - nome.\n \t2 - telefone.\n \t3 - email.\n");
                scanf("%d", &edit);

                switch(edit){
                    case 1:
                        printf("\n\tNome do contato --> %s\n", contacts[i].name);

                        printf("\n\tDigite o novo nome a ser alterado --> ");
                        scanf("%s", &name);

                        strcpy(contacts[i].name, name);

                        printf(green_text "\n\tNome alterado com sucesso!\n" reset_color);

                        break;

                    case 2:
                        printf("\n\tTelefone do contato --> %d", contacts[i].number);

                        printf("\n\tDigite o novo telefone a ser alterado --> ");
                        scanf("%d", &number);

                        contacts[i].number = number;

                        printf(green_text "\n\tTelefone alterado com sucesso!\n" reset_color);
                        break;

                    case 3:
                        printf("\n\tEmail do contato --> %s", contacts[i].email);

                        printf("\n\tDigite o novo email a ser alterado --> ");
                        scanf("%s", &email);

                        strcpy(contacts[i].email, email);

                        printf(green_text "\n\tEmail alterado com sucesso!\n" reset_color);
                        break;

                    default:
                        printf(red_text "\nResposta invalida, tente novamente.\n" reset_color);
                }

                op = -1;
                while(op != 0 && op != 1){
                    printf("\n\tDeseja editar algo mais nesse contato ? (1 - sim / 0 - nao)--> ");
                    scanf("%d", &op);

                    if(op != 0 && op != 1){
                        printf(red_text "\nResposta invalida, tente novamente.\n" reset_color);
                    }
                }

                if(op == 0){
                    return;
                }

            } while(op == 1);
        }

    }    

    printf(red_text "\n\tContato nao encontrado." reset_color);  
    return;  
}


void DeleteContact(int *cContacts){
    int number;

    printf("\n\tInforme o telefone do contato que deseja deletar --> ");
    scanf("%d", &number);

    int i;
    for(i = 0; i < *cContacts; i++){
        
        if(number == contacts[i].number){

            strcpy(contacts[i].name, "");
            strcpy(contacts[i].email, "");
            contacts[i].number = 0;

            int j;
            for(j = i; j < *cContacts - 1; j++){
                contacts[j] = contacts[j+1];
            }

            *cContacts -= 1;

            printf(green_text "\n\tContato excluido com sucesso!\n" reset_color);

            return;
        }
    }
    
    printf(red_text "\n\tContato nao encontrado.\n" reset_color);
    return;
}

void ConsultContact(int *cContacts){

    char name[30];
    printf("\n\tDigite o nome do contato que deseja consultar --> ");
    scanf("%s", &name);

    int i;
    for(i = 0; i < *cContacts; i++){

        if(strcmp(name, contacts[i].name) == 0){

            printf("\n\tNome do contato --> %s\n", contacts[i].name);
            printf("\tTelefone do contato --> %d\n", contacts[i].number);
            printf("\tEmail do contato --> %s\n", contacts[i].email);

            return;
        }
    }

    printf(red_text "\n\tContato nao encontrado.\n" reset_color);
    return;
}

void ConsultAllContacts(int *cContacts){

    int i;
    for(i = 0; i < *cContacts; i++){

        printf("\n\t-------------------------------------------------------\n");
        if(contacts[i].number != 0){

            printf("\n\tNome do contato --> %s", contacts[i].name);
            printf("\n\tTelefone do contato --> %d", contacts[i].number);
            printf("\n\tEmail do contato --> %s\n", contacts[i].email);
        }
    }
        printf("\n\t-------------------------------------------------------\n");

}