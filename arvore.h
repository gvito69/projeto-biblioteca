#ifndef ARVORE_H
#define ARVORE_H

typedef struct Livro {
    int codigo;
    char titulo[100];
    char autor[100];
    char genero[50];
    int ano;
    char editora[50];
    int paginas;
} Livro;

typedef struct No {
    Livro livro;
    struct No *esquerda, *direita;
} No;

// funcoes principais
No* inicializar_arvore();
void inserir_livro(No** raiz, Livro livro);
void buscar_por_genero(No* raiz, char* genero);
No* carregar_livros(char* nome_arquivo, No* raiz);
void exibir_arvore(No* raiz);
void liberar_arvore(No* raiz);

#endif
