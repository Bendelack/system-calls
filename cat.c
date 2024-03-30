#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int fdNewFile; // deve armazenar o file descriptor do arquivo original
    void *buff[1024];
    if ( argc < 2){
        printf("%s: missing file operand\n", argv[0]); // caso em que não é passado nenhum argumento
    } else {
        for(int i = 1; i < argc; i++){
            fdNewFile = open(argv[i], O_RDONLY); // acessando o arquivo original com a permissão de 'ler apenas'
            if(fdNewFile < 0){
                printf("%s: cannot find '%s': No such file or directory\n", argv[0], argv[1]);
            } else {
                int size;
                while((size = read(fdNewFile, buff, 1024)) != 0){
                    write(1, buff, size);
                }
            }
            close(fdNewFile);
        }
    }
    return 0;
}

// close() reference: https://man7.org/linux/man-pages/man2/close.2.html
// open/creat reference: https://man7.org/linux/man-pages/man2/creat.2.html
// read reference:https://man7.org/linux/man-pages/man2/read.2.html
// write reference: https://man7.org/linux/man-pages/man2/write.2.html
