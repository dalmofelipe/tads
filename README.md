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
<br>

<details>
<summary>
   <strong>Pilha Encadeada</strong>
   <p><i>É uma estrutura de dados que segue o princípio FILO (First In, Last Out). Isso significa que o último elemento adicionado à pilha será o primeiro a ser removido. A pilha é utilizada em diversas aplicações que requerem esse tipo de comportamento, como a avaliação de expressões matemáticas, gerenciamento de chamadas de função (stack frames), e mais.</i></p>
</summary>

```sh
gcc pilha.c -o pilha && ./pilha
```
__Estrutura__
- ```Nós```: Cada elemento da pilha é armazenado em um nó que contém um valor (ou dados) e um ponteiro para o próximo nó na pilha.
- ```Topo```: A pilha mantém uma referência apenas ao nó no topo, que é o elemento mais recentemente adicionado. 
- ```Sem Nó Cabeça```: Diferentemente de algumas implementações que utilizam um nó cabeça como um marcador ou sentinela para simplificar operações, esta estrutura não utiliza esse nó extra. 

__Operações__
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
<summary>
   <strong>Fila Encadeada</strong>
   <p><i>É uma estrutura de dados que segue o princípio FIFO (First In, First Out), ou seja, o primeiro elemento adicionado à fila será o primeiro a ser removido. A fila é análoga a uma fila de pessoas em um banco, onde as pessoas são atendidas na ordem em que chegam. São amplamente utilizadas em sistemas de processamento de dados, onde a ordem de chegada dos dados precisa ser mantida, como em filas de impressão, processamento de tarefas em sistemas operacionais, etc.</i></p>
</summary>

```sh
gcc fila.c -o fila && ./fila
```

__Estrutura__
- ```Nós```: Cada elemento da fila é armazenado em um nó que contém um valor (ou dados) e um ponteiro para o próximo nó na fila.
- ```Inicio e Fim```: A fila mantém duas referências, uma para nó no inicio e outro para o fim da fila, onde o elemento mais recentemente adicionado pela fim da fila. 
- ```Sem Nó Cabeça```: Esta implementação não utiliza esse nó extra. 

__Operações__
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
