#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

Node* createNode(int);
void insertFront(Node**, int);
void insertEnd(Node**, int);
void insertAfter(Node*, int);
void insertBefore(Node**, Node*, int);
void deleteNode(Node**, Node*);
void displayList(Node*);
Node* searchNodebyValue(Node**, int);
void deleteNodebyValue(Node**, int);

int main()
{
    Node* head = nullptr;
    displayList(head);
    cout << "======================" << endl;
    insertEnd(&head, 0);
    insertEnd(&head, 1);
    insertEnd(&head, 3);
    insertEnd(&head, 7);
    insertEnd(&head, 10);
    insertEnd(&head, 13);
    displayList(head);
    cout << "======================" << endl;
    insertFront(&head, 33);
    insertFront(&head, 24);
    insertFront(&head, 8);
    insertFront(&head, 15);
    insertFront(&head, 27);
    insertFront(&head, 42);
    displayList(head);
    cout << "======================" << endl;
    Node* insertAfterNode1 = head -> ptrNext;
    insertAfter(insertAfterNode1, 5); // Inserir após o segundo nó
    displayList(head);
    cout << "======================" << endl;
    Node* insertAfterNode2 = head -> ptrNext -> ptrNext -> ptrNext;
    insertAfter(insertAfterNode2, 9); // Inserir após o quarto nó
    displayList(head);
    cout << "======================" << endl;
    Node* insertAfterNode3 = head -> ptrNext -> ptrNext -> ptrNext -> ptrNext -> ptrNext;
    insertAfter(insertAfterNode3, 17); // Inserir após o sexto nó
    displayList(head);
    cout << "======================" << endl;
    Node* insertAfterNode4 = head -> ptrNext -> ptrNext -> ptrNext -> ptrNext -> ptrNext -> ptrNext ;
    insertAfter(insertAfterNode4, 41); // Inserir após o sétimo nó
    displayList(head);
    cout << "======================" << endl;
    Node* DeleteNode1 = head -> ptrNext -> ptrNext;
    deleteNode(&head, DeleteNode1);
    displayList(head);
    cout << "======================" << endl;
    Node* DeleteNode2 = head -> ptrNext -> ptrNext -> ptrNext;
    deleteNode(&head, DeleteNode2);
    displayList(head);
    cout << "======================" << endl;
    Node* DeleteNode3 = head -> ptrNext -> ptrNext -> ptrNext -> ptrNext;
    deleteNode(&head, DeleteNode3);
    displayList(head);
    cout << "======================" << endl;
    Node* DeleteNode4 = head -> ptrNext -> ptrNext -> ptrNext -> ptrNext;
    deleteNode(&head, DeleteNode4);
    displayList(head);
    cout << "======================" << endl;
    Node* insertBeforeNode1 = head;
    insertBefore(&head, insertBeforeNode1, 1); // Inserir antes do primeiro nó
    displayList(head);
    cout << "======================" << endl;
    Node* insertBeforeNode2 = head -> ptrNext;
    insertBefore(&head, insertBeforeNode2, 6); // Inserir antes do segundo nó
    displayList(head);
    cout << "======================" << endl;
    Node* insertBeforeNode3 = head -> ptrNext -> ptrNext -> ptrNext -> ptrNext;
    insertBefore(&head, insertBeforeNode3, 36); // Inserir antes do quinto nó
    displayList(head);
    cout << "======================" << endl;
    Node* insertBeforeNode4 = head -> ptrNext -> ptrNext -> ptrNext -> ptrNext -> ptrNext -> ptrNext -> ptrNext;
    insertBefore(&head, insertBeforeNode4, 82); // Inserir antes do oitavo nó
    displayList(head);
    cout << "======================" << endl;
    Node* foundNode1 = searchNodebyValue(&head, 7);
    if (foundNode1 != nullptr) {
        cout << "Nó com valor " << 7 << " encontrado!" << endl;
    } else {
        cout << "Nó com valor " << 7 << " não encontrado!" << endl;
    }
    cout << "======================" << endl;
    Node* foundNode2 = searchNodebyValue(&head, 45);
    if (foundNode2 != nullptr) {
        cout << "Nó com valor " << 45 << " encontrado!" << endl;
    } else {
        cout << "Nó com valor " << 45 << " não encontrado!" << endl;
    }
    cout << "======================" << endl;
    Node* foundNode3 = searchNodebyValue(&head, 15);
    if (foundNode3 != nullptr) {
        cout << "Nó com valor " << 5 << " encontrado!" << endl;
    } else {
        cout << "Nó com valor " << 5 << " não encontrado!" << endl;
    }
    cout << "======================" << endl;
    Node* foundNode4 = searchNodebyValue(&head, 67);
    if (foundNode4 != nullptr) {
        cout << "Nó com valor " << 67 << " encontrado!" << endl;
    } else {
        cout << "Nó com valor " << 67 << " não encontrado!" << endl;
    }
    cout << "======================" << endl;
    displayList(head);
    deleteNodebyValue(&head, 7);
    displayList(head);
    cout << "======================" << endl;
    displayList(head);
    deleteNodebyValue(&head, 15);
    displayList(head);
    cout << "======================" << endl;
    displayList(head);
    deleteNodebyValue(&head, 10);
    displayList(head);
    cout << "======================" << endl;
    displayList(head);
    deleteNodebyValue(&head, 1);
    displayList(head);
    cout << "======================" << endl;
 
    return 0;
}

