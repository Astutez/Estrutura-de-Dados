#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 5
#define COLUNAS 4
#define MAX_ONIBUS 10
#define MAX_PASSAGENS 20

typedef struct {
    int menu;
} pr;

typedef struct {
    int cadastroSN;
    char email[50];
    char senha[50];
    char confirmarsenha[50];
} login;

typedef struct {
    int ocupado;
} assento;

typedef struct {
    char destino[50];
    float preco;
    char data[20];
    char horario[10];
    assento lugares[LINHAS][COLUNAS];
} onibus;

typedef struct {
    int onibusIndex;
    int linha;
    int coluna;
    char cpf[15];
    char nome[100];
    char nascimento[20];
} passagem;

typedef struct {
    passagem lista[MAX_PASSAGENS];
    int quantidade;
} passagemUsuario;

// FUNÇÕES
void cadastro(login *p);
void logar(login *p);
void principal(pr *p, onibus frota[], int *qtd);
void mostrarAssentos(onibus *o);
void comprarPassagem(onibus frota[], int qtd, passagemUsuario *p);
void cancelarPassagem(onibus frota[], int qtd, passagemUsuario *p);
void visualizarPassagem(onibus frota[], passagemUsuario p);
int validarNascimento(char nascimento[]);

int main(void) {
    login p1;
    pr pv;

    onibus frota[MAX_ONIBUS] = {
        {"Ourinhos -> Chavantes", 15.00, "10/04/2026", "08:00"},
        {"Ourinhos -> Canitar", 12.00, "12/04/2026", "14:30"},
        {"Ourinhos -> Salto Grande", 18.00, "15/04/2026", "09:15"}
    };

    int qtdOnibus = 3;

    for (int i = 0; i < qtdOnibus; i++) {
        for (int j = 0; j < LINHAS; j++) {
            for (int k = 0; k < COLUNAS; k++) {
                frota[i].lugares[j][k].ocupado = 0;
            }
        }
    }

    setlocale(LC_ALL, "");

    printf("=================================================\n");
    printf("      SISTEMA DE VENDA DE PASSAGENS\n");
    printf("=================================================\n\n");

    printf("Você já possui um cadastro?\n\n");
    printf(" 1 - Sim\n");
    printf(" 2 - Não\n\n");
    printf("Escolha: ");
    scanf("%d", &p1.cadastroSN);
    getchar();

    switch (p1.cadastroSN) {
        case 1:
            logar(&p1);
            break;
        case 2:
            cadastro(&p1);
            logar(&p1);
            break;
    }

    principal(&pv, frota, &qtdOnibus);

    return 0;
}

void cadastro(login *p ) {
    printf("\n----- CADASTRO -----\n\n");

    printf("Email: ");
    fgets(p->email, 50, stdin);

    do {
        printf("Senha: ");
        fgets(p->senha, 50, stdin);

        printf("Confirmar senha: ");
        fgets(p->confirmarsenha, 50, stdin);

        if (strcmp(p->senha, p->confirmarsenha) != 0) {
            printf("Senhas diferentes!\n");
        }
    } while (strcmp(p->senha, p->confirmarsenha) != 0);

    printf("Cadastro realizado!\n\n");
}

void logar(login *p) {
    char emailDigitado[50];
    char senhaDigitada[50];

    printf("\n----- LOGIN -----\n\n");

    do {
        printf("Email: ");
        fgets(emailDigitado, 50, stdin);

        printf("Senha: ");
        fgets(senhaDigitada, 50, stdin);

        emailDigitado[strcspn(emailDigitado, "\n")] = 0;
        senhaDigitada[strcspn(senhaDigitada, "\n")] = 0;
        p->email[strcspn(p->email, "\n")] = 0;
        p->senha[strcspn(p->senha, "\n")] = 0;

        if ((strcmp(emailDigitado, "mateus") == 0 && strcmp(senhaDigitada, "12345") == 0) ||
            (strcmp(p->email, emailDigitado) == 0 && strcmp(p->senha, senhaDigitada) == 0)) {

            printf("\nLogin realizado com sucesso!\n\n");
            break;
        } else {
            printf("Login inválido!\n\n");
        }
    } while (1);
}

