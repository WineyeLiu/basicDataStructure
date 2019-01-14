#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    Stack s = NewStack();
    Push(&s, CURLY_LEFT);
    Push(&s, CURLY_RIGHT);
    Push(&s, SQUARE_LEFT);
    Push(&s, SQUARE_RIGHT);
    printf("%p\n", s.head);
    while(!Empty(s)) {
        printf("%d\n", Pop(&s));
    }
    return 0;
}

Stack NewStack() {
    Stack s;
    s.head = NULL;
    s.size = 0;
    return s;
}

int Push(Stack * stack, Bracket bracket) {
    Node * node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        return 0;
    }
    node->b = bracket;
    node->next = stack->head;
    stack->head = node;
    stack->size++;
    return 1;
}

Bracket Pop(Stack * s) {
    Node * p = s->head;
    s->head = s->head->next;
    Bracket b = p->b;
    free(p);
    s->size--;
    return b;
}

int Empty(Stack s) {
    if(s.size = 0 || s.head == NULL)
    {
        return 1;
    }
    return 0;
}

int Size(Stack s) {
    return s.size;
}