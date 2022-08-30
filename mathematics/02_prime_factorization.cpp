#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef stack<ll> sl;
typedef vector<ll> vl;
typedef queue<ll> ql;
typedef set<ll> sel;
typedef vector<vl> dvl;
typedef pair<ll, ll> pll;

#define start                \
    ios::sync_with_stdio(0); \
    cin.tie(0);

#define file                                     \
    input_file = fopen("input.txt", "r", stdin); \
    output_file = fopen("output.txt", "w", stdout);

#define MOD 1000000007
#define f(i, a, b) for (ll i = a; i < b; i++)
#define test(t) while (t--)
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define pob pop_back
#define pu push
#define po pop

/*

  Question :- to find prime factors of a given number.

  Methods:-  1) in O(sqrt(n)) time
             2) using sieve in O(log(n)) time.

 */

//Method 1 in  in O(sqrt(n)) time
vl primeFactors_1(ll n)
{
    vl ans;

    while (n % 2 == 0)
    {
        ans.push_back(2);
        n /= 2;
    }

    for (ll i = 3; i * i <= n; i += 2)
    {

        while (n % i == 0)
        {
            ans.push_back(i);
            n /= i;
        }
    }
    if (n > 2)
    {
        ans.push_back(n);
    }
    return ans;
}

//Method 2 in O(log(n)) time
vl ar(1000001, -1);

//modification in general sieve inorder to calculate prime factors of a number
void sieve()
{

    ll maxN = 1000000;

    for (int i = 2; i <= maxN; i++)
    {
        if (ar[i] == -1)
        {
            for (int j = i; j <= maxN; j += i)
            {
                if (ar[j] == -1)
                    ar[j] = i;
            }
        }
    }

    return;
}
//Method 2 function
vl primeFactors_2(ll n)
{
    vl ans;

    while (ar[n] != -1)
    {
        ans.push_back(ar[n]);
        n /= ar[n];
    }
    return ans;
}
int main()
{
    start;
    sieve();
    ll n;
    cin >> n;
    vl ans1, ans2;
    cout << "Prime factors of " << n << " are : \n";
    cout << "using method 1 in O(sqrt(n)) time : ";
    ans1 = primeFactors_1(n);
    f(i, 0, ans1.size())
    {
        cout << ans1.at(i) << " ";
    }
    cout << "\nusing method 2 in O(log(n)) time : ";
    ans2 = primeFactors_2(n);
    f(i, 0, ans2.size())
    {
        cout << ans2.at(i) << " ";
    }

    return 0;
}