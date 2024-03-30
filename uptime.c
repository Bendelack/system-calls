#include <stdio.h>
#include <time.h>

int main(){
    struct timespec ts; // struct usada para pegar o tempo
    clock_gettime(CLOCK_MONOTONIC, &ts); // função de sistemaa usada para pegar o tempo. tipo de clock e struct são os argumentos
    int timeSeconds = ts.tv_sec; // variavel que armazena o tempo de utilização em segundos
    int days = timeSeconds / 86400;; // tempo em dias
    int hours = (timeSeconds % 86400)/(3600); // tempo em horas
    int minuts = (timeSeconds % (3600)) / 60; // tempo em minutos
    int seconds = timeSeconds % 60; // tempo em segundos
    printf("| %d days | %d hours | %d minuts | %d seconds |\n", days, hours, minuts, seconds); // mostrando na tela
    return 0;
}

// reference: https://man7.org/linux/man-pages/man2/clock_gettime.2.html
