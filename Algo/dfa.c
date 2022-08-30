#include <stdio.h>
#include <string.h>

int f[20] = {0};

int check(char c[], int t[20][26][10], int ii, int tt)
{
    if (c[ii + 1] == '\0' && f[tt] == 1 && t[tt][c[ii] - 'a'][0] != -1)
        return 1;
    else if (c[ii] == '\0')
        return 0;
    int j = 1, jj = 0;
    for (j = 0; j < 3; j++)
    {
        if (t[tt][c[ii] - 'a'][j] != -1)
            jj |= check(c, t, ii + 1, t[tt][c[ii] - 'a'][j]);
    }
    return jj;
}

int main()
{

    int n, i, j, k, fi, input;
    printf("Enter the number of states\n");
    scanf("%d", &n);
    printf("Enter the number of input symbols\n");
    scanf("%d", &input);
    printf("Enter the number of final states\n");
    scanf("%d", &fi);
    printf("Enter the final states\n");
    for (i = 0; i < fi; i++)
    {
        scanf("%d", &j);
        f[j] = 1;
    }

    int t[20][26][10];
    printf("Enter the transition states\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < input; j++)
        {
            for (k = 0; k < 3; k++)
            {
                printf("q%d ,%c = ", i, j + 'a');
                scanf("%d", &t[i][j][k]);
                if (t[i][j][k] == -1)
                    break;
                printf("\n");
            }
        }
    }

    while (1)
    {
        printf("Enter the String to check ");
        char c[20];
        scanf("%s", c);
        fflush(stdout);
        i = 0;
        int cc = check(c, t, 0, 0);
        if (cc == 1)
            printf("ACCEPTED\n");
        else
            printf("REJECTED\n");
        printf("Enter -1 to exit and 1 to continue\n");
        int ff = 0;
        scanf("%d", &ff);
        if (ff == -1)
            break;
        else if (ff != 1)
            fflush(stdout);
    }
    return 0;
}