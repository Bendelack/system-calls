# Atividade de Chamadas de Sistema
>## Chamada de Sistema
>Chamadas de sistema são funções que o Sistema Operacional disponibiliza para acessar os recursos que o mesmo gerencia. Para facilitar o uso dessas funções são desenvolvidos programas de sistemas, que permitem >que o usuário realize tarefas administrativas através da execução de programas, ao invés de fazer ele mesmo um programa.

## Programas de Sistema implementados
- **[date](date.c)** -> Mostra a hora atual.
- **[uptime](uptime.c)** -> Mostra a quanto tempo o computados está ligado.
- **[ls](ls.c)** -> Lista os arquivos localizados em um determinado diretório. Caso não seja especificado o diretório, usa o diretório de trabalho atual, que pode ser recuperado pela chamada de sistema getcwd().
- **[cp](cp.c)** -> Copia conteúdo de um arquivo para outro.
- **[rm](rm.c)** -> Remove arquivos.
- **[mv](mv.c)** -> Muda de lugar/nome um arquivo. Pode mudar um conjunto de arquivos, se o destino for um diretório. (em desenvolvimento)
- **[cat](cat.c)** -> Mostra no terminal o conteúdo de um arquivo. Considera arquivos em modo texto, mostrando cada byte como um valor ASCCII.
- **[mkdir](mkdir.c)** -> Cria um novo diretório.
- **[rmdir](rmdir.c)** -> Remove um diretório, caso o mesmo esteja vazio.
- **[chmod](chmod.c)** -> Muda as permissões de um arquivo/diretório. (talvez seja implementado ainda nesta vida)
- **[chown](chown.c)** -> Muda o usuário dono do arquivo e/ou o grupo ao qual ele pertence. (talvez seja implementado ainda nesta vida)

### Outros Programas
- **[touch](touch.c)** -> Cria um novo arquivo

### Resumo das Funções de Sistema Utilizadas

- **open()**: Abre um arquivo para ler ou escrever.
- **creat()**: Cria um novo arquivo.
- **close()**: Fecha um arquivo.
- **read()**: Lê dados de um arquivo.
- **write()**: Escreve dados em um arquivo.
- **opendir()**: Abre um diretório.
- **closedir()**: Fecha um diretório.
- **readdir()**: Lê o próximo item de um diretório.
- **time()**: Obtém o tempo atual em segundos desde a "Época". *Época*= 1970-01-01 00:00:00 +0000 (UTC)
- **ctime()**: Converte um valor de tempo para string.
- **getcwd()**: Obtém o diretório atual.
- **mkdir()**: Cria um novo diretório.
- **rmdir()**: Remove um diretório vazio.
- **unlink()**: Remove um arquivo.
- **rename()**: Renomeia um arquivo.
- **clock_gettime()**: Obtém o tempo de uso do processador.
