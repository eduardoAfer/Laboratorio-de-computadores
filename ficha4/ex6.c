#include <stdio.h>
#include <stdlib.h>

void ordena(int n, int v[])
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
            if (v[j] < v[min])
                min = j;
        int x = v[i];
        v[i] = v[min];
        v[min] = x;
    }
}

int main()
{

    int *arr;
    int qnt_elem;

    scanf("%d", &qnt_elem);

    arr = (int*)(malloc(qnt_elem * sizeof(int)));
    for (int i = 0; i < qnt_elem; i++)
    {
        scanf("%d", &arr[i]);
    }
    ordena(qnt_elem, arr);

    for (int i = 0; i < qnt_elem; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            printf("%d\n", arr[i]);
            while (arr[i + 1] == arr[i + 2])
                i++;
        }
    }
    free(arr);

    return 0;
}