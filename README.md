# Trabalho Prático 3 — Projeto e Análise de Algoritmos  
Casamento de Padrões e Criptografia por Cifra de Deslocamento

Este trabalho aborda dois temas fundamentais no contexto de análise de algoritmos e processamento de cadeias de caracteres: o casamento exato de padrões em textos e a criptografia baseada em cifra de deslocamento. O projeto foi desenvolvido na disciplina de Projeto e Análise de Algoritmos (PAA) e tem como objetivo comparar algoritmos clássicos de busca de padrões, além de implementar técnicas básicas de criptografia e análise de frequência.

O sistema foi inteiramente implementado em linguagem C, com foco em modularização, análise de desempenho e manipulação eficiente de arquivos e strings.

## Organização do Projeto

O código está organizado de forma modular, dividido em dois diretórios principais:

- `headers/`: contém os arquivos de cabeçalho (.h), responsáveis pela definição das estruturas de dados e protótipos das funções.
- `sources/`: contém os arquivos de implementação (.c), onde estão as funções principais do projeto.

Além disso, o diretório raiz contém o arquivo `main.c`, o `Makefile`, os arquivos de entrada utilizados nos testes e os arquivos de saída gerados pelo programa.


## Tarefa A — Casamento Exato de Padrões

Na primeira parte do trabalho, foram implementados e comparados dois algoritmos clássicos de casamento exato de padrões em texto: Shift-And e Knuth-Morris-Pratt (KMP).

O algoritmo Shift-And utiliza operações bit a bit para processar múltiplos caracteres simultaneamente, sendo especialmente eficiente para padrões curtos. A implementação utiliza uma máscara de bits para cada caractere ASCII e mantém um estado que indica o progresso da busca ao longo do texto.

O algoritmo Knuth-Morris-Pratt (KMP) realiza um pré-processamento do padrão por meio do vetor LPS (Longest Prefix Suffix), evitando comparações redundantes durante a busca. Sua complexidade é linear em relação ao tamanho do texto e do padrão, o que o torna eficiente em buscas repetidas e padrões maiores.

Ambos os algoritmos foram testados utilizando arquivos de entrada e tiveram seus tempos de execução medidos com alta precisão.

Os resultados experimentais mostraram que o Shift-And apresentou menor tempo de execução nos testes realizados, devido ao tamanho reduzido dos padrões e à eficiência das operações bit a bit. Já o KMP se mostra mais vantajoso em cenários com padrões maiores ou buscas repetidas.

## Tarefa B — Criptografia por Cifra de Deslocamento

A segunda parte do trabalho implementa um sistema de criptografia e descriptografia baseado na cifra de deslocamento. O programa permite criptografar e descriptografar arquivos de texto a partir de uma chave fornecida pelo usuário, além de oferecer funcionalidades adicionais.

Entre as funcionalidades implementadas estão:
- criptografia de arquivos utilizando uma chave fixa;
- descriptografia utilizando a mesma chave;
- criptografia com chave aleatória;
- análise de frequência de caracteres;

O algoritmo de criptografia realiza o deslocamento modular dos caracteres visíveis da tabela ASCII, garantindo que espaços, pontuações e símbolos sejam preservados corretamente. A descriptografia desfaz o deslocamento aplicado durante a criptografia.

A análise de frequência calcula a distribuição percentual das letras no texto criptografado e compara esses valores com frequências conhecidas da língua portuguesa, estimando a chave mais provável utilizada no processo.

## Como Executar

A compilação do projeto é realizada por meio do Makefile. No terminal, dentro do diretório do trabalho, execute:

```bash
make
./programa
