#include <bits/stdc++.h>
using namespace std;
#include <boost/multiprecision/cpp_int.hpp>

// This is the same program to find the nth pi decimal point using boost library so that we can find pi value upto 100th or 200th digit

using uint512_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<512, 512, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
using uint1024_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<1024, 1024, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
using uint2048_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<2048, 2048, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
using uint4096_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<4096, 4096, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;
using uint8192_t = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<8192, 8192, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>, boost::multiprecision::et_off>;

int main()
{
    int n;
    cout << "Enter nth number to print pi to that decimal point.\n";
    cin >> n;
    int a = 22, b = 7;
    int dec = a / b;
    uint8192_t ans(0U);
    cout << dec << ".";
    for (int64_t i = 0; i < n; i++)
    {
        a = a - (b * dec);
        if (a == 0)
            break;
        a = a * 10;
        dec = a / b;
        ans = (ans * 10) + dec;
    }
    std::cout << ans << std::endl;
    return 0;
}