// Program to  illustrate Sieve of Eratosthenes
// it'a complexity is  O(nloglogn)

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<bool> ar(1000001, true);
vector<ll> primes(1000001);

void sieve()
{
    ll maxN = 1000000;

    ar[0] = ar[1] = false;

    for (ll i = 2; i <= maxN; i++)
    {
        if (ar[i] == true)
        {
            for (ll j = i * i; j <= maxN; j += i)
            {
                ar[j] = false;
            }
        }
    }

    for (int i = 0; i <= maxN; i++)
    {
        if (ar[i])
            cout << i << " ";
    }
}

int main()
{
    // sieve();
    int n;
    cout << "Enter the number less than which you want the prime numbers \n ";
    cin >> n;

    //Creating the bool array(sieve) of size n+1 and with default value as true
    vector<bool> is_Prime(n + 1, true);

    //Assigning value to 0,1 as false as they are not prime
    is_Prime[0] = is_Prime[1] = false;

    // Main algorithm of sieve for (int j = 2; j <= n; j++) {

    if (is_Prime[j] == true) { //If number is prime mark all multiples of
        thar number as false for (int i = j * j; i <= n; i += j) {
            is_Prime[i] =
                false;
        }
    }
}

// Printing all the prime numbers cout << "The prime numbers between " <<
n << " are " << "\n"; for (int j = 0; j < is_Prime.size(); j++) {
    if
    (is_Prime.at(j) == true) { cout << j << "\t"; }
}

return 0;
}
