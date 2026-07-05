# Avaliação - Algoritmos e Estruturas de Dados I

## Meus Dados
* **Nome:** Suelen Heling Beduhn
* **Problema:** 775 do LeetCode (Inversões Globais e Locais)

## Casos que Testei e Deram Certo
Aqui estão 3 exemplos que rodaram perfeitamente no meu código:
1. **Vetor [1, 0, 2]:** O resultado foi "verdadeira", pois tem 1 inversão global e 1 local.
2. **Vetor [1, 2, 0]:** O resultado foi "falsa", pois tem 2 inversões globais e apenas 1 local.
3. **Vetor [0, 1, 2]:** O resultado foi "verdadeira", pois tem 0 inversões globais e 0 locais.

## O que funciona e o que não funciona (Sendo Honesta)
* **O que funciona:** A lógica da Árvore AVL está certinha. Ela cria os nós, faz o balanceamento das folhas e conta as inversões corretamente. O código limpa toda a memória no final (usei o Dr. Memory e não teve vazamento). Além disso, o arquivo foi todo formatado seguindo as regras do PDF do Doom 3.
* **O que não funciona:** Quando o LeetCode joga um vetor gigante (com quase 100 mil números), o meu código dá a mensagem de "Tempo Limite Excedido". Isso acontece porque a Árvore AVL gasta muito tempo criando nós na memória para listas tão grandes. A lógica de contagem está certa, mas a plataforma do LeetCode exige um truque mais rápido para passar no teste de tempo.

## Uso de IA: 
Usei Intelingência Artificial para reformatar o código para o estilo de Doom 3 e para me ajudar a resolver uns problemas de compilação.

## Meus Arquivos
* `LeetCode_775.c`: Código que foi feito na aula.
* `Doom3.c`: Código que fiz em casa, usando a Árvore AVL e o padrão visual do Doom 3.

