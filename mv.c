#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
    char *fileSource; // deve armazenar o file descriptor do arquivo original
    char *fileTarget; // deve armazenar o file descriptor da cópia
    struct stat sbSource;
    struct stat sbTarget;
    int movedFile;
    if ( argc < 2){
        printf("%s: missing file operand\n", argv[0]); // caso em que não é passado nenhum argumento
    } else if(argc < 3){
        printf("%s: missing destination file operand after '%s'\n", argv[0], argv[1]); // caso em que é passado apena a origem
    } else if(argc == 3) {
        stat(argv[1], &sbSource);
        stat(argv[2], &sbTarget);
        printf("%d\n", (sbSource.st_mode & S_IFMT) == S_IFREG);
        printf("%d\n", (sbTarget.st_mode & S_IFMT) == S_IFREG);
        if (((sbSource.st_mode & S_IFMT) == S_IFREG) && ((sbTarget.st_mode & S_IFMT) == S_IFREG)) { //
            /* Handle regular file */
            printf("os dois argumentos são arquivos regulares.\n");
            movedFile = rename(argv[1], argv[2]); // função rename() só funciona de arquivo para arquivo
            if(movedFile < 0)
                printf("%s: An Error Ocurred", argv[0]);
        }
    } else { // conferir se o último argumento é um diretório
        fileTarget = argv[argc - 1];
    }
    return 0;
}

// close() reference: https://man7.org/linux/man-pages/man2/close.2.html
// open/creat reference: https://man7.org/linux/man-pages/man2/creat.2.html
// read reference:https://man7.org/linux/man-pages/man2/read.2.html
// write reference: https://man7.org/linux/man-pages/man2/write.2.html
