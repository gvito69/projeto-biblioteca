#include <stdio.h>
#include "utils.h"
#include <locale.h>


void menu() {
    setlocale(LC_ALL, "Portuguese");
    printf("Menu:\n");
    printf("1. Inserir Livro\n");
    printf("2. Buscar por G�nero\n");
    printf("3. Carregar Livros do CSV\n");
    printf("4. Exibir �rvore\n");
    printf("5. Sair\n");
}
