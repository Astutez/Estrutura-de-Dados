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



    printf("\n");
    printf("=================================================\n");
    printf("      SISTEMA DE VENDA DE PASSAGENS\n");
    printf("=================================================\n\n");

    printf("Você já possui um cadastro?\n\n");
    printf(" 1 - Sim\n");
    printf(" 2 - Não\n\n");
    printf("Escolha: ");
    scanf("%d", &p1.cadastroSN);
    getchar();
    printf("\n\n");

    if (p1.cadastroSN == 2) {
        cadastro(&p1);
    }
    if (p1.cadastroSN == 1) {
        logar(&p1);
    }
    return 0;
}

void cadastro(login *p ) {
    if (p->cadastroSN == 2) {
        printf("\n");
        printf("=================================================\n");
        printf("                 CADASTRO\n");
        printf("=================================================\n\n");

        printf("Para cadastrar-se, preencha os dados abaixo:\n\n");

        printf("Email: ");
        fgets(p->email, 50, stdin);
        printf("\n");



        do {
            printf("Senha: ");
            fgets(p->senha, 50, stdin);
            printf("\n");

            printf("Confirme a senha: ");
            fgets(p->confirmarsenha, 50, stdin);
            printf("\n");

            if (strcmp(p->senha, p->confirmarsenha) == 0) {
                break;
            } else {
                printf("As senhas não são iguais. Tente novamente.\n\n");
            }
        } while (1);



        printf("Cadastro finalizado!\n");
        printf("=================================================\n\n");

    }
    p->cadastroSN = 1;

}

void logar(login *p) {
    if (p->cadastroSN == 1) {
        printf("\n");
        printf("=================================================\n");
        printf("                   LOGIN\n");
        printf("=================================================\n\n");

        char emailDigitado[50];
        char senhaDigitada[50];

        do {
            printf("Para continuar, faça login:\n\n");

            printf("Email: ");
            fgets(emailDigitado, sizeof(emailDigitado), stdin);
            printf("\n");

            printf("Senha: ");
            fgets(senhaDigitada, sizeof(senhaDigitada), stdin);

            if (strcmp(p->email, emailDigitado) == 0 && strcmp(p->senha, senhaDigitada) == 0) {
                printf("\n\nLogin efetuado com sucesso!\n");
                printf("=================================================\n\n");
                break;
            } else {
                printf("\n\nEmail ou senha incorretos. Tente novamente.\n\n");
            }
        } while (1);

        printf("\n");
    }
}

void principal(pr *p) {
    printf("\n");
    printf("=================================================\n");
    printf("      SISTEMA DE VENDA DE PASSAGENS\n");
    printf("=================================================\n\n");

    printf("Menu de funcionalidades:\n\n");
    printf(" 1 - Visualizar passagens disponíveis\n");
    printf(" 2 - Consultar passagens\n");
    printf(" 3 - Cancelar passagens\n");
    printf(" 4 - Configurações\n");
    printf(" 5 - Sair\n\n");

    printf("Escolha: ");
    scanf("%d", &p->menu);

    printf("\n");
    printf("-------------------------------------------------\n");
}