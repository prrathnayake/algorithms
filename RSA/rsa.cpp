#include <iostream>
#include <cstdlib>

#include "rsa.h"
#include "common.h"

int getRamdomPrimeNumber()
{
    int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int RandIndex = rand() % 10;
    return prime[RandIndex];
}

long long unsigned encription(int d, int n)
{
    std::cout << " power : " << power(11, d) << "\n";

    return power(11, d) % n;
}

long long unsigned dencription(int c, int e, int n)
{
    std::cout << " power : " << power(c, e) << "\n";

    return power(c, e) % n;
}

void generateKeys()
{
    int p, q, n, PHI, e, d;

    // p = getRamdomPrimeNumber();

    // while (true)
    // {
    //     q = getRamdomPrimeNumber();
    //     if (p != q)
    //     {
    //         break;
    //     }
    // }

    p = 3;
    q = 13;

    n = p * q;

    PHI = (p - 1) * (q - 1);

    while (true)
    {
        e = getRamdomPrimeNumber();

        if (PHI % e != 0 && e < PHI)
        {
            break;
        }
    }

    d = 1;

    while (true)
    {
        if ((d * e) % PHI == 1)
        {
            break;
        }
        d++;
    }

    int publicKey[2] = {e, n};
    int privateKey[2] = {d, n};

    int c = encription(d, n);

    std::cout << " p : " << p << "\n";
    std::cout << " q : " << q << "\n";
    std::cout << " n : " << n << "\n";
    std::cout << " PHI : " << PHI << "\n";
    std::cout << " e : " << e << "\n";
    std::cout << " d : " << d << "\n";
    std::cout << " c : " << c << "\n";
    std::cout << dencription(c, e, n) << "\n";
}