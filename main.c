#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "utils.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    No* biblioteca = inicializar_arvore();
    int opcao;
    char genero[50];
    char arquivo[50];
    Livro livro;

    do {
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Código: ");
            scanf("%d", &livro.codigo);
            printf("Título: ");
            scanf(" %[^\n]s", livro.titulo);
            printf("Autor: ");
            scanf(" %[^\n]s", livro.autor);
            printf("Gênero: ");
            scanf(" %[^\n]s", livro.genero);
            printf("Ano: ");
            scanf("%d", &livro.ano);
            printf("Editora: ");
            scanf(" %[^\n]s", livro.editora);
            printf("Páginas: ");
            scanf("%d", &livro.paginas);
            inserir_livro(&biblioteca, livro);
            break;
        case 2:
            printf("Gênero: ");
            scanf(" %[^\n]s", genero);
            buscar_por_genero(biblioteca, genero);
            break;
        case 3:
            printf("Nome do arquivo CSV: ");
            scanf(" %[^\n]s", arquivo);
            biblioteca = carregar_livros(arquivo, biblioteca);
            break;
        case 4:
            exibir_arvore(biblioteca);
            break;
        case 5:
            liberar_arvore(biblioteca);
            printf("Encerrando...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    return 0;
}
