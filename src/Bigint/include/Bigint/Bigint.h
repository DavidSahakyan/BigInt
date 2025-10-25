#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class BigInt
{
public:

    BigInt();
    BigInt(const std::string& number); 
    BigInt(unsigned long long num);
    BigInt(const BigInt& other); 
    
    void print() const;

    BigInt operator+(const BigInt& other);
    BigInt operator=(const BigInt& other);
    BigInt operator*(const BigInt& other);
    bool operator>(const BigInt& other) const;
    bool operator>=(const BigInt& other) const;
    bool operator<(const BigInt& other) const;
    bool operator<=(const BigInt& other) const;
    bool operator==(const BigInt& other) const;
    bool operator!=(const BigInt& other) const;
    BigInt operator-(const BigInt& other);
    BigInt operator/(const BigInt& other);
    void operator+=(const BigInt& other);
    void operator-=(const BigInt& other);
    void operator*=(const BigInt& other);
    void operator/=(const BigInt& other);
    BigInt operator^(const BigInt& other);
    ~BigInt();
    

private:
    std::vector<short int> nums_vector;
};

#endif
