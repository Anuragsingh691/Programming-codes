#include <bits/stdc++.h>
using namespace std;

// The below program stop working after 19th decimal point as int and long long cannot store above that value. the updated code is also availble .
int main()
{
    // your code goes here
    int n;
    cout << "Enter nth number to print pi to that decimal point.\n";
    cin >> n;
    int a = 22, b = 7;
    int dec = a / b;
    int ans = 0;
    cout << dec << ".";
    while (n--)
    {
        a = a - (b * dec);
        if (a == 0)
            break;
        a = a * 10;
        dec = a / b;
        ans = (ans * 10) + dec;
    }
    cout << ans;
    return 0;
}