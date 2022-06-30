#include <stdio.h>
#define size 10
int position(int key)
{
    return key % 10;
}
int probing(int H[], int key)
{
    int index = position(key);
    int i = 0;
    while (H[(index + (i * i)) % size] != 0)
    {
        i++;
    }
    return (index + (i * i)) % size;
}
void insert(int H[], int key)
{
    int index = position(key);
    if (H[index] == 0)
    {
        H[index] = key;
    }
    else
    {
        index = probing(H, key);
        H[index] = key;
    }
}
int search(int H[], int key)
{
    int i = 0;
    int index = position(key);
    if (H[index] == key)
    {
        return index;
    }
    else
    {
        while (H[(index + (i * i)) % size] != key)
        {
            if (H[(index + (i * i)) % size] == 0)
            {
                return (-1);
                break;
            }
            i++;
        }
        return (index + (i * i)) % size;
    }
}
int main()
{
    int HT[10] = {0};
    insert(HT, 23);
    insert(HT, 43);
    insert(HT, 13);
    insert(HT, 27);
    printf("Key is present at index:%d.\n", search(HT, 27));
}