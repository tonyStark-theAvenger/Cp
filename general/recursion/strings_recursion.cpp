#include <bits/stdc++.h>

using namespace std;

//-->removeDuplicates
/* 
string removeDuplicates(string s)
{
    if (s.length() == 1)
        return s;

    if (s[0] == removeDuplicates(s.substr(1))[0])
        return removeDuplicates(s.substr(1));
    return s[0] + removeDuplicates(s.substr(1));
}
 */

//-->Puting specific charceter at last of string
/* 
string at_last(string s)
{
    if (s.length() == 0)
        return "";

    if (s[0] == 'x' || s[0] == 'X')
        return at_last(s.substr(1)) + s[0];
    return s[0] + at_last(s.substr(1));
}
 */

//--->generate_substrings
/* 
void generate_substrings(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char f = s[0];
    string ros = s.substr(1);
    generate_substrings(ros, ans);
    generate_substrings(ros, ans + f);
} */

//--->generate_substrings_with_ASCII
/* void generate_substrings_with_ASCII(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);

    generate_substrings_with_ASCII(ros, ans);
    generate_substrings_with_ASCII(ros, ans + ch);
    generate_substrings_with_ASCII(ros, ans + to_string(code));
} */

// -->Keypad problem
/*
string keypadArr[] = {"",
                      "./",
                      "abc",
                      "def",
                      "ghi",
                      "jkl",
                      "mno",
                      "pqr",
                      "stuv",
                      "wxyz"};

void keypad(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];

    string index = keypadArr[ch - '0'];
    string ros = s.substr(1);

    for (int i = 0; i < index.length(); i++)
    {
        // cout << index[i] << " "; 
        keypad(ros, ans + index[i]);
    }
} */

int main()
{
    start;
    string s;
    cin >> s;

    // cout << removeDuplicates(s);

    // cout << at_last(s);

    // generate_substrings(s, "");

    // generate_substrings_with_ASCII(s, "");

    // keypad(s, "");

    return 0;
}
//-->removeDuplicates
/* 
string removeDuplicates(string s)
{
    if (s.length() == 1)
        return s;

    if (s[0] == removeDuplicates(s.substr(1))[0])
        return removeDuplicates(s.substr(1));
    return s[0] + removeDuplicates(s.substr(1));
}
 */

//-->Puting specific charceter at last of string
/* 
string at_last(string s)
{
    if (s.length() == 0)
        return "";

    if (s[0] == 'x' || s[0] == 'X')
        return at_last(s.substr(1)) + s[0];
    return s[0] + at_last(s.substr(1));
}
 */

//--->generate_substrings
/* 
void generate_substrings(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char f = s[0];
    string ros = s.substr(1);
    generate_substrings(ros, ans);
    generate_substrings(ros, ans + f);
} */

//--->generate_substrings_with_ASCII
/* void generate_substrings_with_ASCII(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);

    generate_substrings_with_ASCII(ros, ans);
    generate_substrings_with_ASCII(ros, ans + ch);
    generate_substrings_with_ASCII(ros, ans + to_string(code));
} */

// -->Keypad problem
/*
string keypadArr[] = {"",
                      "./",
                      "abc",
                      "def",
                      "ghi",
                      "jkl",
                      "mno",
                      "pqr",
                      "stuv",
                      "wxyz"};

void keypad(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];

    string index = keypadArr[ch - '0'];
    string ros = s.substr(1);

    for (int i = 0; i < index.length(); i++)
    {
        // cout << index[i] << " "; 
        keypad(ros, ans + index[i]);
    }
} */

int main()
{
    start;
    string s;
    cin >> s;

    // cout << removeDuplicates(s);

    // cout << at_last(s);

    // generate_substrings(s, "");

    // generate_substrings_with_ASCII(s, "");

    // keypad(s, "");

    return 0;
}