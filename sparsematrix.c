#include <stdio.h>
int T[100][3];
int T1[100][3];
void display(int *A, int m, int n)
{
    printf("\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("\t%d", *A++);
        printf("\n");
    }
    printf("\n");
}

void accept(int *A, int m, int n)
{
    printf("\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &*(A++));
        }
    printf("\n");
}

void convert(int *A, int m, int n)
{
    T[0][0] = m;
    T[0][1] = n;
    int k = 1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (*(A) != 0)
            {
                T[k][0] = i;
                T[k][1] = j;
                T[k++][2] = *A;
            }
            *(A++);
        }
    T[0][2] = k - 1;

    display(T[0], k, 3);
}

void fastTranspose()
{
    int Result[100][3], total[50], index[50];
    for (int i = 0; i < T[0][1]; i++)
        total[i] = 0;
    for (int i = 1; i < T[0][2]; i++)
        total[T[i][1]]++;
    index[0] = 1;
    for (int i = 1; i < T[0][1]; i++)
        index[i] = index[i - 1] + total[i - 1];
    Result[0][0] = T[0][1];
    Result[0][1] = T[0][0];
    Result[0][2] = T[0][2];
    for (int i = 1; i < T[0][2]; i++)
    {
        int loc = index[T[i][1]];
        Result[loc][0] = T[i][1];
        Result[loc][1] = T[i][0];
        Result[loc][2] = T[i][2];
        index[T[i][1]]++;
    }
    for (int i = 0; i <= Result[0][2]; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("\t%d", Result[i][j]);
        }
        printf("\n");
    }
}

void addition(int *A, int m, int n)
{
    int addition[100][3];
    int c1 = 1, c2 = 1, cm = 0;
    // accept(S1[0], m, n);
    int S1[4][4] = {
        {0,0,1,2},
        {7,0,0,0},
        {0,3,0,2},
        {9,0,0,1},
    };
    convert(S1[0], m, n);
    addition[0][0] = m;
    addition[0][1] = n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int flag = 0;
            if (T[c1][0] == i && T[c1][1] == j)
            {
                cm++;
                addition[cm][0] = i;
                addition[cm][1] = j;
                addition[cm][2] = T[c1][2];
                c1++;
                flag = 1;
            }
            if (T1[c2][0] == i && T1[c2][1] == j)
            {
                if (!flag)
                {
                    cm++;
                    addition[cm][2] = 0;
                }
                addition[cm][0] = i;
                addition[cm][1] = j;
                addition[cm][2] += T1[c2][2];
                c2++;
            }
        }
    }
    addition[0][2] = cm;
    display(addition[0], cm +1 , 3);
}

int main()
{
    int m, n;
    printf("Enter no. of rows and columns : ");
    scanf("%d%d", &m, &n);
    int S[4][4] = {
        {0,0,1,2},
        {7,0,0,0},
        {0,3,0,2},
        {9,0,0,1},
    };
    while (1)
    {
        int choice = 0;
        printf("1. Accept\n2. Display\n3. Convert\n4. FastTranspose\n5. Addition\n6. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            accept(S[0], m, n);
            break;
        case 2:
            display(S[0], m, n);
            break;
        case 3:
            convert(S[0], m, n);
            break;
        case 4:
            fastTranspose();
            break;
        case 5:
            addition(S[0], m, n);
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice");
        }
    }

    return 0;
}