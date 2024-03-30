#include <stdio.h> // lib padrão de entrada e saída
#include <unistd.h> // lib para padrão para acessar as funções do unix
#include <fcntl.h> // lib para manipulação de arquivos do sistema
#include <errno.h> // lib para tratamento de erro

int main(int argc, char *argv[]){
    int fdOriginal; // deve armazenar o file descriptor do arquivo original
    int fdCopy; // deve armazenar o file descriptor da cópia
    void *buff[1024]; // buffer para armazenar os dados lidos do arquivo
    mode_t newFileMode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; // permissões de ler e escrever para o usuário que chamou o programa, grupo e outros.
    if ( argc < 2){
        printf("%s: missing file operand\n", argv[0]); // caso em que não é passado nenhum argumento
    } else if(argc < 3){
        printf("%s: missing destination file operand after '%s'\n", argv[0], argv[1]); // caso em que é passado apena a origem
    } else {
        fdOriginal = open(argv[1], O_RDONLY); // acessando o arquivo original com a permissão de 'ler apenas'
        fdCopy = open(argv[2], O_RDWR | O_CREAT, newFileMode); // se o arquivo existir, ele sobrescreve o conteúdo. se não, ele cria um novo arquivo com permissões.
        if(fdOriginal < 0){ // -1 significa que ocorreu um erro
            if(errno == ENOENT) // se o arquivo não for encontrado
                printf("%s: cannot read file '%s': No such file or directory\n", argv[0], argv[1]);
            else if(errno  == EISDIR) // se for um diretório
                printf("%s: error to read file '%s': is a directory\n", argv[0], argv[1]);
            else // outros erros
                printf("%s: error to read file '%s'\n", argv[0], argv[1]);
        } else {
            int size; // armazena o retorno da função read(). (a quantidade de bytes lidos)
            while((size = read(fdOriginal, buff, 1024)) != 0){ // lê o arquivo 1024 bytes por vez. nulo (ou zero) representa o fim do arquivo
                write(fdCopy, buff, size); // escreve no novo arquivo
            }
        }
        close(fdOriginal); // dispensa(fecha) o arquivo original
        close(fdCopy); // dispensa(fecha) a cópia
    }
    return 0;
}

// close() reference: https://man7.org/linux/man-pages/man2/close.2.html
// open/creat reference: https://man7.org/linux/man-pages/man2/creat.2.html
// read reference:https://man7.org/linux/man-pages/man2/read.2.html
// write reference: https://man7.org/linux/man-pages/man2/write.2.html
