#include <stdio.h>
#include <string.h>

#define red_text "\x1b[31m"
#define green_text "\x1b[32m"
#define orange_text "\x1b[33m"
#define reset_color "\x1b[0m"

    /* Crie um programa em C para gerenciar uma agenda de contatos. O programa deve permitir:

    Adicionar contatos (cada contato terá um nome, telefone e email).
    Buscar contatos pelo nome.
    Excluir contatos.
    editar contatos.

    Listar todos os contatos da agenda. */


void AddContact(int *cContacts);
void EditContact(int *cContacts);                    
void DeleteContact(int *cContacts);
void ConsultContact(int *cContacts);
void ConsultAllContacts(int *cContacts);
void SalvarDados(int *cContacts);

typedef struct{
    char name[30];
    char number[15];
    char email[50];

}contact;
    contact contacts[100];

    char invalida[] = red_text "Reposta invalida, tente novamente.\n" reset_color;

int main(void){

    int cContacts = 0;
    FILE *arquivo;

    arquivo = fopen("contato.bin", "rb");

    if(arquivo != NULL){
        fread(&cContacts, sizeof(int), 1, arquivo);
        fread(contacts, sizeof(contact), cContacts, arquivo);
        fclose(arquivo);

    } else{
        printf(red_text "\nArquivo nao encontrado.\n" reset_color);
    }

    fread(contacts, sizeof(contact), 100, arquivo);
    fclose(arquivo);

    //caso nao exista contatos, zerar a variavel cContacts. se o primeiro contato for vazio, nao existe contatos.
    if(strcmp(contacts[0].number, "") == 0 || strcmp(contacts[0].name, "") == 0 || strcmp(contacts[0].email, "") == 0){
        cContacts = 0;
    } 

    printf("\nnumero contato --> %d\n", cContacts);

    printf("\n* Agenda de contatos *\n\n");

    while(1){

        int resp;
        printf("\n\n\nO que deseja fazer ?\n");
        printf("\n 1 - Adicionar contato.\n 2 - Editar contato.\n 3 - Excluir contato.\n 4 - Consultar contato por nome.\n "
                "5 - Listar todos os contatos.\n 6 - Finalizar.\n 7 - Salvar Dados.\n");
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

            case 7:

                SalvarDados(&cContacts);
                break;

            default:
                puts(invalida);
        }
    }

    return 0;
}


void AddContact(int *cContacts){
    char name[30];
    char number[15];
    char email[50];

    printf("\n\tQual o telefone do contato ? --> ");
    scanf("%s", number);

    int i;
    for(i = 0; i < *cContacts; i++){        //verifica se o contato ja existe.

        if(strcmp(number, contacts[i].number) == 0){
            printf(red_text "\n\tContato ja existente, tente novamente.\n" reset_color);
            return;
        }
    }

    while(getchar() != '\n');   //limpa o buffer do teclado.

    printf("\n\tQual o nome do contato ? --> ");
    fgets(name, 30, stdin);
    name[strcspn(name, "\n")] = 0;   //remove o \n do fgets().
    

    printf("\n\tQual email do contato ? --> ");
    scanf("%s", email);

    strcpy(contacts[i].name, name);
    strcpy(contacts[i].email, email);
    strcpy(contacts[i].number, number);

    *cContacts += 1;

    printf(green_text "\n\tContato adicionado com sucesso!\n" reset_color);

    return;  
}

