#include <stdio.h> // lib padrão de entrada e saída
#include <unistd.h> // lib para padrão para acessar as funções do unix
#include <fcntl.h> // lib para manipulação de arquivos do sistema
#include <errno.h> // lib para tratamento de erro

int main(int argc, char *argv[]){
    int fileToRead; // deve armazenar o file descriptor do arquivo lido
    void *buff[1024]; // buffer para armazenar os dados lidos do arquivo
    if ( argc < 2){ 
        printf("%s: missing file operand\n", argv[0]); // se não for informado arquivo
    } else {
        for(int i = 1; i < argc; i++){ // executar para cada arquivo informado
            fileToRead = open(argv[i], O_RDONLY); // acessando o arquivo com a permissão de 'ler apenas'
            if(fileToRead < 0){ // -1 significa que ocorreu um erro
                if(errno == ENOENT) // se o arquivo não for encontrado
                    printf("%s: cannot read file '%s': No such file or directory\n", argv[0], argv[1]);
                else if(errno  == EISDIR) // se for um diretório
                    printf("%s: error to read file '%s': is a directory\n", argv[0], argv[1]);
                else // outros erros
                    printf("%s: error to read file '%s'\n", argv[0], argv[1]);
            } else {
                int size; // armazena o retorno da função read(). (a quantidade de bytes lidos)
                while((size = read(fileToRead, buff, 1024)) != 0){ // lê o arquivo 1024 bytes por vez. nulo (ou zero) representa o fim do arquivo
                    write(1, buff, size); // escreve no terminal
                }
            }
            close(fileToRead); // dispensa(fecha) o arquivo lido
        }
    }
    return 0;
}

// close() reference: https://man7.org/linux/man-pages/man2/close.2.html
// open/creat reference: https://man7.org/linux/man-pages/man2/creat.2.html
// read reference:https://man7.org/linux/man-pages/man2/read.2.html
// write reference: https://man7.org/linux/man-pages/man2/write.2.html
