#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *geraVetorDecrescente(int n)
{
    int i;
    int *A;
    A = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        A[i] = n - i;
    }
    return A;
}
int *geraVetorCrescente(int n)
{
    int i;
    int *A;
    A = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        A[i] = i;
    }
    return A;
}
void imprimeVetor(int *A, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void selecao(int n, int *v)
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
    int *array;

    int size, i, sorted, q;
    clock_t start;
    clock_t end;

    size = 2000;

    array = geraVetorDecrescente(size);

    start = clock();
    selecao(size, array);
    end = clock();
    imprimeVetor(array, size);

    printf("time: %lf\n", (double)(end - start) / (double)CLOCKS_PER_SEC);

    free(array);

    return 0;
}