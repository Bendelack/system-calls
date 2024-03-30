#include <stdio.h> // lib de entrada e saída
#include <time.h> // lib para acessar tipos e funções relacionados a data

int main(){
    time_t currentTime; // variável do tipo time_t que recebe o tempo em segundos
    time(&currentTime); // usando a função de sistema time() para adicionar o tempo no endereço de memória da variável
    char *t = ctime(&currentTime); // converte o valor para o padrão -> dia mes data hora ano
    printf("%s", t); // mostra no console
    return 0;
}

// ctime() reference: https://man7.org/linux/man-pages/man3/ctime.3.html
// time() reference: https://man7.org/linux/man-pages/man2/time.2.html