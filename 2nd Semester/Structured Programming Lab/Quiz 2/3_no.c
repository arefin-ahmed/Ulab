#include <stdio.h>

int main()
{
    int n, m;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &n, &m);

    int arr[n][m];

    printf("Enter array elements:");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int min = arr[0][0];
    int minn = 0, minm = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
                minn = i;
                minm = j;
            }
        }
    }

    printf("Minimum value of array: %d\n", min);
    printf("It's position: arr[%d][%d]\n", minn, minm);

    return 0;
}