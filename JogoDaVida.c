
/*
Trabalho de Programação 2
Autores: Bernardo Pires Mesko e Bárbara Mafra
Professor: Thiago Lipinski Paes
Turma: Informática 3
Data: 25/06/2019
Instituto Federal de Santa Catarina, Câmpus Gaspar
*/
#include<stdio.h>
int TAM;//Esse valor vai ser o tamanho da matriz que vai aparecer
void printMat (int matriz[][TAM]);
void scanMat (int matriz[][TAM]);
void zerarMat (int matriz[][TAM]);
int compMats (int matrizA[][TAM], int matrizB[][TAM]);
void recebeMats (int matrizA[][TAM],int matrizB[][TAM]);
int somarVizinhos (int matriz[][TAM], int i, int j);
void novaGeracao (int matriz[][TAM], int matrizAnterior[][TAM]);
void textaoTop();

int main (){
        textaoTop();
        printf("Digite o tamanho do seu mundo (ele vai ser uma matriz quadrada):\n");
        scanf("%d",&TAM);
        int mundo[TAM][TAM], proximoMundo[TAM][TAM], geracao = 2;
        zerarMat (mundo);
        scanMat (mundo);
        recebeMats(proximoMundo, mundo);
        printf("\n***** QUE OS JOGOS COMECEM!!!! *****\n");
        printf("Geracao 1:\n");
        printMat(mundo);
        do{
                recebeMats(mundo, proximoMundo);
                novaGeracao(mundo, proximoMundo);
                printf("Geracao %d:\n", geracao);
                printMat(proximoMundo);
                geracao++;
        } while(compMats(mundo, proximoMundo)!= 1);
}

void textaoTop (){
                printf(" ::::::::  :::    ::: :::::::::  :::::::::: ::::::::: \n");
        printf(":+:    :+: :+:    :+: :+:    :+: :+:        :+:    :+:\n");
        printf("+:+        +:+    +:+ +:+    +:+ +:+        +:+    +:+ \n");
        printf("+#++:++#++ +#+    +:+ +#++:++#+  +#++:++#   +#++:++#:  \n");
        printf("       +#+ +#+    +#+ +#+        +#+        +#+    +#+ \n");
        printf("#+#    #+# #+#    #+# #+#        #+#        #+#    #+# \n");
        printf(" ########   ########  ###        ########## ###    ### \n");
        printf("\n");
        printf(":::::::::::  ::::::::   ::::::::   ::::::::  \n");
        printf("    :+:     :+:    :+: :+:    :+: :+:    :+: \n");
        printf("    +:+     +:+    +:+ +:+        +:+    +:+ \n");
        printf("    +#+     +#+    +:+ :#:        +#+    +:+ \n");
        printf("    +#+     +#+    +#+ +#+   +#+# +#+    +#+ \n");
        printf("#+# #+#     #+#    #+# #+#    #+# #+#    #+# \n");
        printf(" #####       ########   ########   ######## \n");
        printf("\n");
        printf(":::::::::      :::     \n");
        printf(":+:    :+:   :+: :+:   \n");
        printf("+:+    +:+  +:+   +:+  \n");
        printf("+#+    +:+ +#++:++#++: \n");
        printf("+#+    +#+ +#+     +#+ \n");
        printf("#+#    #+# #+#     #+# \n");
        printf("#########  ###     ### \n");
        printf("\n");
        printf(":::     ::: ::::::::::: :::::::::      :::    \n");
        printf(":+:     :+:     :+:     :+:    :+:   :+: :+:   \n");
        printf("+:+     +:+     +:+     +:+    +:+  +:+   +:+  \n");
        printf("+#+     +:+     +#+     +#+    +:+ +#++:++#++: \n");
        printf(" +#+   +#+      +#+     +#+    +#+ +#+     +#+ \n");
        printf("  #+#+#+#       #+#     #+#    #+# #+#     #+# \n");
        printf("    ###     ########### #########  ###     ### \n");
        printf("\n");
        printf("\n");
        printf("As regras sao simples e elegantes:\n");
        printf("\n");
        printf("1. Qualquer celula viva com menos de dois vizinhos vivos morre de solidao. \n");
        printf("2. Qualquer celula com exatamente tres vizinhos vivos se torna uma celula viva.\n");
        printf("3. Qualquer celula viva com mais de tres vizinhos vivos morre de superpopulacao. \n");
        printf("4. Qualquer celula com dois vizinhos vivos continua no mesmo estado para a proxima geracao.\n");
        printf("\n");
        printf("Autores: Bernardo Pires Mesko e Barbara Mafra\n");
        printf("Turma: Informatica 3\n");
        printf("Professor: Thiago Lipinski Paes\n");
        printf("\n");
} 

void printMat (int matriz[][TAM]){ //Função de mostrar a matriz na tela
  int i, j;
  for (i = 0; i < TAM; i++){
      for (j = 0; j < TAM; j++){
          printf ("[%d]", matriz[i][j]);
        }
      printf ("\n");
    }
  printf ("\n");
}

void scanMat (int matriz[][TAM]){//Função de ler o estado inicial  da matriz
  int i, j, novoValor = 2;
  for (i = 0; i < TAM; i++){
      for (j = 0; j < TAM; j++){
          if (novoValor != -1){
            while (novoValor != -1 && novoValor != 0 && novoValor != 1){//Garantir que os únicos valores aceitos sejam 0, 1 ou -1
                    printf("*****************************************************\n");
                printf("Digite um valor (0 ou 1) para a celula da linha %d e coluna %d.\n",i+1, j+1);
                printf ("Para encerrar a digitacao, digite -1.\n");
                scanf ("%d", &novoValor);
            }
            if (novoValor == 0 || novoValor == 1){
                matriz[i][j] = novoValor;
                novoValor = 2;//2 é um número qualquer que não vai fazer nada (1, 0 e -1 fazem)
            } else {
                matriz[i][j] = 0;
            }
            printMat (matriz);//Isso mostra a matriz na tela toda vez que um elemento for lido
           }
        }
    }
}

