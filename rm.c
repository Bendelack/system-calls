#include <stdio.h> // lib padrão de entrada e saída
#include <unistd.h> // lib para padrão para acessar as funções do unix
#include <fcntl.h> // lib para manipulação de arquivos do sistema
#include <errno.h> // lib para tratamento de erro

int main(int argc, char *argv[]){
    int removedFile; // deve armazenar o file descriptor do arquivo original
    if ( argc < 2){ 
        printf("%s: missing file operand\n", argv[0]); // caso em que não é passado nenhum argumento
    } else {
        for(int i = 1; i < argc; i++){ // repete para cada argumento passado
            removedFile = unlink(argv[i]); // removendo o arquivo
            if(removedFile < 0){
                if (errno == ENOENT) // se o arquivo não existir
                    printf("%s: cannot remove file '%s': No such file\n", argv[0], argv[1]);
                else if (errno == EISDIR) // se foi infomado um diretório ao invés de arquivo
                    printf("%s: cannot remove file '%s': is a directory\n", argv[0], argv[1]);
                else // outros erros
                    printf("%s: error to remove file '%s'\n", argv[0], argv[1]);
            }
        }
    }
    return 0;
}

// unlink() reference: https://man7.org/linux/man-pages/man2/unlink.2.html
