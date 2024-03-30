#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int fdToCreate; // deve armazenar o file descriptor do arquivo original
    if ( argc < 2){
        printf("%s: missing file operand\n", argv[0]); // caso em que não é passado nenhum argumento
    } else {
         fdToCreate = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        if( fdToCreate < 0){
            printf("%s: cannot create '%s': No such file or directory\n", argv[0], argv[1]);
        }
        close(fdToCreate);
    }
    return 0;
}

// close() reference: https://man7.org/linux/man-pages/man2/close.2.html
// open/creat reference: https://man7.org/linux/man-pages/man2/creat.2.html
