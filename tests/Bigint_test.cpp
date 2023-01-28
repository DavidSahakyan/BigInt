#include <Bigint/Bigint.h>
#include <gtest/gtest.h>

TEST(Bigint_test, oppluscheck)
{
    BigInt addative1("89999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999"); // [99]
                        
                        
    BigInt addative2("10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"); // [99]
    BigInt actual = addative1 + addative2;
    const BigInt expected("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000") ;// 100
    ASSERT_EQ(expected, actual);
}

TEST(Bigint_test, opminuscheck)
{
    BigInt minuend("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");//100
    
    BigInt subtahend("65555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555554");//99

    BigInt actual = minuend - subtahend;

    BigInt expected("34444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444446");//99

    ASSERT_EQ(expected, actual);
}

TEST(Bigint_test, opmultiplycheck)
{
    BigInt multiple1("500000000000000000000000000000000000000000000000000");// 52
    BigInt multiple2("4000000000000000000000000000000000000000000000000");// 50
    BigInt actual = multiple1 * multiple2;
    BigInt expected("2000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"); // 101
    ASSERT_EQ(expected, actual);
}

TEST(Bigint_test, opdividecheck)
{
    BigInt separatable("1000000000000000000000000000000000000000"); //40
    BigInt divider("50000000000000000000"); // 21
    BigInt expected("20000000000000000000"); //19
    BigInt actual = separatable/divider;
    ASSERT_EQ(actual, expected);
}

/*TEST(bigint_test, op^check)
{
    BigInt num1("10");
    BigInt num2("80");
    BigInt expected("100000000000000000000000000000000000000000000000000000000000000000000000000000000"); //81
    BigInt actual = num1^num2;
    ASSERT_EQ(expected, actual);
}*/

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
