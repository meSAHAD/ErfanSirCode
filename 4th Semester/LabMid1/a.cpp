#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        char vowels[] = {'a', 'o', 'e', 'i', 'u'};
        int k = x / 5;
        for (int i = 1; i <= x % 5; i++)
        {
            for (int j = 1; j <= k + 1; j++)
            {
                cout << vowels[i];
            }
        }
        for (int i = x % 5 + 1; i <= 5; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                cout << vowels[i];
            }
        }
        cout << endl;
    }
    return 0;
}