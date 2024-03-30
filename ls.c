#include <stdio.h> // lib padrão de entrada e saída
#include <unistd.h> // lib para padrão para acessar as funções do unix
#include <string.h> // lib para manipulação de strings
#include <dirent.h> // lib com estruturas e funções para manipulação de diretórios

int main(int argc, char *argv[]){// argc contem a quantidate de argumentos. argv[] contém os argumentos.
    char path[200]; // deve armazenar o diretório a ser lido
    DIR *dir; // variáveis tipo DIR armazenam diretórios
    struct dirent *dirEntry; // struct para manipular um elemento de um diretório
    if ( argc > 1 )
        strcpy(path,argv[1]); // argv[1] contém o argumento especificado. path armazena este valor.
    else
        getcwd(path, 200); // se não for passado argumento, path armazena o diretório atual.
    dir = opendir(path); // abre o diretório armazenado em path
    while((dirEntry = readdir(dir)) != NULL){ // readdir obtem o proximo elemento do diretório. NULL significa que há mais elementos para ler
        if(strcmp(dirEntry->d_name,".") != 0 && strcmp(dirEntry->d_name,"..") != 0) // if para não mostrar '.' ou '..' :)
            printf("%s  ", dirEntry->d_name);
    }
    closedir(dir); // fecha o diretório
    printf("\n"); // pula linha
    return 0;
}

// getcwd reference: https://man7.org/linux/man-pages/man2/getcwd.2.html
// readdir reference: https://man7.org/linux/man-pages/man3/readdir.3.html
// openddir reference: https://man7.org/linux/man-pages/man3/opendir.3.html
// closedirreference: https://man7.org/linux/man-pages/man3/closedir.3.html
