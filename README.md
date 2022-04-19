# Truth-Table
Constrói a tabela da verdade de uma a três proposições passadas como entrada

OBS: para Três proposições o programa ainda não funciona corretamente
- Erick Lemmy dos Santos Oliveira

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
NEGAÇÃO:               [!],      [~],     [N]   
CONJUNÇÃO:             [&],      [^],     [E]   
DISJUNÇÃO:             [|],      [v],     [O]   
IMPLICAÇÃO:            [>],      [-],     [I]   
BICONDICIONAL:         [<],      [=],     [D] 
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
|      ex: P ^ Q; P V Q; P = Q                          |
|   3. UMA proposição apenas a NEGAÇÃO sera apresentada |
|   4. operação de NEGAÇÃO para DUAS ou MAIS proposições|
|     retorna apenas a negação da PRIMEIRA              |
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
|       mesa    |       ¬mesa
|=======================================|
|       F       |       V
|       V       |       F
|=======================================|
</pre>
3. Entrando com 2 proposições e o operador de Disjunção
<pre>
Digite as PROPOSIÇÃO com a/as OPERAÇÕES: Caderno | Corrimão
|===========================================================|
|       Caderno |       Corrimo |       Caderno ∨ Corrimo
|===========================================================|
|       F       |       F       |       F
|       F       |       V       |       V
|       V       |       F       |       V
|       V       |       V       |       V
|===========================================================|
</pre>

4. Entrando com 3 variaveis e duas operações 
Digite as PROPOSIÇÃO com a/as OPERAÇÕES: Chá - Tea = Hand
<pre>
|===============================================================================|
|       Ch      |       Tea     |       Hand    |       Ch ➔  Tea ➔  Hand
|===============================================================================|
|       F       |       F       |       F       |       V
|       F       |       F       |       V       |       V
|       F       |       V       |       F       |       V
|       F       |       V       |       V       |       V
|       V       |       F       |       F       |       F
|       V       |       F       |       V       |       F
|       V       |       V       |       F       |       V
|       V       |       V       |       V       |       V
|===============================================================================|
</pre>