void principal(pr *p, onibus frota[], int *qtd) {

    passagemUsuario passagem;
    passagem.quantidade = 0;

    do {
        printf("\n----- MENU -----\n\n");
        printf("1 - Comprar passagem\n");
        printf("2 - Ver ônibus\n");
        printf("3 - Cancelar passagem\n");
        printf("4 - Ver minhas passagens\n");
        printf("5 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &p->menu);

        switch (p->menu) {

            case 1:
                comprarPassagem(frota, *qtd, &passagem);
                break;

            case 2:
                for (int i = 0; i < *qtd; i++) {
                    printf("%d - %s | R$ %.2f | Data: %s | Hora: %s\n",
                           i + 1,
                           frota[i].destino,
                           frota[i].preco,
                           frota[i].data,
                           frota[i].horario);
                }
                break;

            case 3:
                cancelarPassagem(frota, *qtd, &passagem);
                break;

            case 4:
                visualizarPassagem(frota, passagem);
                break;

            case 5:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (p->menu != 5);
}

void mostrarAssentos(onibus *o) {
    printf("\nAssentos (%s):\n\n", o->destino);

    printf("   ");
    for (int j = 0; j < COLUNAS; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n");

    for (int i = 0; i < LINHAS; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < COLUNAS; j++) {
            if (o->lugares[i][j].ocupado == 0)
                printf("[O]");
            else
                printf("[X]");
        }
        printf("\n");
    }
}

int validarNascimento(char nascimento[]) {
    int dia, mes, ano;

    if (sscanf(nascimento, "%d/%d/%d", &dia, &mes, &ano) != 3) {
        return 0;
    }

    time_t t = time(NULL);
    struct tm hoje = *localtime(&t);

    int anoAtual = hoje.tm_year + 1900;
    int mesAtual = hoje.tm_mon + 1;
    int diaAtual = hoje.tm_mday;

    if (ano > anoAtual) return 0;

    int idade = anoAtual - ano;

    if (mes > mesAtual || (mes == mesAtual && dia > diaAtual)) {
        idade--;
    }

    if (idade < 18 || idade > 100) {
        return 0;
    }

    return 1;
}

void comprarPassagem(onibus frota[], int qtd, passagemUsuario *p) {
    if (p->quantidade >= MAX_PASSAGENS) {
        printf("Limite atingido!\n");
        return;
    }

    int op, l, c;
    char cpf[15], nome[100], nascimento[20];
    char assentoStr[5];

    printf("\nEscolha o ônibus:\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d - %s | Data: %s | Hora: %s | R$ %.2f\n",
               i + 1,
               frota[i].destino,
               frota[i].data,
               frota[i].horario,
               frota[i].preco);
    }

    scanf("%d", &op);
    getchar();

    if (op < 1 || op > qtd) return;

    onibus *o = &frota[op - 1];

    printf("\nDestino: %s Data: %s Horário: %s",
           o->destino, o->data, o->horario);

    mostrarAssentos(o);

    printf("Assento (A1 ou 2B): ");
    scanf("%s", assentoStr);

    if (assentoStr[0] >= 'A' && assentoStr[0] <= 'Z') {
        c = assentoStr[0] - 'A';
        l = atoi(&assentoStr[1]) - 1;
    } else {
        l = assentoStr[0] - '1';
        c = assentoStr[1] - 'A';
    }

    if (l < 0 || l >= LINHAS || c < 0 || c >= COLUNAS) {
        printf("Assento inválido!\n");
        return;
    }

    getchar();

    printf("Nome completo: ");
    fgets(nome, 100, stdin);

    do {
        printf("Data de nascimento (dd/mm/aaaa): ");
        fgets(nascimento, 20, stdin);
        nascimento[strcspn(nascimento, "\n")] = 0;

        if (!validarNascimento(nascimento)) {
            printf("Data inválida! Idade deve ser maior ou igual a 18 anos.\n");
        }

    } while (!validarNascimento(nascimento));

    printf("CPF: ");
    scanf("%s", cpf);

    if (o->lugares[l][c].ocupado == 0) {
        o->lugares[l][c].ocupado = 1;

        p->lista[p->quantidade].onibusIndex = op - 1;
        p->lista[p->quantidade].linha = l;
        p->lista[p->quantidade].coluna = c;
        strcpy(p->lista[p->quantidade].cpf, cpf);
        strcpy(p->lista[p->quantidade].nome, nome);
        strcpy(p->lista[p->quantidade].nascimento, nascimento);

        p->quantidade++;

        printf("\nPassagem confirmada!\n");
    } else {
        printf("Assento ocupado!\n");
    }
}

void cancelarPassagem(onibus frota[], int qtd, passagemUsuario *p) {
    if (p->quantidade == 0) {
        printf("\nSem passagens!\n");
        return;
    }

    for (int i = 0; i < p->quantidade; i++) {
        printf("%d - %s (Assento %c%d)\n",
               i + 1,
               frota[p->lista[i].onibusIndex].destino,
               'A' + p->lista[i].coluna,
               p->lista[i].linha + 1);
    }

    int escolha;
    scanf("%d", &escolha);

    if (escolha < 1 || escolha > p->quantidade) return;

    int idx = escolha - 1;

    onibus *o = &frota[p->lista[idx].onibusIndex];
    o->lugares[p->lista[idx].linha][p->lista[idx].coluna].ocupado = 0;

    for (int i = idx; i < p->quantidade - 1; i++) {
        p->lista[i] = p->lista[i + 1];
    }

    p->quantidade--;

    printf("Cancelada!\n");
}

void visualizarPassagem(onibus frota[], passagemUsuario p) {
    if (p.quantidade == 0) {
        printf("\nNenhuma passagem!\n");
        return;
    }

    for (int i = 0; i < p.quantidade; i++) {
        printf("\nDestino: %s ", frota[p.lista[i].onibusIndex].destino);
        printf("Data: %s Hora: %s",
               frota[p.lista[i].onibusIndex].data,
               frota[p.lista[i].onibusIndex].horario);

        printf(" Assento: %c%d\n",
               'A' + p.lista[i].coluna,
               p.lista[i].linha + 1);

        printf("Nome: %s", p.lista[i].nome);
        printf("Nascimento: %s", p.lista[i].nascimento);
        printf("CPF: %s\n", p.lista[i].cpf);
    }
}