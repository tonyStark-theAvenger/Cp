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
#define wn po pop

void print_ans(vector<vector<int>> &board)
{

    f(i, 0, board.size())
    {
        f(j, 0, board.size())
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool is_safe(vector<vector<int>> &board, int row, int col)
{
    for (int i = row, j = col; i >= 0; i--)
        if (board[i][j] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; j--, i--)
        if (board[i][j] == 1)
            return false;
    for (int i = row, j = col; i >= 0 && j < board.size(); j++, i--)
        if (board[i][j] == 1)
            return false;

    return true;
}
bool solve(vector<vector<int>> &board, int row)
{
    if (row >= board.size())
        return true;

    for (int i = 0; i < board.size(); i++)
    {
        if (is_safe(board, row, i))
        {
            board[row][i] = 1;

            if (solve(board, row + 1))
                return true;

            board[row][i] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solve(board, 0))
        print_ans(board);
    else
        cout << "NO Answer exist for this board" << endl;
}
