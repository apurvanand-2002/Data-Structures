#include <stdio.h>
#define size 10
int position(int key)
{
    return key % 10;
}
int probe(int H[], int key)
{
    int i = 0;
    int index = position(key);
    while (H[(index + i) % size] != 0)
    {
        i++;
    }
    return (index + i) % size;
}
void insert(int H[], int key)
{
    int index = position(key);
    int i = 0;
    if (H[index] == 0)
    {
        H[index] = key;
    }
    else
    {
        index = probe(H, key);
        H[index] = key;
    }
}
int search(int H[], int key)
{
    int index = position(key);
    int i = 0;
    if (H[index] == key)
    {
        return index;
    }
    else
    {
        while (H[(index + i) % size] != key)
        {
            if (H[(index + i) % size] == 0)
            {
                return (-1);
                break;
            }
            i++;
        }
        return (index + i) % size;
    }
}
int main()
{
    int HT[10] = {0};
    insert(HT, 12);
    insert(HT, 25);
    insert(HT, 26);
    insert(HT, 35);
    printf("Key is found at index:%d.\n", search(HT, 26));
}
/*In linear probing,loading factor is maintained near 0.5 .*/