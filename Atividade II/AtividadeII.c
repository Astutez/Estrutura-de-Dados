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
        printf("2. Ranking\n");
        printf("3. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastro(alunos);
                break;
            case 2:
                listar(alunos);
                break;
            case 3:

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
    scanf(" %[^\n]", alunos[totalalunos].nome);

    printf("Apelido: ");
    scanf(" %[^\n]", alunos[totalalunos].apellido);

    printf("Pontuação: ");
    scanf("%d", &alunos[totalalunos].pontuacao);

    printf("Número de vitórias: ");
    scanf("%d", &alunos[totalalunos].numerodevitorias);

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
        printf("Aluno %d\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Apelido: %s\n", alunos[i].apellido);
        printf("Pontuação: %d\n", alunos[i].pontuacao);
        printf("Vitórias: %d\n\n", alunos[i].numerodevitorias);
    }
}
void ranking (Aluno alunos[]) {


}