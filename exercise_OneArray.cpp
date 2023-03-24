/*2차원 배열에 대한 행렬 더하기
C++ 2차 과제로 2차원 배열을 1차원 배열로 데이터 입력, add, multiply
1. getMatrix(row, col)에서 행렬 row x col 메모리를 할당, 난수 값 입력
2. add(a, b)는 a = a + b로 계산
3. multiply(a, b, c)는 c = a x b로 구현
*/
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#define MaxCounts 30
#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5
#define DROWS 3
#define DCOLS 5
// int getMatrix(int[], int); // 난수 생성하여 처리 - pointer만 사용하여 구현
bool showMatrix(int[], int, int);
int *addMatrix(int a[], int, int, int b[], int, int); // a = a + b를 계산하고 a를 return
int *getMatrix(int, int);
int *multiplyMatrix(int a[], int, int, int b[], int, int, int c[], int, int); // c = a * b를 계산하고 c를 return
bool freeMatrix(int[], int, int);
int main()
{
    srand(time(NULL));

    int *a, *a1, *a2, *a3, *b, *c, *d;
    a3 = NULL;
    c = NULL;
    d = NULL;

    a = getMatrix(AROWS, ACOLS);
    a1 = getMatrix(AROWS, ACOLS);
    a2 = getMatrix(AROWS, ACOLS);
    showMatrix(a, AROWS, ACOLS);
    showMatrix(a1, AROWS, ACOLS);
    showMatrix(a2, AROWS, ACOLS);
    showMatrix(a3, AROWS, ACOLS);

    a3 = addMatrix(addMatrix(a, AROWS, ACOLS, a1, AROWS, ACOLS), AROWS, ACOLS, a2, AROWS, ACOLS);
    showMatrix(a3, AROWS, ACOLS);
    b = getMatrix(BROWS, BCOLS);
    showMatrix(b, BROWS, BCOLS);
    c = getMatrix(BROWS, BCOLS);
    showMatrix(c, BROWS, BCOLS);
    d = multiplyMatrix(a, AROWS, ACOLS, b, BROWS, BCOLS, c, CROWS, CCOLS);
    showMatrix(c, CROWS, CCOLS);
    showMatrix(d, DROWS, DCOLS);

    freeMatrix(a, AROWS, ACOLS);
    freeMatrix(a1, AROWS, ACOLS);
    freeMatrix(a2, AROWS, ACOLS);
    freeMatrix(b, BROWS, BCOLS);
    freeMatrix(c, CROWS, CCOLS);
    system("pause");
    return 1;
}

int *getMatrix(int rows, int cols)
{
    int *arr = (int *)calloc(rows * cols, sizeof(int));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            *(arr + (i * cols) + j) = rand() % 10; // 계산식 수정 필요
        }
    }
    return arr;
}

int *addMatrix(int a[], int rows, int cols, int b[], int rows1, int cols1)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            *(a + (i * cols) + j) = *(a + (i * cols) + j) + *(b + (i * cols) + j);
        }
    }
    return a;
}

int *multiplyMatrix(int a[], int ar, int ac, int b[], int br, int bc, int c[], int cr, int cc)
{
    if (ac != br)
    {
        return 0;
    }

    for (int i = 0; i < cr; i++)
    {
        for (int j = 0; j < cc; j++)
        {
            *(c + (i * cc) + j) = 0;
        }
    }

    for (int i = 0; i < ar; i++)
    {
        for (int j = 0; j < bc; j++)
        {
            for (int k = 0; k < ac; k++)
            {
                *(c + (i * bc) + j) += *(a + (i * ac) + k) * *(b + j + (bc * k));
            }
        }
    }
    return c;
}

bool showMatrix(int a[], int rows, int cols)
{
    if (a == NULL)
    {
        return false;
    }
    printf("\n");
    printf(" matrix row = %d, col = %d\n", rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%4d", *(a + (i * cols) + j));
        }
        printf("\n");
    }
    return true;
}

bool freeMatrix(int a[], int rows, int cols)
{
    if (a == NULL)
    {
        return false;
    }
    free(a);
    return true;
}
