#include <stdio.h> // lib padrão de entrada e saída
#include <unistd.h> // lib para padrão para acessar as funções do unix
#include <sys/stat.h> // lib para usar diretamente uma chamada de sistema
#include <errno.h> // import para tratamento de erro

int main(int argc, char *argv[]){
    int removedDir;
    if ( argc < 2 )
        printf("%s: missing operand\n", argv[0]);
    else {
        for ( int i = 1; i < argc; i++ ){
            removedDir = rmdir(argv[i]);
            if(removedDir < 0){ // tratamento de erros
                if (errno == EEXIST)
    	            printf("%s: failed to remove directory '%s': already exists\n", argv[0],argv[i]);
                else if (errno == ENOENT)
    	            printf("%s: failed to remove directory '%s': no such directory\n", argv[0],argv[i]);
                else if (errno == ENOTDIR)
    	            printf("%s: failed to remove directory '%s': is not a directory\n", argv[0],argv[i]);
                else if (errno == EACCES)
    	            printf("%s: failed to remove directory '%s': access danied\n", argv[0],argv[i]);
                else if (errno == ENOTEMPTY)
    	            printf("%s: failed to remove '%s':directory not empty\n", argv[0],argv[i]);
                else
    	            printf("%s: failed to remove directory '%s'\n", argv[0], argv[i]);
            }
        }
    }

    return 0;
}

// rmdir reference: https://man7.org/linux/man-pages/man2/rmdir.2.html
// errno reference: https://man7.org/linux/man-pages/man3/errno.3.html
