#include <stdio.h> // lib padrão de entrada e saída
#include <unistd.h> // lib para padrão para acessar as funções do unix
#include <fcntl.h> // lib para manipulação de arquivos do sistema
#include <errno.h> // lib para tratamento de erro

int main(int argc, char *argv[]){
    int fdToCreate; // deve armazenar o retorno da função creat()
    mode_t modeNewFile = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; // permissões do novo arquivo
    if ( argc < 2){
        printf("%s: missing file operand\n", argv[0]); // caso em que não é passado nenhum argumento
    } else {
        fdToCreate = creat(argv[1], modeNewFile); // cria um novo arquivo com as permissões acima
        if( fdToCreate < 0){ // tratamento de erros
            if (errno == EACCES) // usuário não têm permissão para criar o arquivo
                printf("%s: cannot create '%s'\n: permission danied", argv[0], argv[1]);
            else // outros erros
                printf("%s: cannot create '%s'\n", argv[0], argv[1]);
        }
    }
    return 0;
}

// close() reference: https://man7.org/linux/man-pages/man2/close.2.html
// open/creat reference: https://man7.org/linux/man-pages/man2/creat.2.html
