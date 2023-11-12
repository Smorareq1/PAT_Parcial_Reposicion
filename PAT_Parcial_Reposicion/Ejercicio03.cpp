#include "Ejercicio03.h"

Node<int>* Ejercicio03::detectCycle(Node<int>* head)
{
    Node<int>* corto = head;
    Node<int>* large = head;

    while (corto != nullptr && large != nullptr && large->next != nullptr) {
        corto = corto->next;
        large = large->next->next;

        if (corto == large) {
            break; //Hay ciclo
        }
    }

    if (large == nullptr || large->next == nullptr) {
        return nullptr; // no hay ciclo
    }

    corto = head;

    while (corto != large) {
        corto = corto->next;
        large = large->next;
    }

    return large;
}
