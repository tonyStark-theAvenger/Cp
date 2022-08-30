#include <bits/stdc++.h>

using namespace std;

/* 
Problem:- https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
 */

/* 
Refer:- https://www.youtube.com/watch?v=pGVguAcWX4g&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=38
 */

int solve_r(string s, int i, int j, bool flag)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (flag == true)
        {
            if (s[i] == 'T')
                return 1;
            else
                return 0;
        }
        else
        {
            if (s[i] == 'F')
                return 1;
            else
                return 0;
        }
    }

    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int l_t, l_f, r_t, r_f;

        l_t = solve_r(s, i, k - 1, true);
        l_f = solve_r(s, i, k - 1, false);
        r_t = solve_r(s, k + 1, j, true);
        r_f = solve_r(s, k + 1, j, false);

        if (s[k] == '&')
        {
            if (flag == true)
                ans = ans + l_t * r_t;
            else
                ans = ans + (l_f * r_t) + (l_t * r_f) + (l_f * r_f);
        }
        else if (s[k] == '|')
        {
            if (flag == true)
                ans = ans + (l_f * r_t) + (l_t * r_f) + (l_t * r_t);
            else
                ans = ans + l_f * r_f;
        }
        else if (s[k] == '^')
        {
            if (flag == true)
                ans = ans + (l_f * r_t) + (l_t * r_f);
            else
                ans = ans + (l_t * r_t) + (l_f * r_f);
        }
    }
    return ans;
}

/* 
memoized approach 
Refer:- https://www.youtube.com/watch?v=bzXM1Zond9U&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=40
 */

unordered_map<string, int> m;

int solve_m(string s, int i, int j, bool flag)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (flag == true)
        {
            if (s[i] == 'T')
                return 1;
            else
                return 0;
        }
        else
        {
            if (s[i] == 'F')
                return 1;
            else
                return 0;
        }
    }

    string st = to_string(i);
    st.push_back('-');
    st.append(to_string(j));
    st.push_back('-');
    st.append(to_string(flag));

    if (m.find(st) != m.end())
        return m[st];

    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int l_t, l_f, r_t, r_f;
        l_t = solve_m(s, i, k - 1, true);
        l_f = solve_m(s, i, k - 1, false);
        r_t = solve_m(s, k + 1, j, true);
        r_f = solve_m(s, k + 1, j, false);

        if (s[k] == '&')
        {
            if (flag == true)
                ans = ans + l_t * r_t;
            else
                ans = ans + (l_f * r_t) + (l_t * r_f) + (l_f * r_f);
        }
        else if (s[k] == '|')
        {
            if (flag == true)
                ans = ans + (l_f * r_t) + (l_t * r_f) + (l_t * r_t);
            else
                ans = ans + l_f * r_f;
        }
        else if (s[k] == '^')
        {
            if (flag == true)
                ans = ans + (l_f * r_t) + (l_t * r_f);
            else
                ans = ans + (l_t * r_t) + (l_f * r_f);
        }
    }
    m.insert({st, ans});
    return ans;
}

int main()
{
    string s;
    cin >> s;
    // cout << "using recursion :- " << solve_r(s, 0, s.length() - 1, true) << endl;
    cout << "using memoized dp :- " << solve_m(s, 0, s.length() - 1, true) << endl;
    // int i = 10, j = 59;
    // bool flag = true;
    // string st = to_string(i);
    // st.push_back('-');
    // st.append(to_string(j));
    // st.push_back('-');
    // st.append(to_string(flag));
    // cout << st << endl;
    return 0;
}
