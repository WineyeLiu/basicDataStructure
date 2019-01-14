#include "stack.h"
#include <stdio.h>

static int stringlen(char *);
int main(void)
{
    char input1[] = "{[()]{[{{()}}][()]}}";
    int i;

    Stack s = NewStack();
    for (i = 0; i < stringlen(input1); i++)
    {
        char ch = input1[i];
        if(ch == '{' || ch == '[' || ch == '(') {
            switch (ch)
            {
                case '{':
                    Push(&s, CURLY_LEFT);
                    break;
                case '[':
                    Push(&s, SQUARE_LEFT);
                    break;
                case '(':
                    Push(&s, PARENTHESE_LEFT);
                    break;
                default:
                    break;
            }
        }
        if(ch == '}' && s.head->b == CURLY_LEFT)
        {
            Pop(&s);
        } else if(ch == '}' && s.head->b != CURLY_LEFT)
        {
            printf("num %d bracket \"}\" err.\n", i+1);
        }
        if(ch == ']' && s.head->b == SQUARE_LEFT)
        {
            Pop(&s);
        } else if(ch == ']' && s.head->b != SQUARE_LEFT)
        {
            printf("num %d bracket \"]\" err.\n", i+1);
        }
        if(ch == ')' && s.head->b == PARENTHESE_LEFT)
        {
            Pop(&s);
        } else if(ch == ')' && s.head->b != PARENTHESE_LEFT)
        {
            printf("num %d bracket \")\" err.\n", i+1);
        }
    }

    if(!Empty(s))
    {
        puts("Validate Failed!");
    } else 
    {
        puts("Validate Success!");
    }
}

static int stringlen(char * str)
{
    int count = 0;
    while (*(str++) != '\0')
    {
        count++;
    }
    return count;
}
