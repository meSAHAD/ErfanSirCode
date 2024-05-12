#include <stdio.h>
#include <string.h>

#define MX 1000

int main()
{
    char s[MX][MX];
    int cnt = 0;
    char c;
    int mp[256] = {0};

    while (scanf("%s", s[cnt]) != EOF)
    {
        if (strcmp(s[cnt], "#") == 0)
            break;
        cnt++;
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < cnt; j++)
        {
            if (i < strlen(s[j]))
            {
                c = s[j][i];
                if (mp[c] != 1)
                {
                    printf("%c", c);
                    mp[c] = 1;
                }
            }
        }
    }
    printf("\n");

    return 0;
}
