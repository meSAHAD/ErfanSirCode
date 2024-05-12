#include <stdio.h>

#define MAX_LENGTH 32 // Assuming max length of result is 32

char result[MAX_LENGTH]; // Global array to hold the result

char *negativetwobase(int n)
{
    int remainder;
    int index = 0;

    if (n == 0)
    {
        result[index++] = '0';
        result[index] = '\0';
        return result;
    }

    while (n != 0)
    {
        remainder = n % -2;
        n /= -2;
        if (remainder < 0)
        {
            n += 1;
            remainder += 2;
        }
        result[index++] = (char)('0' + remainder);
    }

    result[index] = '\0';

    // Reverse the string
    int i, j;
    char temp;
    for (i = 0, j = index - 1; i < j; i++, j--)
    {
        temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }

    return result;
}

int main()
{
    int cases;
    int num;

    scanf("%d", &cases);

    for (int i = 0; i < cases; i++)
    {
        printf("Case #%d: ", i + 1);

        scanf("%d", &num);

        printf("%s\n", negativetwobase(num));
    }

    return 0;
}
