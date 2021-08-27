# Revisão de Lab de Prog II

Implementar em C uma calculadora que utiliza duas pilhas para realizar as suas operações.
Uma das pilhas deve armazenar os valores que farão parte das operações (pilha de valores reais), e a outra deve armazenar os operadores (pilha de caracteres sendo que os valores possíveis são: +, -, *, /).

  A pilha que armazenará os valores do tipo real deve ser implementada utilizando um vetor
  de reais de 20 posições. A pilha que armazenará os operadores deve ser implementada utilizando uma lista simplesmente encadeada.
  A calculadora deve oferecer as seguintes opções para o usuário:

              1- Empilhar valor do tipo real. Essa operação consiste em solicitar um valor para o usuário e colocá-lo no topo da pilha de reais.

              2- Empilhar operador. Essa operação consiste em solicitar um operador para o usuário,verificar se o caractere digitado é um operador válido e colocá-lo no topo da pilha de caracteres.

              3- Realizar cálculo. Quando o usuário selecionar a opção de realizar um cálculo, o programa deverá desempilhar dois valores da pilha de reais e um operador da pilha de caracteres, realizar a operação entre os mesmos e empilhar o resultado obtido na pilha de reais. Para a realização do cálculo é necessário que existam pelo menos dois valores armazenados na pilha de reais.

              4- Imprimir pilhas. Imprimir ambas as pilhas (em linhas separadas). 
