#include <stdio.h> // lib padrão de entrada e saída
#include <unistd.h> // lib para padrão para acessar as funções do unix
#include <sys/stat.h> // lib para usar diretamente uma chamada de sistema
#include <errno.h> // import para tratamento de erro

int main(int argc, char *argv[]){
    int createdDir;
    if ( argc < 2 )
        printf("%s: missing operand\n", argv[0]);
    else {
        for ( int i = 1; i < argc; i++ ){
            createdDir = mkdir(argv[i], S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
            if(createdDir < 0){
                if (errno == EEXIST)
    	            printf("%s: cannot create directory '%s': already exists\n", argv[0],argv[i]);
                else
    	            printf("%s: cannot create directory '%s'\n", argv[0], argv[i]);
            }
        }
    }

    return 0;
}

// mkdir reference: https://man7.org/linux/man-pages/man2/mkdir.2.html
// errno reference: https://man7.org/linux/man-pages/man3/errno.3.html
