#include <stdio.h>
#include <string.h>

char X[10001];
char Z[101];
struct sol
{
    char n[10001];
};

struct sol first[101];
struct sol second[101];

void reverse(char array[])
{
    int arrLen, i;
    char k;
    arrLen = strlen(array);

    for (i = 0; i < arrLen / 2; i++)
    {
        k = array[i];
        array[i] = array[arrLen - i - 1];
        array[arrLen - i - 1] = k;
    }
}

int bigIntAdd(char *a, char *b, char *sum)
{
    int s = 0, n, carry = 0;
    int lena, lenb;
    lena = strlen(a);
    lenb = strlen(b);

    while (s < lena && s < lenb)
    {
        n = (a[lena - s - 1] - '0') + (b[lenb - s - 1] - '0') + carry;
        if (n > 9)
        {
            carry = n / 10;
            n = n % 10;
        }
        else
            carry = 0;

        sum[s] = n + '0';
        s++;
    }

    if (s >= lena)
    {
        lena = lenb;
        a = b;
    }

    while (s < lena)
    {
        n = (a[lena - s - 1] - '0') + carry;

        if (n > 9)
        {
            carry = n / 10;
            n = n % 10;
        }
        else
            carry = 0;
        sum[s] = n + '0';
        s++;
    }

    if (carry)
        sum[s++] = carry + '0';
    sum[s] = 0;

    reverse(sum);
    return s;
}

int main()
{
    int i, j, x, z, k, kase = 0;
    struct sol *f, *s, *t;


    scanf("%d", &kase);
    while (kase--)
    {
        scanf("%s", X);
        x = strlen(X);
        scanf("%s", Z);
        z = strlen(Z);

        for (i = 0; i <= z; i++)
        {
            strcpy(first[i].n, "0");
            strcpy(second[i].n, "0");
        }

        f = first;
        s = second;

        for (j = 0; j < x; j++)
        {
            strcpy(f[0].n, "1");
            strcpy(s[0].n, "1");

            for (i = 0; i < z; i++)
            {
                if (Z[i] == X[j])
                {
                    bigIntAdd(f[i].n, f[i + 1].n, s[i + 1].n);
                }
                else
                {
                    strcpy(s[i + 1].n, f[i + 1].n);
                }
            }

            t = f;
            f = s;
            s = t;
        }

        printf("%s\n", f[z].n);
    }

    return 0;
}