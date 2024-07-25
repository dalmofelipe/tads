## TADs - Tipos Abstratos de Dados em C

```sh
git clone https://github.com/dalmofelipe/tads
cd tads
```
__Necessário compilador GCC__

```sh
sudo apt update
sudo apt install build-essential
```

<details>
<summary><h3>Pilha Encadeada</h3></summary>

### Compile & Run

```sh
gcc pilha.c -o pilha && ./pilha
```

Uma **Pilha Encadeada Sem Nó Cabeça** é uma estrutura de dados que representa uma pilha (FILO - First In, Last Out) usando nós encadeados, mas sem um nó especial chamado de "cabeça" ou "sentinela".

### Estrutura

- ```Nós```: Cada elemento da pilha é armazenado em um nó que contém um valor (ou dados) e um ponteiro para o próximo nó na pilha.
- ```Topo```: A pilha mantém uma referência apenas ao nó no topo, que é o elemento mais recentemente adicionado. 
- ```Sem Nó Cabeça```: Diferentemente de algumas implementações que utilizam um nó cabeça como um marcador ou sentinela para simplificar operações, esta estrutura não utiliza esse nó extra. 

### Operações

1. **Empilha (Inserção)**: 
   - Um novo nó é criado e adicionado ao topo da pilha.
   - O ponteiro do novo nó aponta para o nó que era o topo anteriormente.
   - A referência do topo é atualizada para este novo nó.
2. **Desempilha (Remoção)**: 
   - O nó no topo da pilha é removido.
   - A referência do topo é atualizada para o nó seguinte.
   - Se a pilha está vazia (topo é `null`), nenhuma operação é realizada.
3. **Peek (Consulta do Topo)**:
   - Retorna o valor do nó no topo sem removê-lo da pilha.
   - Se a pilha estiver vazia, pode retornar `null` ou lançar uma exceção, dependendo da implementação.
4. **Pilha_Vazia (Verificação de Vazio)**:
   - Verifica se a referência do topo é `null` e tamanho igual a 0, indicando que a pilha está vazia.
5. **Imprime_Pilha**:
   - Imprime a Pilha partindo do topo até o primeiro nó inserido.
6. **Drop_Pilha**:
   - Limpa toda memoria alocada

</details>


<details>
<summary><h3>Fila Encadeada</h3></summary>

### Compile & Run

```sh
gcc fila.c -o fila && ./fila
```

Uma fila é uma estrutura de dados que segue o princípio FIFO (First In, First Out), ou seja, o primeiro elemento adicionado à fila será o primeiro a ser removido. A fila é análoga a uma fila de pessoas em um banco, onde as pessoas são atendidas na ordem em que chegam.

### Características Principais da Fila
Ordem de Processamento: Os elementos são processados na ordem em que foram adicionados, com o primeiro elemento sendo o primeiro a sair.

__Dois Pontos de Acesso__:
- ```Frente (front)```: Onde os elementos são removidos.
- ```Traseira (rear)```: Onde os elementos são adicionados.
- ```Uso Comum```: Filas são amplamente utilizadas em sistemas de processamento de dados, onde a ordem de chegada dos dados precisa ser mantida, como em filas de impressão, processamento de tarefas em sistemas operacionais, etc.

### Operações Básicas da Fila
As operações principais que podem ser realizadas em uma fila são:

1. **Enfileirar**: 
   - Adiciona o elemento x ao final da fila.
   - Aumenta o tamanho da fila.
2. **Desenfileirar**:
   - Remove e retorna o elemento na frente da fila.
   - Diminui o tamanho da fila.
   - Retornar um valor especial se a fila estiver vazia.
3. **Consulta_Fila**:
   - Retorna o elemento na frente da fila sem removê-lo.
4. **Fila_Vazia**:
   - Verifica se a fila está vazia.
5. **Drop_Fila**:
   - Limpa toda FILA desalocando memoria usada

</details>
