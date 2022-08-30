#include <bits/stdc++.h>
using namespace std;

/* 
Refer:- https://www.youtube.com/watch?v=QDBrZFROuA0&list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs&index=12
 */

void towerOfHanoi(int n, char start, char dest, char helper)
{
    if (n == 0)
        return;

    towerOfHanoi(n - 1, start, helper, dest);
    cout << "Move from " << start << "-->" << dest << endl;
    towerOfHanoi(n - 1, helper, dest, start);
}

int main()
{
    towerOfHanoi(3, 'A', 'C', 'B');

    return 0;
}