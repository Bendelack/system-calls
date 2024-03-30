#include <stdio.h> // lib padrão de entrada e saída
#include <unistd.h> // lib para padrão para acessar as funções do unix
#include <string.h> // lib para manipulação de strings
#include <sys/syscall.h> // lib para acessar as chamadas de sistema diretamente
#include <sys/types.h>
#include <dirent.h>

char *dirType(int codType){
    if(codType == 4)
        return "dir";
    else
        return "file";
    return "unknow";
}

int main(int argc, char *argv[]){// argc contem a quantidate de argumentos. argv[] contém os argumentos.
    char path[200];
    DIR *dir;
    struct dirent *dirEntry;
    if ( argc > 1 )
        strcpy(path,argv[1]); // argv[1] contém o argumento especificado. path armazena este valor.
    else
        getcwd(path, 200); // se não for passado argumento, path armazena o diretório atual.
    dir = opendir(path); // abre o diretório armazenado em path
    while(1){
	dirEntry = readdir(dir);
	if(dirEntry == NULL)
	    break;
        if(strcmp(dirEntry->d_name,".") != 0 && strcmp(dirEntry->d_name,"..") != 0)
            printf("%s  ", dirEntry->d_name);
    }
    closedir(dir);
    printf("\n");
    return 0;
}

// getcwd reference: https://man7.org/linux/man-pages/man2/getcwd.2.html
// readdir reference: https://man7.org/linux/man-pages/man3/readdir.3.html
// openddir reference: https://man7.org/linux/man-pages/man3/opendir.3.html
// closedirreference: https://man7.org/linux/man-pages/man3/closedir.3.html
