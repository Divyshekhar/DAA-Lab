#include <stdio.h>
#include <stdlib.h>
typedef struct SYMBOL 
{
    char alphabet;
    int frequency;
} SYMBOL;
typedef struct Node {
    SYMBOL symbol;
    struct Node *left, *right;
} Node;
Node* createNode(char alphabet, int frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->symbol.alphabet = alphabet;
    newNode->symbol.frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}
typedef struct PriorityQueue {
    Node** array;
    int size;
    int capacity;
} PriorityQueue;
PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    pq->capacity = capacity;
    pq->array = (Node**)malloc(capacity * sizeof(Node*));
    return pq;
}
void swapNodes(Node** a, Node** b) {
    Node* t = *a;
    *a = *b;
    *b = t;
}
void minHeapify(PriorityQueue* pq, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < pq->size && pq->array[left]->symbol.frequency < pq->array[smallest]->symbol.frequency)
        smallest = left;

    if (right < pq->size && pq->array[right]->symbol.frequency < pq->array[smallest]->symbol.frequency)
        smallest = right;

    if (smallest != idx) {
        swapNodes(&pq->array[smallest], &pq->array[idx]);
        minHeapify(pq, smallest);
    }
}
int isSizeOne(PriorityQueue* pq) {
    return (pq->size == 1);
}
Node* extractMin(PriorityQueue* pq) {
    Node* temp = pq->array[0];
    pq->array[0] = pq->array[pq->size - 1];
    --pq->size;
    minHeapify(pq, 0);
    return temp;
}
void insertMinHeap(PriorityQueue* pq, Node* minHeapNode) {
    ++pq->size;
    int i = pq->size - 1;

    while (i && minHeapNode->symbol.frequency < pq->array[(i - 1) / 2]->symbol.frequency) {
        pq->array[i] = pq->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    pq->array[i] = minHeapNode;
}
void buildMinHeap(PriorityQueue* pq) {
    int n = pq->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(pq, i);
}
int isLeaf(Node* root) {
    return !(root->left) && !(root->right);
}
Node* buildHuffmanTree(SYMBOL symbols[], int size) {
    Node *left, *right, *top;
    PriorityQueue* pq = createPriorityQueue(size);

    for (int i = 0; i < size; ++i)
        pq->array[i] = createNode(symbols[i].alphabet, symbols[i].frequency);

    pq->size = size;
    buildMinHeap(pq);

    while (!isSizeOne(pq)) {
        left = extractMin(pq);
        right = extractMin(pq);
        top = createNode('$', left->symbol.frequency + right->symbol.frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(pq, top);
    }
    return extractMin(pq);
}
void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        if (root->symbol.alphabet != '$') {
            printf("%c ", root->symbol.alphabet);
        }
        inorderTraversal(root->right);
    }
}

int main() {
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    SYMBOL symbols[n];
    printf("Enter the alphabets: ");
    for (int i = 0; i < n; ++i) {
        scanf(" %c", &symbols[i].alphabet);
    }

    printf("Enter its frequencies: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &symbols[i].frequency);
    }

    Node* root = buildHuffmanTree(symbols, n);

    printf("In-order traversal of the tree (Huffman): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

