#include "Ejercicio01.h"


Node<int>* Ejercicio01::reverseLinkedList(Node<int>* head) { //reverse como en clase
    Node<int>* next = nullptr;
    Node<int>* prev = nullptr;
    Node<int>* current = head;


    while (current != nullptr) {
        Node<int>* nxt = current->next;
        current->next = prev;
        prev = current;
        current = nxt;
    }
    return prev;
}



Node<int>* Ejercicio01::Helper(Node<int>* l1, int sizeL1, Node<int>* l2, int sizeL2) {
    Node<int>* dummy = new Node<int>{ 0 };
    Node<int>* tail = dummy;
    int carry = 0;

    while (sizeL1 > 0 || sizeL2 > 0 || carry != 0) {
        int num1 = (sizeL1 > 0 && l1 != nullptr) ? l1->value : 0;
        int num2 = (sizeL2 > 0 && l2 != nullptr) ? l2->value : 0;

        int sum = num1 + num2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        Node<int>* newNode = new Node<int>{ digit };
        tail->next = newNode;
        tail = tail->next;

        // Mover a los nodos siguientes solo si hay nodos restantes
        if (sizeL1 > 0 && l1 != nullptr) {
            l1 = l1->next;
            sizeL1--;
        }
        if (sizeL2 > 0 && l2 != nullptr) {
            l2 = l2->next;
            sizeL2--;
        }
    }

    Node<int>* result = dummy->next;
    return result;
}





Node<int>* Ejercicio01::addTwoNumbers(Node<int>* l1, int sizeL1, Node<int>* l2, int sizeL2)
{
    l1 = reverseLinkedList(l1);
    l2 = reverseLinkedList(l2);


    Node<int>* result = Helper(l1, sizeL1, l2, sizeL2);



    return reverseLinkedList(result);
}