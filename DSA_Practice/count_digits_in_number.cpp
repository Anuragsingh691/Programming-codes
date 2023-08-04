
/*

Approach 1:-
create a count variable initialising it to 0 
Run a while loop until number is greater than 0 , and divide number with 0 and keep count ++ for every iteration.
return count;


Approach 2:-
Convert number to string and print size of string.

Approach 3:-
use log base 10
*/


#include <bits/stdc++.h>
using namespace std;

// Number = 1235656

void count(int n){
	string n1 = to_string(n);
	cout<<n1.size()<<endl;
}

void countLog( long long n){
	cout<< floor(log10(n) +1);
}

int main() {
	// your code goes here
	long long num = 1235656;
	countLog(num);
	return 0;
}
