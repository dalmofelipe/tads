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
<summary><h3>Pilha Encadeada Sem Nó Cabeça</h3></summary>

__Compile & Run__

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

### Vantagens e Desvantagens

**Vantagens:**
- **Simplicidade**: Sem o nó cabeça, a implementação pode ser mais direta e economiza memória ao não utilizar o nó extra.
- **Dinâmica**: Como é baseada em nós encadeados, a pilha pode crescer e encolher conforme necessário, sem um limite fixo de tamanho.

**Desvantagens:**
- **Complexidade nas Operações**: Algumas operações podem ser um pouco mais complexas, já que não há nó cabeça para lidar com casos especiais (como a remoção do último nó).
- **Potencial de Erros**: Pode haver uma maior chance de erros de implementação, especialmente se a manipulação do topo não for feita corretamente.

</details>