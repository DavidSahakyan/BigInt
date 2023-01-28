find_package(GTest REQUIRED)

add_executable(Bigint_test Bigint_test.cpp)

target_link_libraries(Bigint_test
 PRIVATE
 GTest::GTest
 Bigint
)

add_test(Bigint_gtests Bigint_test)