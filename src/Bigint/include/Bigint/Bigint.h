#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class BigInt
{
public:

    BigInt()
    {
        this->nums_vector = {};
    }

    BigInt(const std::string& number) 
    {
            std::for_each(number.rbegin(), number.rend(), [this](char e)
            {
                this->nums_vector.push_back(int(e) - 48);
            });
    }

    BigInt(unsigned long long num)
    {
        if(!num)
        {
            nums_vector.push_back(num%10);
        }
        while(num)
        {
            nums_vector.push_back(num%10);
            num = num/10;
        }
    }

    BigInt(const BigInt& other) 
    {
        for(int i = 0; i < other.nums_vector.size(); i++)
        {
            this->nums_vector.push_back(other.nums_vector[i]);
        }
    }

    void print() const
    {
        bool is_zero = true;
        for(int i = this->nums_vector.size() - 1; i >= 0; i-- )
        {
            if(this->nums_vector[i] != 0)
            {
                bool starts_with_zero = true;
                if(this->nums_vector.size() == 1)
                {
                    std::cout<<nums_vector[0];
                }
                else
                {
                    std::for_each(this->nums_vector.rbegin(), this->nums_vector.rend(), [&starts_with_zero](int i)
                    {
                        if(i != 0)
                        {
                            starts_with_zero = false;
                            std::cout<<i;
                        }
                        else if(i == 0 && starts_with_zero == false)
                        {
                            std::cout<<i;
                        }
                    });
                }
                is_zero = false;
                std::cout<<std::endl;
                break;
            }
        }
        if(is_zero)
        {
            std::cout<<0<<std::endl;
        }
    }

    BigInt operator+(const BigInt& other)
    {
        BigInt res;
        bool plus_one_statement = false;
        int short_size = std::min(other.nums_vector.size(), this->nums_vector.size());
        int long_size = std::max(other.nums_vector.size(), this->nums_vector.size());
        for(int i = 0; i < short_size; i++)
        {
            if(this->nums_vector[i] + other.nums_vector[i] + plus_one_statement >= 10)
            {
                res.nums_vector.push_back((this->nums_vector[i] + other.nums_vector[i] + plus_one_statement) % 10);
                plus_one_statement = true;
            }
            else if(this->nums_vector[i] + other.nums_vector[i] + plus_one_statement < 10)
            {
                res.nums_vector.push_back(this->nums_vector[i] + other.nums_vector[i] + plus_one_statement);
                plus_one_statement = false;
            }
        }
        if(short_size == long_size)
        {
            if(plus_one_statement == true)
            {
                res.nums_vector.push_back(1);
            }
        }
        else if(this->nums_vector.size() > other.nums_vector.size())
        {
            for(short_size; short_size < long_size; short_size++)
            {
                if(this->nums_vector[short_size] + plus_one_statement >= 10)
                {
                    res.nums_vector.push_back((this->nums_vector[short_size] + plus_one_statement) % 10);
                    plus_one_statement = true;
                }
                else if(this->nums_vector[short_size] + plus_one_statement < 10)
                {
                    res.nums_vector.push_back(this->nums_vector[short_size] + plus_one_statement);
                    plus_one_statement = false;
                }
            }
            if(plus_one_statement)
            {
                res.nums_vector.push_back(1);
                plus_one_statement = false;
            }
        }
        else if(this->nums_vector.size() < other.nums_vector.size())
        {
            for(short_size; short_size < long_size; short_size++)
            {
                if(other.nums_vector[short_size] + plus_one_statement >= 10)
                {
                    res.nums_vector.push_back((other.nums_vector[short_size] + plus_one_statement) % 10);
                    plus_one_statement = true;
                }
                else if(other.nums_vector[short_size] + plus_one_statement < 10)
                {
                    res.nums_vector.push_back(other.nums_vector[short_size] + plus_one_statement);
                    plus_one_statement = false;
                }
            }
            if(plus_one_statement)
            {
                res.nums_vector.push_back(1);
                plus_one_statement = false;
            }
        }
        return res;
    }
    
    BigInt operator=(const BigInt& other)
     {
        this->nums_vector.clear();
        for(int i = 0; i < other.nums_vector.size(); i++)
        {
            this->nums_vector.push_back(other.nums_vector[i]);  
        }
        return *this;
    }

    BigInt operator*(const BigInt& other)
    {
        BigInt result;
        int coefficient = 0;
        int adder = 0;
        int short_size = std::min(this->nums_vector.size(), other.nums_vector.size());
        int long_size = std::max(this->nums_vector.size(), other.nums_vector.size());
        if(this->nums_vector.size() >= other.nums_vector.size())
        {
            for(int lower_i = 0; lower_i < short_size; lower_i++)
            {
                BigInt next;
                int coefficient = 0;
                while(coefficient != lower_i)
                {
                    next.nums_vector.push_back(0);
                    coefficient++;
                }
                for(int upper_i = 0; upper_i < long_size; upper_i++)
                {
                    next.nums_vector.push_back((other.nums_vector[lower_i] * this->nums_vector[upper_i] + adder) % 10);
                    adder = (other.nums_vector[lower_i] * this->nums_vector[upper_i] + adder) / 10;
                }
                if(adder != 0)
                {
                    next.nums_vector.push_back(adder);
                }
                result = result + next;
            }
        }
        else
        {
            for(int lower_i = 0; lower_i < short_size; lower_i++)
            {
                BigInt next;
                int coefficient = 0;
                while(coefficient != lower_i)
                {
                    next.nums_vector.push_back(0);
                    coefficient++;
                }
                for(int upper_i = 0; upper_i < long_size; upper_i++)
                {
                        next.nums_vector.push_back((this->nums_vector[lower_i] * other.nums_vector[upper_i] + adder) % 10);
                        adder = (this->nums_vector[lower_i] * other.nums_vector[upper_i] + adder) / 10;
                }
                if(adder != 0)
                {
                    next.nums_vector.push_back(adder);
                }
                result = result + next;
            }
        }
        return result;
    }

    bool operator>(const BigInt& other) const
    {
        if(other.nums_vector.size() > this->nums_vector.size())
        {
            return false;
        }
        else if(other.nums_vector.size()  < this->nums_vector.size())
        {
            return true;
        }
        else if(other.nums_vector.size() == this->nums_vector.size())
        {
            for(int i = other.nums_vector.size() - 1; i >= 0; i--)
            {
                if(other.nums_vector[i] > this->nums_vector[i])
                {
                    return false;
                }
                else if(other.nums_vector[i] < this->nums_vector[i])
                {
                    return true;
                }
            }
            return false;
        }
    }

    bool operator>=(const BigInt& other) const
    {
        if(other.nums_vector.size() > this->nums_vector.size())
        {
            return false;
        }
        else if(other.nums_vector.size()  < this->nums_vector.size())
        {
            return true;
        }
        else if(other.nums_vector.size() == this->nums_vector.size())
        {
            for(int i = other.nums_vector.size() - 1; i >= 0; i--)
            {
                if(other.nums_vector[i] > this->nums_vector[i])
                {
                    return false;
                }
                else if(other.nums_vector[i] < this->nums_vector[i])
                {
                    return true;
                }
            }
            return true;
        }
    }

    bool operator<(const BigInt& other) const
    {
        if(other.nums_vector.size() > this->nums_vector.size())
        {
            return true;
        }
        else if(other.nums_vector.size()  < this->nums_vector.size())
        {
            return false;
        }
        else if(other.nums_vector.size() == this->nums_vector.size())
        {
            for(int i = other.nums_vector.size() - 1; i >= 0; i--)
            {
                if(other.nums_vector[i] > this->nums_vector[i])
                {
                    return true;
                }
                else if(other.nums_vector[i] < this->nums_vector[i])
                {
                    return false;
                }
            }
            return false;
        }
    }

    bool operator<=(const BigInt& other) const
    {
        if(other.nums_vector.size() > this->nums_vector.size())
        {
            return true;
        }
        else if(other.nums_vector.size()  < this->nums_vector.size())
        {
            return false;
        }
        else if(other.nums_vector.size() == this->nums_vector.size())
        {
            for(int i = other.nums_vector.size() - 1; i >= 0; i--)
            {
                if(other.nums_vector[i] > this->nums_vector[i])
                {
                    return true;
                }
                else if(other.nums_vector[i] < this->nums_vector[i])
                {
                    return false;
                }
            }
            return true;
        }
    }

    bool operator==(const BigInt& other) const
    {
        if(other.nums_vector.size() > this->nums_vector.size())
        {
            return false;
        }
        else if(other.nums_vector.size()  < this->nums_vector.size())
        {
            return false;
        }
        else if(other.nums_vector.size() == this->nums_vector.size())
        {
            for(int i = other.nums_vector.size() - 1; i >= 0; i--)
            {
                if(other.nums_vector[i] > this->nums_vector[i])
                {
                    return false;
                }
                else if(other.nums_vector[i] < this->nums_vector[i])
                {
                    return false;
                }
            }
            return true;
        }
    }

    bool operator!=(const BigInt& other) const
    {
        if(other.nums_vector.size() > this->nums_vector.size())
        {
            return true;
        }
        else if(other.nums_vector.size()  < this->nums_vector.size())
        {
            return true;
        }
        else if(other.nums_vector.size() == this->nums_vector.size())
        {
            for(int i = other.nums_vector.size() - 1; i >= 0; i--)
            {
                if(other.nums_vector[i] > this->nums_vector[i])
                {
                    return true;
                }
                else if(other.nums_vector[i] < this->nums_vector[i])
                {
                    return true;
                }
            }
            return false;
        }
    }

    BigInt operator-(const BigInt& other)
    {
        BigInt res;
        int short_size = std::min(this->nums_vector.size(), other.nums_vector.size());
        int long_size = std::max(this->nums_vector.size(), other.nums_vector.size());
        bool minus_one_statement = false;
        if(*this < other)
        {
            std::cout<<"out of range"<<std::endl<<"return code : ";
            return 1;
        }
        for(int i = 0; i < short_size; i++)
        {
            if(this->nums_vector[i] - minus_one_statement < other.nums_vector[i])
            {
                res.nums_vector.push_back(this->nums_vector[i] - other.nums_vector[i] + 10 - minus_one_statement);
                minus_one_statement = true;
            }
            else
            {
                res.nums_vector.push_back(this->nums_vector[i] - other.nums_vector[i] - minus_one_statement);
                minus_one_statement = false;
            }
        }
        for(short_size; short_size < long_size; short_size++)
        {
            if(minus_one_statement == false)
            {
                res.nums_vector.push_back(this->nums_vector[short_size]);
            }
            else if(minus_one_statement == true)
            {
                if(this->nums_vector[short_size] == 0)
                {
                    minus_one_statement = true;
                    res.nums_vector.push_back(9);
                }
                else
                {
                    minus_one_statement = false;
                    res.nums_vector.push_back(this->nums_vector[short_size] - 1);
                }
            }
        }
        int s = res.nums_vector.size() - 1;
        bool starts_with_zero = true;
        for(int i = s; i >= 1; i--)
        {
            if(res.nums_vector[i] == 0 && starts_with_zero == true)
            {
                res.nums_vector.erase(res.nums_vector.begin() + i);
            }
            else
            {
                starts_with_zero = false;
            }
        }
        return res;
    }

    BigInt operator/(const BigInt& other)
    {
       BigInt res = 0;
       BigInt current_res(*this);
       int power;

       while(other <= current_res)
       {
            int coefficient = 1;
            power = 0;
            BigInt other_copy = other;
            bool statement = false; 
            while(other_copy <= current_res) 
            {
                other_copy.nums_vector.insert(other_copy.nums_vector.begin(), 0);
                power++;
                statement = true;
            }
            if(statement)
            {
                other_copy.nums_vector.erase(other_copy.nums_vector.begin());
                power--;
                statement = false;
            } 

            BigInt base_value = other_copy;

            while(other_copy <= current_res)
            {
                coefficient++;
                other_copy = base_value * coefficient;
                statement = true;
            }
            if(statement)
            {
                coefficient--;
                other_copy = base_value * coefficient;
            }
            current_res = current_res - other_copy;
            BigInt helper(1);
            while(power--)
            {
                helper.nums_vector.insert(helper.nums_vector.begin(), 0);
            }
            helper = helper * coefficient;
            res = res + helper;
       }
       return res;
    }

    void operator+=(const BigInt& other)
    {
        *this = (*this + other);
    }

    void operator-=(const BigInt& other)
    {
        *this = (*this - other);
    }

    void operator*=(const BigInt& other)
    {
        *this = (*this * other);
    }

    void operator/=(const BigInt& other)
    {
        *this = (*this / other);
    }

    BigInt operator^(const BigInt& other)
    {
        if(other == 1)
        {
            return *this;
        }
        if(other == 0)
        {
            return 1;
        }

        BigInt res(0);
        BigInt other_copy = other;
        BigInt this_copy = *this;
        BigInt this_second_copy = *this;
        int coefficient = 0;
        int k = 1;
        while(other >= k)
        {
            coefficient++;
            k = pow(2, coefficient);
            this_second_copy = this_copy;
            this_copy = this_copy * this_copy;
        }
        coefficient--;
        k = pow(2, coefficient); 
        return this_second_copy * (*this^(other_copy - k));
    }

    ~BigInt()
    {
        this->nums_vector.clear();
        this->nums_vector.shrink_to_fit();
    }

private:
    std::vector<short int> nums_vector;
};

#endif