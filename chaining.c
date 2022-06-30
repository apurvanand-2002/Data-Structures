#include <stdio.h>
#include <stdlib.h>
/*Chaining is a method of open hashing in which memory from outside can also be used
and hence, we make nodes outside the pointer array.*/
struct node
{
    int data;
    struct node *next;
};
int position(int key)
{
    return key % 10;
}
void sorted_insert(struct node **H, int key)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    (*(t)).data = key;
    (*(t)).next = NULL;
    struct node *q = NULL;
    struct node *p = (*(H));
    if ((*(H)) == NULL)
    {
        (*(H)) = t;
    }
    else
    {
        while (p != NULL && (*(p)).data < key)
        {
            q = p;
            p = (*(p)).next;
        }
        if (p == (*(H)))
        {
            (*(t)).next = (*(H));
            (*(H)) = t;
        }
        else
        {
            (*(t)).next = (*(q)).next;
            (*(q)).next = t;
        }
    }
}
void insert(struct node *H[], int key)
{
    int index = position(key);
    sorted_insert(&H[index], key);
}
struct node *search(struct node **p, int num)
{
    if (*p == NULL)
    {
        return NULL;
    }
    else
    {
        while (*p != NULL)
        {
            if ((*(*p)).data != num)
            {
                *p = (*(*p)).next;
            }
            else
            {
                return *p;
            }
        }
        return NULL;
    }
}
int main()
{
    struct node *P[10];
    insert(P, 12);
    insert(P, 22);
    insert(P, 42);
    struct node *location;
    location = search(&P[position(42)], 42);
    printf("%d ", (*(location)).data);
}