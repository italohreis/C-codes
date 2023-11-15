#include <stdio.h>
#include <string.h>

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

    char invalida[] = red_text "Reposta invalida, tente novamente.\n" reset_color;

    void AddContact(int *cContacts);
    void EditContact(int *cContacts);
    void DeleteContact(int *cContacts);
    void ConsultContact(int *cContacts);
    void ConsultAllContacts(int *cContacts);



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
                puts(invalida);

        }
    }

    return 0;
}


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
                        puts(invalida);
                }

                printf("\n\tDeseja editar algo mais nesse contato ? (1 - sim / 0 - nao)--> ");
                scanf("%d", &op);

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

        printf("\n\t-----------------------------------------------------------------\n");
        if(contacts[i].number != 0){

            printf("\n\tNome do contato --> %s", contacts[i].name);
            printf("\n\tTelefone do contato --> %d", contacts[i].number);
            printf("\n\tEmail do contato --> %s\n", contacts[i].email);
        }

    }


}