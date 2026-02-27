#include <stdio.h>
#include <locale.h>
#include <string.h>

#define quantMAX 20

typedef struct {
    char nome[50];
    char apellido[50];
    int pontuacao;
    int numerodevitorias;
} Aluno;

int totalalunos = 0;

void cadastro(Aluno alunos[]);
void listar(Aluno alunos[]);
void ranking(Aluno alunos[]);

int main() {
    setlocale(LC_ALL, "Portuguese");

    Aluno alunos[quantMAX];
    int opcao;

    do {
        printf("\n------ Sistema de Campeonatos -----\n\n");
        printf("1. Cadastrar Aluno\n");
        printf("2. Listar Alunos\n");
        printf("3. Ranking\n");
        printf("4. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastro(alunos);
                break;
            case 2:
                listar(alunos);
                break;
            case 3:
                ranking(alunos);
                break;
        }



    } while (opcao != 4);

    return 0;
}

void cadastro(Aluno alunos[]) {

    if (totalalunos >= quantMAX) {
        printf("Limite máximo de alunos atingido!\n");
        return;
    }

    printf("\n----- Cadastro de Aluno -----\n");

    printf("Nome: ");
    getchar();
    fgets(alunos[totalalunos].nome, 50, stdin);
    alunos[totalalunos].nome[strcspn(alunos[totalalunos].nome, "\n")] = '\0';
    printf("\n");
    printf("Apelido: ");
    fgets(alunos[totalalunos].apellido, 50, stdin);
    alunos[totalalunos].apellido[strcspn(alunos[totalalunos].apellido, "\n")] = '\0'; //que saco que foi para descobrir como fazer o \n n?o ser imprimido em todo santo lugar
    printf("\n");
    printf("Pontuação: ");
    scanf("%d", &alunos[totalalunos].pontuacao);
    printf("\n");
    printf("Número de vitórias: ");
    scanf("%d", &alunos[totalalunos].numerodevitorias);
    printf("\n\n\n");
    totalalunos++;

    printf("Aluno cadastrado com sucesso!\n");
}

void listar(Aluno alunos[]) {

    if (totalalunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    printf("\n----- Lista de Alunos -----\n\n");

    for (int i = 0; i < totalalunos; i++) {
        printf("Aluno %d | Nome: %s | Apelido: %s | Pontuação: %d | Vitórias: %d\n",i + 1, alunos[i].nome, alunos[i].apellido, alunos[i].pontuacao,   alunos[i].numerodevitorias);




    }
}
void ranking (Aluno alunos[]) {


    int maior = 0;
    for (int i = 0; i < totalalunos; i++) {

            if (alunos[i].pontuacao > alunos[maior].pontuacao) {
                maior = i;

            }

    }
    printf("----- Ranking ------\n\n" );
    printf("O jogador com com maior pontuação foi: %s com a pontuação de: %d\n", alunos[maior].nome, alunos[maior].pontuacao );
}