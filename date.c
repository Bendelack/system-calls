#include <stdio.h>
#include <time.h>

int main(){
    time_t currentTime; // variável do tipo time_t que recebe o tempo em segundos
    time(&currentTime); // usando a função de sistema time() para adicionar o tempo no endereço de memória da variável
    char *t = ctime(&currentTime); // converte o valor para o padrão -> dia mes data hora ano
    printf("%s", t); // mostra no console
    return 0;
}