void zerarMat (int matriz[][TAM]){//Isso zera a matriz no começo
  int i, j;
  for (i = 0; i < TAM; i++){
      for (j = 0; j < TAM; j++){
          matriz[i][j] = 0;
        }
    }
}

int compMats (int matrizA[][TAM], int matrizB[][TAM]){
  int i, j, matrizesIguais = 1;//Se for 1, são iguais
  for (i = 0; i < TAM; i++){
      for (j = 0; j < TAM; j++){
          if (matrizA[i][j] != matrizB[i][j]){
              matrizesIguais = 0;//Se for 0, são diferentes
            }
        }
    }
  return matrizesIguais;
}

void recebeMats (int matrizA[][TAM],int matrizB[][TAM]){
        int i, j;
        for(i=0;i<TAM;i++){
                for(j=0;j<TAM;j++){
                        matrizA[i][j] = matrizB[i][j];
                }
        }
}

int somarVizinhos (int matriz[][TAM], int i, int j){
        int somaVizinhos;
        if (i == 0){ //Elemento está na primeira linha
            if (j == 0){ //i=0 j=0
                somaVizinhos = matriz[TAM - 1][TAM - 1] + matriz[TAM - 1][0] + matriz[TAM - 1][1] + matriz[0][TAM - 1] + matriz[0][1] + matriz[1][TAM - 1] + matriz[1][0] + matriz[1][1];
            } else if (j == TAM - 1){ //i=0, j=TAM-1
                somaVizinhos = matriz[TAM - 1][TAM - 2] + matriz[TAM - 1][TAM - 1] + matriz[TAM - 1][0] + matriz[0][TAM - 2] + matriz[0][0] + matriz[1][TAM - 2] + matriz[1][TAM - 1] + matriz[1][0];
        } else { //i=0
          somaVizinhos = matriz[TAM - 1][j - 1] + matriz[TAM - 1][j] + matriz[TAM - 1][j + 1] + matriz[0][j - 1] + matriz[0][j + 1] + matriz[1][j - 1] + matriz[1][j] + matriz[1][j + 1];
        }
    } else if (i == TAM - 1){ //Elemento está na última linha
      if (j == 0){ //i=TAM-1 j=0
          somaVizinhos = matriz[TAM - 2][TAM - 1] + matriz[TAM - 2][0] + matriz[TAM - 2][1] + matriz[TAM - 1][TAM - 1] + matriz[TAM - 1][1] + matriz[0][TAM - 1] + matriz[0][0] + matriz[0][1];
        } else if (j == TAM - 1){ //i=TAM-1 j=TAM-1
          somaVizinhos = matriz[TAM - 2][TAM - 2] + matriz[TAM - 2][TAM - 1] + matriz[TAM - 2][0] + matriz[TAM - 1][TAM - 2] + matriz[TAM - 1][0] + matriz[0][TAM - 2] + matriz[0][TAM - 1] + matriz[0][0];
        } else { //i=TAM-1
          somaVizinhos = matriz[TAM - 2][j - 1] + matriz[TAM - 2][j] + matriz[TAM - 2][j + 1] + matriz[TAM - 1][j - 1] + matriz[TAM - 1][j + 1] + matriz[0][j - 1] + matriz[0][j] + matriz[0][j + 1];
            } 
    } else { //Elemento não está em uma linha importante
                if (j == 0){//j=0
                somaVizinhos = matriz[i - 1][TAM - 1] + matriz[i - 1][0] + matriz[i - 1][1] + matriz[i][TAM - 1] + matriz[i][1] + matriz[i + 1][TAM - 1] + matriz[i + 1][0] + matriz[i + 1][1];
            }else if(j == TAM - 1){//j=TAM-1
            somaVizinhos = matriz[i - 1][TAM - 2] + matriz[i - 1][TAM - 1] + matriz[i - 1][0] + matriz[i][TAM - 2] + matriz[i][0] + matriz[i + 1][TAM - 2] + matriz[i + 1][TAM - 1] + matriz[i + 1][0];
        } else { //nada importante
          somaVizinhos = matriz[i - 1][j - 1] + matriz[i - 1][j] + matriz[i - 1][j + 1] + matriz[i][j - 1] + matriz[i][j + 1] + matriz[i + 1][j - 1] + matriz[i + 1][j] + matriz[i + 1][j + 1];
        }
    }
        return somaVizinhos;
}

void novaGeracao (int matriz[][TAM], int novaMatriz[][TAM]){  
        int i, j; 
            for (i = 0; i < TAM; i++){
            for (j = 0; j < TAM; j++){
                switch (somarVizinhos (matriz, i, j)){ 
                    case 0 ... 1: //Qualquer célula viva com menos de dois vizinhos vivos morre de solidão.
                            novaMatriz[i][j] = 0; 
                    break;
                    case 2:
                            novaMatriz[i][j] = matriz[i][j];
                    break;
                    case 3: //Qualquer célula com exatamente três vizinhos vivos se torna uma célula viva.
                            novaMatriz[i][j] = 1;  
                    break;
                    case 4 ...8: //Qualquer célula viva com mais de três vizinhos vivos morre de superpopulação:
                            novaMatriz[i][j] = 0;
                    break;
                }
            }
        }
   }
