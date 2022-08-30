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

  Topic:- Matrix Exponention(V.V.V IMP)
  
  Time Complexity:- "O(log(n)*s^3)"  , where  n=power to which it is being calculated &  s=size of square matrix;

  Applications :- To find nth term of a linear recurence.

 */

//Function to multiply matrix
dvl multiplyMatrix(dvl A, dvl B, ll dim)
{
    dvl ans(dim, vl(dim));

    f(i, 0, dim)
    {
        f(j, 0, dim)
        {
            ans[i][j] = 0;
            f(k, 0, dim)
            {
                ans[i][j] = (ans[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return ans;
}

//Function to calculating power of a matrix
dvl Mpower(dvl ar, ll n, ll dim)
{
    dvl I(dim, vl(dim));

    f(i, 0, dim)
    {
        f(j, 0, dim)
        {
            I[i][j] = 0;
        }
        I[i][i] = 1;
    }

    //Use of binary exponentiation
    while (n)
    {
        if (n & 1)
        {
            I = multiplyMatrix(I, ar, dim);
            n--;
        }
        else
        {
            ar = multiplyMatrix(ar, ar, dim);
            n /= 2;
        }
    }

    return I;
}

/* 
Apllication of matirx exponention to find nth term of fibonacci series in log(n) time 

Below representation is only for fibonacci it may change acording to given question.

 _      _      _     _ (n-1)     _   _
|  f(n)  |    | 1   1 |         |  1  |
|        | =  |       |     *   |     |
|_f(n-1)_|    |_1   0_|         |_ 1 _|


Note :- if any recurence relation is not in a linear form then make it linear using some mathematics ans use matirx exponention to find nth term.
*/
ll nth_fibonacci()
{
    ll n;
    cin >> n;
    dvl matrix = {{1, 1}, {1, 0}};

    dvl ans = Mpower(matrix, n - 2, 2);

    return (ans[0][0] + ans[0][1]) % MOD;
}

int main()
{

    start;

    cout << nth_fibonacci();
    // ll t, dim, n;
    // cin >> t;
    // test(t)
    // // {
    //     cin >> dim >> n;

    //     dvl ar(dim, vl(dim)); //entered matrix

    //     dvl ans(dim, vl(dim)); //mateix to save answer

    //     f(i, 0, dim)
    //     {
    //         f(j, 0, dim)
    //         {
    //             cin >> ar[i][j];
    //         }
    //     }

    //     ans = Mpower(ar, n, dim);

    //     f(i, 0, dim)
    //     {
    //         f(j, 0, dim)
    //         {
    //             cout << ans[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    return 0;
}