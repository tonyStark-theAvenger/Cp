// Program to ilustrate segmented_sieve

#include <iostream>
#include <list>
#include <iterator>
#include <string.h>
#include <math.h>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

//simple sieve function to computee primes less tham sqrt of n
vector<int> simplesieve(int n)
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

//actuall segmented sieve function
void segmented_sieve(int n)
{
    int limit = sqrt(n) + 1;
    vector<int> prime = simplesieve(limit);

    int low = limit;
    int high = 2 * limit;

    for (int i = 0; i < prime.size(); i++)
    {
        cout << prime.at(i) << " ";
    }

    while (low < n)
    {
        if (high >= n)
            high = n;

        // To mark primes in current range. A value in mark[i]
        // will finally be false if 'i-low' is Not a prime,
        // else true.
        bool mark[limit + 1];
        memset(mark, true, sizeof(mark));

        // Use the found primes by simpleSieve() to find
        // primes in current range
        for (int i = 0; i < prime.size(); i++)
        {
            // Find the minimum number in [low..high] that is
            // a multiple of prime[i] (divisible by prime[i])
            // For example, if low is 31 and prime[i] is 3,
            // we start with 33.
            int loLim = floor(low / prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];

            /* Mark multiples of prime[i] in [low..high]:
                We are marking j - low for j, i.e. each number
                in range [low, high] is mapped to [0, high-low]
                so if range is [50, 100] marking 50 corresponds
                to marking 0, marking 51 corresponds to 1 and
                so on. In this way we need to allocate space only
                for range */
            for (int j = loLim; j < high; j += prime[i])
                mark[j - low] = false;
        }

        // Numbers which are not marked as false are prime
        for (int i = low; i < high; i++)
            if (mark[i - low] == true)
                cout << i << " ";

        // Update low and high for next segment
        low = low + limit;
        high = high + limit;
    }
}

int main()
{
    int n;
    cout << "Enter the number less than which you want the prime numbers \n ";
    cin >> n;

    cout << "Primes less than " << n << " are :"
         << "\n";

    segmented_sieve(n);
    return 0;
}
