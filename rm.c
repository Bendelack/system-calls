#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int removedFile; // deve armazenar o file descriptor do arquivo original
    //void *buff[1024];
    if ( argc < 2){
        printf("%s: missing file operand\n", argv[0]); // caso em que não é passado nenhum argumento
    } else {
        for(int i = 1; i < argc; i++){
            removedFile = unlink(argv[i]); // acessando o arquivo original com a permissão de 'ler apenas'
            if(removedFile < 0)
                printf("%s: error to remove file '%s'\n", argv[0], argv[1]);
        }
    }
    return 0;
}

// unlink() reference: https://man7.org/linux/man-pages/man2/unlink.2.html
