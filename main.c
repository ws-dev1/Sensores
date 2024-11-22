#include <stdio.h>
#include "sensor.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    struct Sensor sensores[MAX_SENSORES];
    float tempMin=10.0, tempMax=40.0;
    float umidadeMin=30.0, umidadeMax=80.0;
    struct Valores valoresRelatorio;
    valoresRelatorio.maiorTemp =0;
    valoresRelatorio.maiorUmi = 0;
    valoresRelatorio.menorTemp =30;
    valoresRelatorio.menorUmi = 100;
    char c;
    
    inicializarSensores(sensores, MAX_SENSORES);
    definirLimites(&tempMin, &tempMax, &umidadeMin, &umidadeMax);

    srand(time(NULL));  // Inicializa o gerador de números aleatórios

    

    while (1)
    {
        for(int i=0; i< MAX_SENSORES;i++){
            lerDadosSensor(&sensores[i]);
            relatorioDados(&sensores[i], &valoresRelatorio);
        }

        exibirDadosSensor(sensores, MAX_SENSORES, tempMin, tempMax, umidadeMin, umidadeMax);
        

        
        printf("Pressione 's' para sair, 'c' para configurar, qualquer tecla para continuar\n");
        if (scanf(" %c", &c) == 1) { 
            // Limpa o buffer após a leitura
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
        }

      
        if(c == 's' || c == 'S'){
            imprimirRelatorio(&valoresRelatorio);
            break;
        } else if (c== 'c' || c == 'C'){
            definirLimites(&tempMin, &tempMax, &umidadeMin, &umidadeMax);
            printf("Novos limites de temperatura e umidade definidos!\n\n");
        }

        
    }
    
    return 0;
}
