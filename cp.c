#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int fdOriginal; // deve armazenar o file descriptor do arquivo original
    int fdCopy; // deve armazenar o file descriptor da cópia
    void *buff[1024];
    if ( argc < 2){
        printf("%s: missing file operand\n", argv[0]); // caso em que não é passado nenhum argumento
    } else if(argc < 3){
        printf("%s: missing destination file operand after '%s'\n", argv[0], argv[1]); // caso em que é passado apena a origem
    } else {
        fdOriginal = open(argv[1], O_RDONLY); // acessando o arquivo original com a permissão de 'ler apenas'
        fdCopy = open(argv[2], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
        if(fdOriginal < 0){
            printf("%s: cannot find '%s': No such file or directory\n", argv[0], argv[1]);
        } else {
            int size;
            while((size = read(fdOriginal, buff, 1024)) != 0){
                write(fdCopy, buff, size);
            }
        }
        close(fdOriginal);
        close(fdCopy);
    }
    return 0;
}

// close() reference: https://man7.org/linux/man-pages/man2/close.2.html
// open/creat reference: https://man7.org/linux/man-pages/man2/creat.2.html
// read reference:https://man7.org/linux/man-pages/man2/read.2.html
// write reference: https://man7.org/linux/man-pages/man2/write.2.html
