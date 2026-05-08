# Trabalho Prático: Agenda com pBuffer

Olá, meu nome é Suelen Heling Beduhn, e este é o meu vídeo de explicação do trabalho prático da Agenda.

O objetivo deste trabalho foi implementar uma agenda de contatos em C gerenciando a memória da aplicação manualmente. O desafio principal foi seguir as restrições rigorosas, simulando o papel do Sistema Operacional na organização da memória:

* **Regra 1:** Nenhuma variável foi declarada em todo o programa (nem mesmo como parâmetro de função). Foram utilizados apenas ponteiros apontando para os endereços corretos dentro de um único `void *pBuffer`.
* **Regra 2:** Nenhuma `struct` foi utilizada. O tamanho dos registros foi calculado via Macros e aritmética de ponteiros.
* **Teste de Memória:** O projeto foi testado e o gerenciamento do `pBuffer` foi validado sem vazamentos (`0 leaks`) utilizando o **Valgrind**.

# Como compilar e executar
O projeto foi estruturado para facilitar a compilação. Para compilar e rodar, utilize os comandos no terminal:

```bash
# Para compilar o projeto
mingw32-make

# Para executar a agenda
.\output\main.exe