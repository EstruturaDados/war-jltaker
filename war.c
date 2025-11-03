/* main.c
   Desafio War – Tema 1 (Nível Novato)
   Aluno: Jorge Luiz Alves de Moura
   Matrícula: 2025 0163 9259
   Curso: Análise e Desenvolvimento de Sistemas
   Disciplina: Estrutura de Dados

   Descrição:
   Este código foi desenvolvido em linguagem C para realizar o cadastro de territórios,
   inspirado no jogo War. O programa permite cadastrar 5 territórios com nome, cor do exército
   e quantidade de tropas, utilizando um vetor de structs. Após o cadastro, os dados são exibidos
   de forma organizada. O código está comentado para facilitar a correção e demonstrar compreensão
   da lógica aplicada.
*/
#include <stdio.h>      // Biblioteca padrão para entrada e saída de dados
#include <string.h>     // Biblioteca para manipulação de strings

// Constantes de tamanho para os campos da estrutura
#define MAX_TERRITORIOS 5  // Número máximo de territórios a serem cadastrados
#define MAX_NOME 30        // Tamanho máximo do nome do território
#define MAX_COR 10         // Tamanho máximo da cor do exército

// Definição da estrutura Territorio
// Agrupa os dados relacionados a cada território: nome, cor do exército e número de tropas
typedef struct {
    char nome[MAX_NOME];   // Nome do território
    char cor[MAX_COR];     // Cor do exército associado ao território
    int tropas;            // Quantidade de tropas presentes no território
} Territorio;

// Função auxiliar para remover o caractere de nova linha deixado pelo fgets
// Isso evita que o '\n' seja armazenado junto com o texto digitado
void trim_newline(char *s) {
    size_t n = strlen(s);              // Obtém o tamanho da string
    if (n > 0 && s[n - 1] == '\n') {   // Verifica se o último caractere é '\n'
        s[n - 1] = '\0';               // Substitui por '\0' para encerrar a string corretamente
    }
}

// Função que realiza o cadastro dos territórios
// Recebe um vetor de territórios e preenche os dados de cada um com entrada do usuário
void cadastrarTerritorios(Territorio mapa[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("\n=== Cadastro do Território %d ===\n", i + 1);

        // Entrada do nome do território
        printf("Nome: ");
        fgets(mapa[i].nome, MAX_NOME, stdin);     // Lê o nome com suporte a espaços
        trim_newline(mapa[i].nome);               // Remove o '\n' do final da string

        // Verifica se o nome está vazio e atribui um nome padrão
        if (strlen(mapa[i].nome) == 0) {
            printf("Nome vazio. Usando 'Territorio%d'.\n", i + 1);
            snprintf(mapa[i].nome, MAX_NOME, "Territorio%d", i + 1); // Gera nome padrão
        }

        // Entrada da cor do exército
        printf("Cor do exército (ex: vermelho, azul,): ");
        fgets(mapa[i].cor, MAX_COR, stdin);       // Lê a cor com suporte a espaços
        trim_newline(mapa[i].cor);                // Remove o '\n' do final da string

        // Verifica se a cor está vazia e atribui "neutro"
        if (strlen(mapa[i].cor) == 0) {
            strcpy(mapa[i].cor, "neutro");        // Define cor padrão
        }

        // Entrada da quantidade de tropas com validação
        printf("Quantidade de tropas: ");
        while (scanf("%d", &mapa[i].tropas) != 1) {
            // Se a entrada não for um número, limpa o buffer e pede novamente
            int c;
            while ((c = getchar()) != '\n' && c != EOF); // Limpa o buffer
            printf("Quantidade inválida. Digite um número: ");
        }

        // Limpa o buffer após leitura numérica para evitar conflitos com fgets
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
}

// Função que exibe os dados dos territórios cadastrados
// Percorre o vetor e imprime os dados formatados de cada território
void exibirTerritorios(Territorio mapa[], int tamanho) {
    printf("\n=== Territórios Registrados ===\n");
    for (int i = 0; i < tamanho; i++) {
        // Exibe os dados formatados de cada território
        printf("%d) Nome: %s | Cor: %s | Tropas: %d\n",
               i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// Função principal do programa
// Coordena o fluxo de execução: cadastro e exibição dos territórios
int main() {
    Territorio mapa[MAX_TERRITORIOS]; // Vetor que armazenará os territórios cadastrados

    // Mensagem de boas-vindas ao usuário
    printf("Bem-vindo ao Desafio War Estruturado - Nível Novato.\n");
    printf("Você irá cadastrar %d territórios.\n", MAX_TERRITORIOS);

    // Chamada da função para realizar o cadastro dos territórios
    cadastrarTerritorios(mapa, MAX_TERRITORIOS);

    // Chamada da função para exibir os dados dos territórios cadastrados
    exibirTerritorios(mapa, MAX_TERRITORIOS);

    return 0; // Finaliza o programa com sucesso
}