#include "sensor.h"
#include <stdio.h>
#include <stdlib.h>


void inicializarSensores(struct Sensor sensores[],int quantidade){
    for (int i = 0; i < quantidade; i++)
    {
        sensores[i].id = i+1;
        sensores[i].temperatura = 0.0;
        sensores[i].umidade = 0.0;
    }
    
    
}

void definirLimites(float *tempMin, float *tempMax, float *umidadeMin, float *umidadeMax){
    printf("Defina a temperatura Minima: ");
    scanf("%f", tempMin);

    printf("Defina a temperatura Maxima: ");
    scanf("%f", tempMax);

    printf("Defina a umidade Minima: ");
    scanf("%f", umidadeMin);

    printf("Defina a umidade Maxima: ");
    scanf("%f", umidadeMax);

}

void lerDadosSensor(struct Sensor *sensor){
    sensor->temperatura =  20.0 +(rand()%1000)/100.0; // valores de 20 ate 30
    sensor->umidade = 50.0 + (rand()%500) / 10.0; // vao de 50 a 100
}

void exibirDadosSensor(struct Sensor sensores[],int quantidade,float tempMin, float tempMax, float umidadeMin, float umidadeMax){
    for(int i=0; i<quantidade;i++){
        printf("\n----- Sensor ID %d -----\n", sensores[i].id);
        printf("\nTemperatura: %.2f\n", sensores[i].temperatura);
        printf("Umidade: %.2f\n", sensores[i].umidade);

        verificarLimitesSensor(&sensores[i], tempMin, tempMax, umidadeMin, umidadeMax);

        printf("\n");
    }
}


void verificarLimitesSensor(struct Sensor *sensor, float tempMin, float tempMax, float umidadeMin, float umidadeMax)
{
    static int alarmeTemperatura = 0;
    static int alarmeUmidade = 0;


    
    if(sensor->temperatura > tempMax){
        printf("\nTemperatura Ata\n");
        alarmeTemperatura++;
    } else if(sensor->temperatura < tempMin){
        printf("\nTemperatura Baixa\n");
        alarmeTemperatura++;
    }else{
        printf("\nTemperatura normal\n");
    }

    if(sensor->umidade > umidadeMax){
        printf("Umidade Alta\n");
        alarmeUmidade++;
    } else if(sensor->umidade < umidadeMin){
        printf("Umidade Baixa\n");
        alarmeUmidade++;
    }else{
        printf("Umidade normal\n");
    }

    printf("\nTotal de alarmes Temperatura: %d\n", alarmeTemperatura);
    printf("Total de alarmes Umidade: %d\n", alarmeUmidade);


}

void relatorioDados(struct Sensor *sensor, struct Valores *valor){

    // definir o maior de temperatura e umidade
    if(sensor->temperatura > valor->maiorTemp){
        valor->maiorTemp = sensor->temperatura;
    }

    if(sensor->umidade > valor->maiorUmi){
        valor->maiorUmi = sensor->umidade;
    }

    // definir o menor de temperatura e umidade
    if(sensor->temperatura < valor->menorTemp){
        valor->menorTemp = sensor->temperatura;
    }

    if(sensor->umidade < valor->menorUmi){
        valor->menorUmi = sensor->umidade;
    }

}

void imprimirRelatorio(struct Valores *valor){

    printf("\n======== RELATORIO =========\n");
    printf("Maior temperatura atingida: %.2f\n", valor->maiorTemp);
    printf("Maior umidade atingida: %.2f\n", valor->maiorUmi);
    printf("\nMenor temperatura atingida: %.2f\n", valor->menorTemp);
    printf("Menor umidade atingida: %.2f\n", valor->menorUmi);
}



