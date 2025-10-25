#include "Bigint.h"

int main()
{
    BigInt a(1990000000000);
    BigInt b(1990000000000);

    BigInt c = (a + b) * a;
    c.print();
}