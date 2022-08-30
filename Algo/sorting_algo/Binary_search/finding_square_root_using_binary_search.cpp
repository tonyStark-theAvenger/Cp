#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve(int n)
{
    if (n == 0 || n == 1)
        return n;

    int ans, mid, lower = 0, higher = n;

    while (lower <= higher)
    {
        mid = lower + (higher - lower) / 2;
        if ((mid * mid) == n)
            return mid;
        else if ((mid * mid) < n)
        {
            lower = mid + 1;
            ans = mid;
        }
        else
            higher = mid - 1;
    }

    return ans;
}

int main()
{
    int n;
    cout << "ENTER THE NUMBER: ";
    cin >> n;
    cout << solve(n) << " " << floor(sqrt(n)) << " " << ceil(sqrt(n));
    return 0;
}
