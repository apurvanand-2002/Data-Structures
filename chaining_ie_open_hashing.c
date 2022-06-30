#include <stdio.h>
#include <stdlib.h>
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
    struct node *q = NULL;
    struct node *p = (*(H));
    t = (struct node *)malloc(sizeof(struct node));
    (*(t)).data = key;
    (*(t)).next = NULL;

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
        if (p == (*(H))) // if just after pointer array ,new node is to be inserted
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
struct node *search(struct node **p, int key)
{
    if (*p == NULL)
    {
        return NULL;
    }
    else
    {
        while (*p != NULL)
        {
            if ((*(*p)).data != key)
            {
                *p = (*(*p)).next;
            }
            return *p;
        }
    }
}
int main()
{
    struct node *HT[10]; // array of pointers
    struct node *p;
    for (int i = 0; i < 10; i++)
    {
        HT[i] = NULL;
    }
    /*We will insert numbers and those are to be stored in these 10 elements only.*/
    /*The name of array of pointers will be a pointer to a pointer.*/
    insert(HT, 12);
    insert(HT, 22);
    insert(HT, 42);
    p = search(&HT[position(22)], 22);
    printf("%d ", (*(p)).data);
}