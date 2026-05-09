# Matriz Espiral II - LeetCode #59

**Autor:** Suelen Heling Beduhn - M2
**Problema:** LeetCode 59 - Spiral Matrix II

## Sobre o Problema
O objetivo é gerar uma matriz quadrada `n x n` preenchida com elementos de `1` a `n^2` em ordem espiral.

## O que funciona e o que não funciona (Honestidade)
- **Funciona:** A lógica de preenchimento em espiral, a alocação dinâmica da matriz, a impressão na tela e a liberação de memória (`free`). O código foi formatado seguindo o padrão da id Software (Doom 3).
- **Não funciona (ou pendências):** No código local, tudo roda perfeitamente. Nenhuma falha identificada. 
- **Ajuda de IA:** Utilizei IA (Gemini) para me ajudar a configurar o ambiente do VS Code (arrumar o path do terminal que não achava o arquivo), para entender o erro do GDB com pastas acentuadas.
## Casos de Teste Realizados

1. **Caso n = 1 (Matriz mínima):**
   - Entrada: `1`
   - Saída esperada: `[[1]]`
   - Resultado: Sucesso.

2. **Caso n = 3 (Tamanho ímpar):**
   - Entrada: `3`
   - Saída esperada: `[[1,2,3],[8,9,4],[7,6,5]]`
   - Resultado: Sucesso.

3. **Caso n = 5 (Tamanho maior):**
   - Entrada: `5`
   - Saída esperada: Uma matriz 5x5 girando de 1 a 25 perfeitamente no centro.
   - Resultado: Sucesso (mostrado em vídeo).

## LeetCode
O código foi submetido no LeetCode e aceito com sucesso (Resultado exibido no vídeo).