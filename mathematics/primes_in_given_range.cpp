//Program to ilustrate to find the primes in given range of numbers using segmented sieve

#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<int> simple_sieve(int n)
{
    vector<int> primes;
    vector<bool> is_prime(n + 1, true);

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] == true)
        {
            primes.push_back(i);

            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    return primes;
}

void segmented_sieve(int low, int high)
{
    int sq = sqrt(high);
    vector<int> prime = simple_sieve(sq);

    int n = high - low + 1;
    vector<bool> mark(n + 1, false);

    for (int i = 0; i < prime.size(); i++)
    {
        int lowlim = floor(low / prime[i]) * prime[i];
        if (lowlim < low || lowlim == prime[i])
        {
            lowlim += prime[i];
        }
        // if ()
        // {
        //     lowlim += prime[i];
        // }

        for (int j = lowlim; j <= high; j += prime[i])
        {

            if (j != prime[i])
            {

                mark[j - low] = true;
            }
        }
    }

    for (int i = low; i <= high; i++)
    {
        if (!mark[i - low])
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int choice, low, high;

    cout << "Enter the two numbers between which you want prime numbers.\nEnter the lower limit: \n";
    cin >> low;
    cout << "Enter the upper limit \n";
    cin >> high;
    if (high < low)
    {
        cout << "Second number should ne greater than first \n";
    }
    else
    {
        segmented_sieve(low, high);
    }

    return 0;
}
