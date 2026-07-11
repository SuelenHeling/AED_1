# Avaliação AED_1 - 4Sum II (LeetCode 454)

**Nome:** Suelen Heling Beduhn

## Sobre o Problema
O problema **454. 4Sum II** do LeetCode consiste em receber quatro arrays de inteiros (`nums1`, `nums2`, `nums3`, `nums4`), todos de mesmo tamanho `n`. O objetivo é retornar o número de tuplas `(i, j, k, l)` tais que:
* `0 <= i, j, k, l < n`
* `nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0`

## O que funciona e o que não funciona
* **Código feito em aula (`leetcode_454.c`):** Possui um erro lógico na **linha 21**. Durante o laço aninhado, a soma foi preenchida como `nums1[i] + nums2[i]`, utilizando o índice `i` duas vezes, quando o correto para acessar os elementos do segundo array no laço interno seria usar o índice `j`. Isso preenche o vetor de somas com valores incorretos.
* **Código feito em casa (`Doom3.c`):** Funciona perfeitamente. A lógica foi corrigida, adotando o padrão de formatação de código do *Doom 3*. O algoritmo calcula as somas, ordena utilizando `qsort`, e realiza uma busca binária (`O(log n)`) para encontrar os complementos. 
* **Gestão de Memória:** 100% funcional. O vetor alocado dinamicamente é devidamente liberado com `free`. A análise do `Valgrind` apontou `All heap blocks were freed -- no leaks are possible`.

## Casos Testados com Sucesso
1. **Caso Padrão 1:**
   * Entradas: `nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]`
   * Saída: `2` (Sucesso local e no LeetCode).
2. **Caso Padrão 2 (Zerado):**
   * Entradas: `nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]`
   * Saída: `1` (Sucesso no submit).
3. **Caso Negativos e Positivos:**
   * Entradas: `nums1 = [-1,-1], nums2 = [-1,1], nums3 = [-1,1], nums4 = [1,-1]`
   * Saída: `6` (Sucesso no submit).

*(A gravação em vídeo demonstra o código rodando no terminal e a submissão no LeetCode)*

## Uso de IA
Usei Inteligência Artificial pois ia usar o dr memory e não funcionou nesse pc, então tive que pedir ajuda para instalar e poder usar o valgrind em máquina virtual.