#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
/*
//Vector
 -->erase() : creates the new vector of unique elements of given vector
 -->sort() :  to sort in accending order
 -->sort(v.begin(),v.end(), greater<>()) : to sort in decending order
 -->reverse() : to reverse a vector
 -->random_shuffle() : to randomly suffle elements of vector
 -->lower_bound() and upper_bound()
*/

/*
//Sets
-->s.insert(int a)
  #insert's element in an set
-->s.erase(int a)
   #delets element from an set
-->s.count(int a)
  #returns 1 if element is present in an set or else 0
-->s.find(int a)
   #if a is present in an set returns iterater to that element or else returns iterater to set.end()

*/

vector<int> gradingStudents(vector<int> grades)
{

    vector<int> ans;

    for (int i = 0; i < grades.size(); i++)
    {
        if (grades.at(i) < 38)
        {
            ans.push_back(grades.at(i));
        }

        else
        {
            int increased_grade = grades.at(i) + (5 - (grades.at(i) % 5));

            if (increased_grade - grades.at(i) < 3)
            {
                ans.push_back(increased_grade);
            }
            else
            {

                ans.push_back(grades.at(i));
            }
        }
    }

    return ans;
}

int main()
{

    int n;
    cin >> n;
    vector<int> grades;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        grades.push_back(x);
    }

    vector<int> ans = gradingStudents(grades);
    cout << "Answer is :\n";

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans.at(i) << " ";
    }

    return 0;
}