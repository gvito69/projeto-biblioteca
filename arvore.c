#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include <locale.h>

// inicializar a arvore
No* inicializar_arvore() {
    return NULL;
}

// criar um novo nó
No* criar_no(Livro livro) {
    No* novo = (No*)malloc(sizeof(No));
    novo->livro = livro;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// inserir livro na arvore
void inserir_livro(No** raiz, Livro livro) {
    setlocale(LC_ALL, "Portuguese");
    if (*raiz == NULL) {
        *raiz = criar_no(livro);
        return;
    }
    if (livro.codigo < (*raiz)->livro.codigo) {
        inserir_livro(&((*raiz)->esquerda), livro);
    } else if (livro.codigo > (*raiz)->livro.codigo) {
        inserir_livro(&((*raiz)->direita), livro);
    } else {
        printf("Erro: Código duplicado (%d).\n", livro.codigo);
    }
}

// buscar livros por genero
void buscar_por_genero(No* raiz, char* genero) {
    if (raiz == NULL) return;
    buscar_por_genero(raiz->esquerda, genero);
    if (strcmp(raiz->livro.genero, genero) == 0) {
        printf("Código: %d, Título: %s, Autor: %s, Ano: %d, Editora: %s, Páginas: %d\n",
            raiz->livro.codigo, raiz->livro.titulo, raiz->livro.autor,
            raiz->livro.ano, raiz->livro.editora, raiz->livro.paginas);
    }
    buscar_por_genero(raiz->direita, genero);
}

// carregar livros do arquivo csv
No* carregar_livros(char* nome_arquivo, No* raiz) {
    FILE* file = fopen(nome_arquivo, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo %s.\n", nome_arquivo);
        return raiz;
    }

    Livro livro;
    char linha[256];
    while (fgets(linha, sizeof(linha), file)) {
        sscanf(linha, "%d,%99[^,],%99[^,],%49[^,],%d,%49[^,],%d",
            &livro.codigo, livro.titulo, livro.autor, livro.genero,
            &livro.ano, livro.editora, &livro.paginas);
        inserir_livro(&raiz, livro);
    }
    fclose(file);
    return raiz;
}

// exibir a arvore (in-ordem)
void exibir_arvore(No* raiz) {
    if (raiz == NULL) return;
    exibir_arvore(raiz->esquerda);
    printf("Código: %d, Título: %s, Autor: %s, Ano: %d, Editora: %s, Páginas: %d\n",
        raiz->livro.codigo, raiz->livro.titulo, raiz->livro.autor,
        raiz->livro.ano, raiz->livro.editora, raiz->livro.paginas);
    exibir_arvore(raiz->direita);
}

// liberar memoria da arvore
void liberar_arvore(No* raiz) {
    if (raiz == NULL) return;
    liberar_arvore(raiz->esquerda);
    liberar_arvore(raiz->direita);
    free(raiz);
}
