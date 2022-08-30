
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<int> b(n);

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        sort(b.begin(), b.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (x >= b[i])
            {
                x -= b[i];
                ans++;
            }
        }

        cout << ans;
    }
}
