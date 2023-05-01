#include <iostream>
#include <cstdlib>

#include "rsa.h"
#include "common.h"

int getRamdomPrimeNumber()
{
    int prime[46] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
    int RandIndex = rand() % 46;
    return prime[RandIndex];
}

long long unsigned encription(int d, int n)
{
    return power(31, d) % n;
}

long long unsigned dencription(int c, int e, int n)
{
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

    p = 7;
    q = 3;

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