#ifndef SENSOR_H
#define SENSOR_H


#define MAX_SENSORES 2


struct Sensor{
    int id;
    float temperatura;
    float umidade;
};

struct Valores{
    float maiorTemp;
    float maiorUmi;
    float menorTemp;
    float menorUmi;
};

void inicializarSensores(struct Sensor sensores[],int quantidade);

void lerDadosSensor(struct Sensor *sensor);

void exibirDadosSensor(struct Sensor sensores[],int quantidade,float tempMin, float tempMax, float umidadeMin, float umidadeMax);

void verificarLimitesSensor(struct Sensor *sensor, float tempMin, float tempMax, float umidadeMin, float umidadeMax);

void definirLimites(float *tempMin, float *tempMax, float *umidadeMin, float *umidadeMax);

void relatorioDados(struct Sensor *sensor, struct Valores *valor);

void imprimirRelatorio(struct Valores *valor);

#endif