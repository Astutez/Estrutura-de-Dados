#include <stdio.h>
#include <locale.h>
#include <string.h>


typedef struct {
    char menu;
} pr;

typedef struct {
    int cadastroSN;
    char email[50];
    char senha[50];
    char confirmarsenha[50];
    int autorizacao;
} login;

void cadastro(login *p);

void logar(login *p);

void principal(pr *p);

int main(void) {
    login p1;
    pr pv;

    setlocale(LC_ALL, "");
    principal(&pv);
    printf("************************************************\n");
    printf("* BEM VINDO/A AO SISTEMA DE VENDA DE PASSAGENS *\n");
    printf("************************************************\n\n");


    printf("Você já possui um cadastro?\n\n");
    printf("1 - Sim || 2 - Não\n");
    printf("\n");
    scanf("%d", &p1.cadastroSN);
    getchar();
    printf("\n\n\n\n\n\n");

    if (p1.cadastroSN == 2) {
        cadastro(&p1);
    }
    if (p1.cadastroSN == 1) {
        logar(&p1);
    }
    return 0;
}

void cadastro(login *p) {
    if (p->cadastroSN == 2) {
        printf("---------------------------------------------------------------------------------------------\n\n\n");
        printf("Para cadastrar-se por favor, insira seu \n\n");
        printf("Email: ");
        fgets(p->email, 50, stdin);
        printf("\n\n");

        do {
            printf("Senha: ");
            fgets(p->senha, 50, stdin);
            printf("\n");
            printf("Digite a senha novamente: ");
            fgets(p->confirmarsenha, 50, stdin);
            printf("\n");
            if (strcmp(p->senha, p->confirmarsenha) == 0) {
                break;
            } else {
                printf("As senhas não são iguais, por favor, insira novamente.\n\n");
            }
        } while (1);
    }
    p->cadastroSN = 1;
}

void logar(login *p) {
    if (p->cadastroSN == 1) {
        printf("---------------------------------------------------------------------------------------------\n\n\n");
        do {
            printf("Para continuar por favor, insira seu login.\n\n");
            printf("email:  ");
            fgets(p->email, sizeof(p->email), stdin);
            printf("\n");
            printf("Senha: ");
            fgets(p->senha, sizeof(p->senha), stdin);

            if (strcmp(p->email, p->email) == 0 && strcmp(p->senha, p->senha) == 0) {
                break;
            } else {
                printf("Email ou senha incorretos.\n\n\n\n");
            }
        } while (1);

        printf("\n\n\n\n\n\n");
    }
}

void principal(pr *p) {
    printf("---------------------------------------------------------------------------------------------\n\n\n");
    printf("************************************************\n");
    printf("* BEM VINDO/A AO SISTEMA DE VENDA DE PASSAGENS *\n");
    printf("************************************************\n\n");


    printf("----Menu de funcionalidades \n\n");
    printf("1. Visualizar passagens disponíveis\n");
    printf("2. Consultar passagens\n");
    printf("3. Cancelar passagens\n");
    printf("4. Configurações\n");
    printf("5. sair\n");
    scanf("%d", &p->menu);
}
