#include <stdio.h>

// Função para calcular a mochila
float* mochila(float itens[][2], float peso_disponivel, int num_itens) {
    // Calcula o preço por kg de cada item
    float precos[num_itens];
    for (int i = 0; i < num_itens; i++) {
        precos[i] = itens[i][0] / itens[i][1];
    }

    // Coloca identificador de cada item e ordena pelo mais valioso
    int ordem_itens[num_itens];
    for (int i = 0; i < num_itens; i++) {
        ordem_itens[i] = i;
    }

    // Bubble sort para ordenar pelo preço por kg em ordem decrescente
    for (int i = 0; i < num_itens - 1; i++) {
        for (int j = 0; j < num_itens - i - 1; j++) {
            if (precos[j] < precos[j + 1]) {
                // Troca os valores de precos
                float temp = precos[j];
                precos[j] = precos[j + 1];
                precos[j + 1] = temp;

                // Troca os valores de ordem_itens
                int temp_ordem = ordem_itens[j];
                ordem_itens[j] = ordem_itens[j + 1];
                ordem_itens[j + 1] = temp_ordem;
            }
        }
    }

    // Quantidade em kg pego de cada item
    float pego[num_itens];

    // Percorre todos os itens disponíveis, até o menos valioso
    for (int k = 0; k < num_itens; k++) {
        int posicao_item = ordem_itens[k];

        // Verifica se é possível pegar tudo disponível daquele item
        if (itens[posicao_item][1] <= peso_disponivel) {
            pego[posicao_item] = itens[posicao_item][1];
            peso_disponivel -= itens[posicao_item][1];
        } else {
            // Pega o máximo que o peso permite
            pego[posicao_item] = peso_disponivel;
            peso_disponivel = 0;
        }

        // Mochila cheia
        if (peso_disponivel == 0) {
            break;
        }
    }

    // Retorna o array contendo a quantidade de cada item pego
    return pego;
}

int main() {
    // Exemplos de uso da função
    float exemplo1[][2] = {{10, 10}, {5, 6}, {8, 5}};
    float *resultado1 = mochila(exemplo1, 7, 3);
    printf("Exemplo 1: [%.2f, %.2f, %.2f]\n", resultado1[0], resultado1[1], resultado1[2]);

    float exemplo2[][2] = {{70, 7}, {8, 5}, {10, 10}};
    float *resultado2 = mochila(exemplo2, 7, 3);
    printf("Exemplo 2: [%.2f, %.2f, %.2f]\n", resultado2[0], resultado2[1], resultado2[2]);

    float exemplo3[][2] = {{5, 6}, {10, 9}, {8, 5}, {8, 8}};
    float *resultado3 = mochila(exemplo3, 70, 4);
    printf("Exemplo 3: [%.2f, %.2f, %.2f, %.2f]\n", resultado3[0], resultado3[1], resultado3[2], resultado3[3]);

    return 0;
}
