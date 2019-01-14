typedef enum bracket {
    CURLY_LEFT,
    CURLY_RIGHT,
    SQUARE_LEFT,
    SQUARE_RIGHT,
    PARENTHESE_LEFT,
    PARENTHESE_RIGHT
} Bracket;

typedef struct Node {
    Bracket b;
    struct Node * next;
} Node;

typedef struct stack {
    Node * head;
    int size;
} Stack;

extern Stack NewStack();

extern int Push(Stack *, Bracket);

extern Bracket Pop(Stack *);

extern int Empty(Stack);

extern int Size(Stack);