Node* createNode(int iPayload)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp -> iPayload = iPayload;
    temp -> ptrNext = nullptr;
    temp -> ptrPrev = nullptr;
    
    return temp;
}

void displayList(Node* node)
{
    if (node == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar displayList" << endl;
        return;
    }
    
    if (node -> ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da lista: Não é possível realizar displayList" << endl;
        return;
    }
    
    Node* temp = node;
    
    cout << "Payload ";
    
    // Percorremos a lista até seu fim (ptrNext do último nó é NULL)
    while (temp != nullptr)
    {
        cout << temp -> iPayload << " ";
        temp = temp -> ptrNext;
    }
    
    cout << endl;
}

void insertFront(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);
    // newNode -> ptrPrev = nullptr;
    
    if (*head != nullptr)
    {
        (*head) -> ptrPrev = newNode;
        newNode -> ptrNext = (*head);
        (*head) = newNode;
        
        return;
    }
    
    (*head) = newNode;
}

void insertEnd(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);
    // newNode -> ptrNext = nullptr;
    
    if (*head == nullptr)
    {
        // newNode -> ptrPrev = nullptr;
        (*head) = newNode;
        return;
    }
    
    Node* temp = (*head);
    
    // Percorremos a lista até seu fim (ptrNext do último nó é NULL)
    while (temp -> ptrNext != nullptr) temp = temp -> ptrNext;
    
    newNode -> ptrPrev = temp; // newNode aponta para o fim da lista
    temp -> ptrNext = newNode; // Antigo último elemento aponta para o novo nó
}

void insertAfter(Node* ptrLocation, int iPayload)
{
    if (ptrLocation == nullptr)
    {
        cout << "location é NULL." << endl;
        
        return;
    }
    
    Node* newNode = createNode(iPayload);
    
    // Corrigir nó a ser inserido
    newNode -> ptrNext = ptrLocation -> ptrNext;
    newNode -> ptrPrev = ptrLocation;
    
    // Corrigir o ponto de inserção
    ptrLocation -> ptrNext = newNode;
    
    if (newNode -> ptrNext != nullptr) newNode -> ptrNext -> ptrPrev = newNode;
}

void deleteNode(Node** head, Node* ptrDelete)
{
    if (*head == nullptr || ptrDelete == nullptr)
    {
        cout << "Não foi possível remover." << endl;
        
        return;
    }
    
    // Caso o ptrDelete seja o primeiro elemento da lista
    if (*head == ptrDelete) (*head) = ptrDelete -> ptrNext;
    
    // Se o ptrDelete não é o último nó
    if (ptrDelete -> ptrNext != nullptr) ptrDelete -> ptrNext -> ptrPrev = ptrDelete -> ptrPrev;
    
    // Se o ptrDelete não é o primeiro nó
    
    if (ptrDelete -> ptrPrev != nullptr) ptrDelete -> ptrPrev -> ptrNext = ptrDelete -> ptrNext;
    
    free(ptrDelete);
}

void insertBefore(Node** head, Node* ptrLocation, int iPayload)
{
    if (ptrLocation == nullptr)
    {
        cout << "location é NULL." << endl;
        
        return;
    }
    
    Node* newNode = createNode(iPayload);
    
    // Se ptrLocation é o primeiro nó, newNode se torna o novo head
    if (ptrLocation -> ptrPrev == nullptr) 
    {
        newNode -> ptrNext = ptrLocation;
        ptrLocation -> ptrPrev = newNode;
        // Atualize a cabeça para apontar para o novo nó
        (*head) = newNode;
        
        return;
    }
    
    // Corrigir nó a ser inserido
    newNode -> ptrPrev = ptrLocation -> ptrPrev;
    newNode -> ptrNext = ptrLocation;
    
    // Corrigir o ponto de inserção
    ptrLocation -> ptrPrev = newNode;
    
    if (newNode -> ptrPrev != nullptr) newNode -> ptrPrev -> ptrNext = newNode;
}

Node* searchNodebyValue(Node** head, int value) {
    Node* current = (*head);

    // Percorre a lista até encontrar o nó com o valor desejado ou chegar ao final da lista
    while (current != nullptr) {
        if (current -> iPayload == value) {
            // Encontrou o nó com o valor desejado, retorna um ponteiro para esse nó
            return current;
        }
        current = current -> ptrNext;
    }

    // Se o valor não foi encontrado, retorna nullptr
    return nullptr;
}

void deleteNodebyValue(Node** head, int iData)
{
    Node* delNode = nullptr;

    if ((*head) == nullptr)
    {
        return;
    }

    for (Node* node = (*head); node != nullptr; node = node -> ptrNext)
    {
        if (node -> iPayload == iData)
        {
            delNode = node;
            break;
        }
    }

    if (delNode == nullptr)
    {
        return;
    }

    if (*head == delNode)
    {
        *head = delNode -> ptrNext;
    }

    if (delNode -> ptrPrev != nullptr)
    {
        delNode -> ptrPrev -> ptrNext = delNode -> ptrNext;
    }
    if (delNode -> ptrNext != nullptr) {
        delNode -> ptrNext -> ptrPrev = delNode -> ptrPrev;
    }

    free(delNode);
}
