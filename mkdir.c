#include <stdio.h> // lib padrão de entrada e saída
#include <unistd.h> // lib para padrão para acessar as funções do unix
#include <sys/stat.h> // lib para usar diretamente uma chamada de sistema
#include <errno.h> // lib para tratamento de erro
#include <fcntl.h> // lib para manipulação de arquivos do sistema. possui funções e estruturas

int main(int argc, char *argv[]){
    int createdDir; // recebe o retorno da função mkdir
    mode_t dirMode = S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH; // permissões de ler e executar para o usuário que chamou o programa, grupo e outros.
    if ( argc < 2 )
        printf("%s: missing operand\n", argv[0]); // se o nome se não for informado
    else {
        for ( int i = 1; i < argc; i++ ){ // para cada nome informado
            createdDir = mkdir(argv[i], dirMode); // função para criar um novo diretório. o nome  e as permissões são os parâmetros da função
            if(createdDir < 0){ // retorno -1 significa erro
                if (errno == EEXIST) // se o nome já existir
    	            printf("%s: cannot create directory '%s': already exists\n", argv[0],argv[i]);
                else // outros erros
    	            printf("%s: cannot create directory '%s'\n", argv[0], argv[i]);
            }
        }
    }

    return 0;
}

// mkdir reference: https://man7.org/linux/man-pages/man2/mkdir.2.html
// errno reference: https://man7.org/linux/man-pages/man3/errno.3.html