void EditContact(int *cContacts){
    char name[30];
    char number[15];
    char email[50];

    int op;
    printf("\n\tDigite o telefone do contato que deseja editar --> ");
    scanf("%s", number);

    int i;
    for(i = 0; i < *cContacts; i++){
            
        if(strcmp(number, contacts[i].number) == 0){
                
            int edit;
            do{

                printf("\n\tInforme o que deseja editar.\n");
                printf("\t1 - nome.\n \t2 - telefone.\n \t3 - email.\n");
                scanf("%d", &edit);

                switch(edit){
                    case 1:
                        printf("\n\tNome do contato --> %s\n", contacts[i].name);

                        printf("\n\tDigite o novo nome a ser alterado --> ");
                        scanf("%s", name);

                        strcpy(contacts[i].name, name);

                        printf(green_text "\n\tNome alterado com sucesso!\n" reset_color);

                        break;

                    case 2:
                        printf("\n\tTelefone do contato --> %s", contacts[i].number);

                        printf("\n\tDigite o novo telefone a ser alterado --> ");
                        scanf("%s", &number);

                        strcpy(contacts[i].number, number);

                        printf(green_text "\n\tTelefone alterado com sucesso!\n" reset_color);
                        break;

                    case 3:
                        printf("\n\tEmail do contato --> %s", contacts[i].email);

                        printf("\n\tDigite o novo email a ser alterado --> ");
                        scanf("%s", email);

                        strcpy(contacts[i].email, email);

                        printf(green_text "\n\tEmail alterado com sucesso!\n" reset_color);
                        break;

                    default:
                        puts(invalida);
                }

                op = -1;
                while(op != 0 && op != 1){
                    printf("\n\tDeseja editar algo mais nesse contato ? (1 - sim / 0 - nao)--> ");
                    scanf("%d", &op);

                    if(op != 0 && op != 1){
                        puts(invalida);
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
    char number[15];

    printf("\n\tInforme o telefone do contato que deseja deletar --> ");
    scanf("%s", number);

    int i;
    for(i = 0; i < *cContacts; i++){
        
        if(strcmp(number, contacts[i].number) == 0){
            printf("\n\tNome do contato --> %s\n", contacts[i].name);
            printf("\tTelefone do contato --> %s\n", contacts[i].number);
            printf("\tEmail do contato --> %s\n", contacts[i].email);

            int resp = -1;
            while(resp != 0 && resp != 1){
                printf("\n\tDeseja realmente excluir o contato ? (1 - sim / 0 - nao) --> ");
                scanf("%d", &resp);

                if(resp != 0 && resp != 1){
                    puts(invalida);
                }
            }

            if(resp == 1){
                contacts[i].number[0] = '\0';
                contacts[i].name[0] = '\0';
                contacts[i].email[0] = '\0';

                int j;
                for(j = i; j < *cContacts - 1; j++){
                    contacts[j] = contacts[j+1];
                }

                *cContacts -= 1;

                printf(green_text "\n\tContato excluido com sucesso!\n" reset_color);
                return;         
            } else{
                printf(orange_text "\n\tContato nao excluido.\n" reset_color);
                return;
            }

            return;
        }
    }
    
    printf(red_text "\n\tContato nao encontrado.\n" reset_color);
    return;
}

void ConsultContact(int *cContacts){

    char name[30];
    printf("\n\tDigite o nome do contato que deseja consultar --> ");
    scanf("%s", name);

    int i;
    for(i = 0; i < *cContacts; i++){

        if(strcmp(name, contacts[i].name) == 0){

            printf("\n\tNome do contato --> %s\n", contacts[i].name);
            printf("\tTelefone do contato --> %s\n", contacts[i].number);
            printf("\tEmail do contato --> %s\n", contacts[i].email);

            return;
        }
    }

    printf(red_text "\n\tContato nao encontrado.\n" reset_color);
    return;
}

void ConsultAllContacts(int *cContacts){

    int i;
    for(i = 0; i < 100; i++){

        if(strcmp(contacts[i].number, "") == 0 || strcmp(contacts[i].name, "") == 0 || strcmp(contacts[i].email, "") == 0){
            continue;
        }

        printf("\n\t-------------------------------------------------------\n");       
        printf("\n\tNome do contato --> %s", contacts[i].name);
        printf("\n\tTelefone do contato --> %s", contacts[i].number);
        printf("\n\tEmail do contato --> %s\n", contacts[i].email);
        
    }
        printf("\n\t-------------------------------------------------------\n");

    return;
}

void SalvarDados(int *cContacts){
    FILE *arquivo;

    arquivo = fopen("contato.bin", "wb");

    if(arquivo != NULL){
        fwrite(cContacts, sizeof(int), 1, arquivo);
        fwrite(contacts, sizeof(contact), *cContacts, arquivo); 
        fclose(arquivo);

        printf(green_text "\n\tDados salvos com sucesso!\n" reset_color);
    } else{
        printf(red_text "\nArquivo nao encontrado.\n" reset_color);
    }

    return;
}