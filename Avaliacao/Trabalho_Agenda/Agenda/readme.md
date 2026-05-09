# Trabalho Prático: Agenda com pBuffer

Olá, meu nome é Suelen Heling Beduhn, e este é o meu vídeo de explicação do trabalho prático da Agenda.

O objetivo deste trabalho foi implementar uma agenda de contatos em C gerenciando a memória da aplicação manualmente. O desafio principal foi seguir as restrições rigorosas, simulando o papel do Sistema Operacional na organização da memória:

* **Regra 1:** Nenhuma variável foi declarada em todo o programa (nem mesmo como parâmetro de função). Foram utilizados apenas ponteiros apontando para os endereços corretos dentro de um único `void *pBuffer`.
* **Regra 2:** Nenhuma `struct` foi utilizada. O tamanho dos registros foi calculado via Macros e aritmética de ponteiros.
* **Teste de Memória:** O projeto foi testado e o gerenciamento do `pBuffer` foi validado sem vazamentos (`0 leaks`) utilizando o **Valgrind**.

## Casos de Teste Realizados (Sucesso)

Para garantir a robustez da implementação, o sistema foi submetido aos seguintes cenários de teste, todos validados com 100% de sucesso:

1. **Inserção e Expansão Dinâmica:** Foram adicionados múltiplos contatos consecutivamente. O sistema executou corretamente o `realloc` do `pBuffer`, mantendo a integridade dos dados anteriores e expandindo o bloco de memória conforme a necessidade.
2. **Busca e Aritmética de Ponteiros:** Foi realizada a busca por nomes específicos dentro do buffer. O teste confirmou que a lógica de saltar os bytes do cabeçalho e percorrer os registros de cada pessoa está calculando os endereços de memória de forma precisa.
3. **Gestão de Memória (Zero Leaks):** O programa foi executado através do **Dr. Memory** (Windows) e **Valgrind** (Linux). Em ambos os casos, após a inserção, remoção de contatos e encerramento do programa, o relatório confirmou que todos os blocos foram liberados (`0 bytes of leak`).

## O que funciona e Limitações

### O que funciona perfeitamente:
* **CRUD em Bloco Único:** Adição, remoção, listagem e busca funcionando estritamente dentro de um único `void *pBuffer`.
* **Aritmética de Ponteiros Pura:** O código respeita a restrição de não declarar variáveis locais e não utilizar `structs`, realizando todos os acessos via deslocamento de bytes.
* **Estabilidade de Hardware:** O sistema recalcula os ponteiros após cada realocação, evitando acessos a endereços inválidos (ponteiros pendentes).

### O que não funciona / Limitações:
* **Persistência de Dados:** Como o foco do trabalho é a gestão de memória em tempo de execução, os dados não são salvos em arquivos físicos (como `.txt` ou `.bin`). Ao fechar o programa, a agenda é limpa.
* **Interface:** A interface é via terminal (CLI) simplificada, sem suporte a caracteres especiais complexos ou interface gráfica, priorizando a lógica de backend.
* **Ordenação Automática:** Os contatos são inseridos na ordem em que são digitados; o sistema não realiza a ordenação alfabética automática dos registros no buffer.

# Como compilar e executar
O projeto foi estruturado para facilitar a compilação. Para compilar e rodar, utilize os comandos no terminal:

```bash
# Para compilar o projeto
mingw32-make

# Para executar a agenda
.\output\main.exe

# Uso de IA
Usei Inteligência Artificial para corrigir um bug do dr memory e alguns erros de compilação do vscode. 

## Nota sobre os arquivos de código
O repositório contém dois arquivos principais de código-fonte (na pasta src)
* `main.c`: O código original desenvolvido e demonstrado no vídeo de explicação.
* `AgendaDoom3.c`: Um arquivo extra contendo a **exata mesma lógica de funcionamento**, porém refatorado e formatado seguindo rigorosamente o padrão de código da *id Software (Doom 3 / id Tech 4)*, aplicado como um desafio adicional de legibilidade e estilo.
