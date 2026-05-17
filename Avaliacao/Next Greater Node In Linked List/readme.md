# Trabalho Prático AED 1 - Next Greater Node In Linked List

## Informações do Aluno
* **Nome:** Suelen Heling Beduhn
* **Disciplina:** Algoritmos e Estruturas de Dados 1 (AED 1)
* **Problema:** [LeetCode 1019 - Next Greater Node In Linked List]

---

## Estrutura do Repositório (Arquivos)
* `main.c`: Código desenvolvido em sala de aula (versão inicial). Contém os erros lógicos de ponteiros e vazamento de memória discutidos na explicação.
* `Doom3.c`: Código feito em casa. Totalmente refatorado seguindo rigorosamente o **Estilo de Código do Doom 3**, com a memória gerenciada corretamente e pronto para submissão.

---

## O que Funciona e O que Não Funciona (Honestidade)
* **O que funciona:** A lógica do algoritmo implementado em `Doom3.c` funciona perfeitamente para encontrar o próximo nó maior. A alocação dinâmica está totalmente correta, passando pelo Validador de Memória (Dr. Memory) com **0 bytes de vazamento (leaks)**. A formatação do Doom 3 foi rigorosamente aplicada. O código passou em todos os testes do LeetCode.
* **O que não funciona (Limitação/Erros na versão inicial):** A versão inicial (`main.c`) possui erros de compilação e *Segmentation Fault* por falhas na passagem de ponteiros (`returnSize`) e vazamento de memória (falta de `free`). Além disso, a complexidade do algoritmo final é $O(N^2)$, o que significa que ele resolve o problema, mas não é a solução mais performática possível para listas gigantescas.

---

## Casos Testados com Sucesso
Testei os seguintes casos localmente e no botão *Submit* do LeetCode:

1. **Caso 1 (Teste Principal do Vídeo):**
   * **Entrada:** `head = [2, 1, 5]`
   * **Saída:** `[5, 5, 0]`
2. **Caso 2:**
   * **Entrada:** `head = [2, 7, 4, 3, 5]`
   * **Saída:** `[7, 0, 5, 5, 0]`
3. **Caso 3 (Lista Decrescente):**
   * **Entrada:** `head = [5, 4, 3, 2, 1]`
   * **Saída:** `[0, 0, 0, 0, 0]`

*(No vídeo, mostro o resultado verde de "Accepted" após o submit no LeetCode).*

---


## Dificuldades e Uso de IA
* **Dificuldades:** Minha maior dificuldade inicial foi entender por que o programa quebrava com *Segmentation Fault* na hora de retornar o array, e como mapear os ponteiros para uma estrutura mais fácil de ler. Outro desafio foi caçar os vazamentos de memória usando as ferramentas certas no Windows.
* **Uso de Inteligência Artificial:** Utilizei IA para duas coisas principais:
  1. Ajudar a traduzir meu código funcional para o **padrão de formatação do Doom 3** (ajustando chaves, espaçamentos nos parênteses, camelCase de variáveis e sufixo `_t` nas structs).
  2. Entender os erros do compilador quando não desreferenciei o ponteiro `*returnSize` corretamente e como ler os relatórios gerados pelo **Dr. Memory** para confirmar que os `free()` estavam corretos.

---

## Complexidade do Algoritmo
* **Complexidade de Tempo:** $O(N^2)$ - Como primeiro converti a lista para um vetor e depois usei dois laços `for` aninhados (força bruta) para procurar o próximo elemento maior, no pior dos casos (uma lista em ordem decrescente), o algoritmo verifica todos os elementos subsequentes para cada número.
* **Complexidade de Espaço:** $O(N)$ - Aloquei dois arrays dinâmicos do tamanho exato da lista encadeada (um para os `valores` da lista e outro para a `resp`), o que consome memória proporcional ao número de elementos.

---

## Comparação com a Solução do Editorial
No editorial do LeetCode (e em discussões da comunidade), a solução mais otimizada utiliza uma estrutura de dados chamada **Pilha Monotônica (Monotonic Stack)**.
* **Minha Solução:** Converte para vetor e usa dois loops. Tempo $O(N^2)$. É mais intuitiva e fácil de implementar inicialmente.
* **Solução do Editorial:** Utiliza uma pilha para guardar os índices dos elementos que ainda não encontraram um número maior. Ela percorre a lista apenas uma vez, empilhando e desempilhando. Tempo $O(N)$.
* **Conclusão:** Minha solução é correta e passa nos testes, mas gasta mais tempo de processamento. A solução com pilha seria o próximo passo ideal de otimização no estudo de Estruturas de Dados.