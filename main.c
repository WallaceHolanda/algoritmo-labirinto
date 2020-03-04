#include <stdio.h>
#include <stdlib.h>

void imprimeMatriz(int** matriz, int linhas, int colunas){
    int i, j;
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            printf("[%d]  ", matriz[i][j]);
        }
        printf("\n");
    }
}

int auxiliar(int line, int colum, int linAtual, int colAtual){
    if((colAtual > colum) || (colAtual < 0)){
        return 1;
    }else if ((linAtual > line) || (linAtual < 0)){
        return 1;
    }else {
        return 0;
    }
}

int verificaBlock(int** matriz, int line, int colum, int atualLine, int atualColun){
    if(auxiliar(line, colum, atualLine, atualColun)){
        return 1;
    }else if(matriz[atualLine][atualColun] == 1){
        return 0;
    } else {
        return 1;
    }
}

int verificaLabirinto(int** matriz, int linhas, int colunas, int atualColun, int atualLine){
    if(auxiliar(linhas, colunas, atualLine, atualColun) == 1){
        //printf("[%d] [%d] Invalido!\n", atualLine, atualColun);
        return 0;
    }else{
        if(matriz[atualLine][atualColun] == 2){
            //printf("[%d] [%d] Encontrado!\n", atualLine, atualColun);
            return 1;
        }else if (matriz[atualLine][atualColun] == 0){
            //printf("[%d] [%d] Bloqueado!\n", atualLine, atualColun);
            return 0;
            //printf("\nValor: %d\n", matriz[atualColun][atualLine]);
        } else if(matriz[atualLine][atualColun] == 1){
            //printf("[%d] [%d] Valida!\n", atualLine, atualColun);
            //int sum = 0;
            int esq = atualColun - 1;
            int dir = atualColun + 1;
            int baixo = atualLine + 1;
            if(verificaLabirinto(matriz, linhas, colunas, dir, atualLine) == 1){
                return 1;
            }
            if(verificaLabirinto(matriz, linhas, colunas, atualColun, baixo) == 1){
                return 1;
            }
            if(verificaBlock(matriz, linhas, colunas, baixo, esq) == 0){
                if(verificaLabirinto(matriz, linhas, colunas, esq, baixo) == 1){
                    return 1;
                }
            }
            return 0;

        }else{
            //printf("Caso Inesperado!");
            return 0;
        }
    }

}

int main()
{
    int i, j, num_linhas, num_colunas;
    int** matriz;

    printf("Informe o numero de linhas: ");
    scanf("%d", &num_linhas);
    printf("Informe o numero de colunas: ");
    scanf("%d", &num_colunas);

    matriz = (int**) malloc(num_linhas * sizeof(int*));

    for(i = 0; i < num_linhas; i++){
        matriz[i] = (int*) malloc(num_colunas * sizeof(int));
    }

    for(i = 0; i < num_linhas; i++){
        for(j = 0; j < num_colunas; j++){
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }

    verificaLabirinto(matriz, num_linhas, num_colunas, 0, 0) == 1 ? printf("Ha saida!\n") : printf("Nao ha saida\n");
    imprimeMatriz(matriz, num_linhas, num_colunas);
    return 0;
}
