#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cout<<"Enter nth number to print pi to that decimal point.\n";
	cin>>n;
	int a = 22,b = 7;
	int dec = a / b;
	int ans = 0;
	cout<<dec<<".";
    while(n--) {
        a = a - (b * dec);
        if (a == 0)
            break;
        a = a * 10;
        dec = a / b;
        ans = (ans*10) + dec;
    }
    cout<<ans;
	return 0;
}