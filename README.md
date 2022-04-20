# Truth-Table
Este repositório contém o trabalho prático 1 de programação, desenvolvidos durante o primeiro semestre de 2022:
- trabalho pratico 1: Tabela da Verdade 
    - O trabalho foi desenvolvido em C++.

Este trabalho tem como objetivo construir um interpretador de proposições compostas
Ao executar o programa, o usuário deve inserir como entrada uma fórmula com algum conectivo. Como resultado será gerada a tabela da verdade de uma a três proposições passadas como entrada

___OBS: 
Para Três proposições o programa funciona sob o criterio de (p OPERACAO q) operacao r ou seja executa primeiro oq ta no parenteses e depois faz com o de fora;___

## Compilação
- necessario ter um compilador de C++ instalado
    - executar pelo terminal do windows\linux 
    - ir até o diretorio do codigo fonte e digitar
<pre>
    g++ .\main.cpp -o .\main.exe && .\main.exe
</pre>
- Uma alternativa mais simples é utilizar o VSCode/CodeBlocks ou qualquer outra IDE com C++ configurado. 

## Operações aceitas:
<pre>
______________________________________________________
|________Operações______|__________Operadores________|
|      NEGAÇÃO:         |   [!]   |    [~]  |   [N]  | 
|      CONJUNÇÃO:       |   [&]   |    [^]  |   [E]  | 
|      DISJUNÇÃO:       |   [|]   |    [v]  |   [O]  | 
|      IMPLICAÇÃO:      |   [>]   |    [-]  |   [I]  | 
|      BICONDICIONAL:   |   [<]   |    [=]  |   [D]  |
------------------------------------------------------
</pre>

## Exemplo de Funcionamento
1. Ao compilar:
<pre>
_________________________________________________________
|               TRUTH TABLE GENERATOR                   |
|-------------------------------------------------------|
|   OBS:                                                |
|   1. MAXIMO de TRES proposições                       |
|   2. Usar Letra MAISCULA entre ESPAÇOS na operação    |
|      ex: P ^ Q; P V Q; P = Q;                         |
|   3. UMA proposição apenas a NEGAÇÃO sera apresentada |
|   4. operação de NEGAÇÃO para DUAS ou MAIS proposições|
|      retorna apenas a negação da PRIMEIRA             |
|   5. Não usar ACENTUAÇÃO nas proposições              |
|       OPERAÇÕES ACEITAS:                              |
|       SAIR:                           [FIM]           |
|       NEGAÇÃO:               [!],      [~],     [N]   |
|       CONJUNÇÃO:             [&],      [^],     [E]   |
|       DISJUNÇÃO:             [|],      [v],     [O]   |
|       IMPLICAÇÃO:            [>],      [-],     [I]   |
|       BICONDICIONAL:         [<],      [=],     [D]   |
|-------------------------------------------------------|
Digite as PROPOSIÇÃO com a/as OPERAÇÕES:
</pre>
2. Entrando com 1 proposição APENAS a NEGAÇÃO é efetuada
<pre>
Digite as PROPOSIÇÃO com a/as OPERAÇÕES: mesa
|=======================================|
|      mesa     |         ¬mesa
|=======================================|
|       F       |           V
|       V       |           F
|=======================================|
</pre>
3. Entrando com 2 proposições e o operador de Disjunção
<pre>
Digite as PROPOSIÇÃO com a/as OPERAÇÕES: Caderno | Corrimão
|===========================================================|
|       Caderno |       Corrimo |       Caderno ∨ Corrimo
|===========================================================|
|       F       |       F       |            F
|       F       |       V       |            V
|       V       |       F       |            V
|       V       |       V       |            V
|===========================================================|
</pre>

4. Entrando com 3 variaveis e duas operações:
<pre>
Digite as PROPOSIÇÃO com a/as OPERAÇÕES: Cao | Gato - MMoney
|===============================================================================|
|       Cao     |       Gato    |       MMoney  |    (Cao ∨ Gato) ➔  MMoney
|===============================================================================|
|       F       |       F       |       F       |       F       |       V
|       F       |       F       |       V       |       F       |       V
|       F       |       V       |       F       |       V       |       F
|       F       |       V       |       V       |       V       |       V
|       V       |       F       |       F       |       V       |       F
|       V       |       F       |       V       |       V       |       V
|       V       |       V       |       F       |       V       |       F
|       V       |       V       |       V       |       V       |       V
|===============================================================================|
</pre>

## PRINTS DE EXECUÇÃO 
### 2 PROPOSIÇÕES
<img src = "https://github.com/eriklemy/Truth-Table/blob/main/prints/print_Execucao_2variaveis.png?raw=true">

### 3 PROPOSIÇÕES
<img src = "https://github.com/eriklemy/Truth-Table/blob/main/prints/print_Execucao_2variaveis.png?raw=true">

