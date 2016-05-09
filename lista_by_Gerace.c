#include <stdio.h>
#include <stdlib.h>


typedef char DATO;
struct linked_list
{
    DATO d;
    struct list *next;
};

typedef struct linked_list ELEMENTO;
typedef ELEMENTO *LINK;

LINK /*struct typedef*/ l(char s[])
{

    LINK head = NULL, tail;
    int i;
    if(s[0] != '\0')
    {
        head = malloc(sizeof(ELEMENTO));
               head -> d = s[0];
    }
    tail = head;
    for(i=0; s[i]!= '\0'; i++)
    {
        tail -> next = malloc(sizeof(ELEMENTO));
        tail = tail -> next;
        tail -> d= s[i];
    }
    tail -> next = NULL;

    return head;
} LINK;

int conta(LINK head)
{

    if (head == NULL)
        return 0;
    else
        return (1+conta(head -> next));
}

int conta_it (LINK head)
{

    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head-> next;

    }
    return count;
}

