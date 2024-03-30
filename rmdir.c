#include <stdio.h> // lib padrão de entrada e saída
#include <unistd.h> // lib para padrão para acessar as funções do unix
#include <sys/stat.h> // lib para usar diretamente uma chamada de sistema
#include <errno.h> // import para tratamento de erro

int main(int argc, char *argv[]){
    int removedDir; // armazena o retorno da função rmdir
    if ( argc < 2 )
        printf("%s: missing operand\n", argv[0]); // se não foi passado argumento
    else {
        for ( int i = 1; i < argc; i++ ){ // repete para cada argumento informado
            removedDir = rmdir(argv[i]); // função para remover um diretório. o argumento é o path do diretório
            if(removedDir < 0){ // tratamento de erros
                if (errno == ENOENT) // se o diretório não existir
    	            printf("%s: failed to remove directory '%s': no such directory\n", argv[0],argv[i]);
                else if (errno == ENOTDIR) // se o argumento não for um diretório
    	            printf("%s: failed to remove directory '%s': is not a directory\n", argv[0],argv[i]);
                else if (errno == ENOTEMPTY) // se o diretório não estiver vazio
    	            printf("%s: failed to remove '%s':directory not empty\n", argv[0],argv[i]);
                else // outros erros
    	            printf("%s: failed to remove directory '%s'\n", argv[0], argv[i]);
            }
        }
    }

    return 0;
}

// rmdir reference: https://man7.org/linux/man-pages/man2/rmdir.2.html
// errno reference: https://man7.org/linux/man-pages/man3/errno.3.html
