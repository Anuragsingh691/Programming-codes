/*
Question:- Given a string, the task is to reverse the order of the words in the given string. 

Approach:

Run a for loop to traverse the string and create a temporary string to store the words
If the current character is a space then add the current string to the answer and empty the string
Else push the character into the string
Print the answer array in reverse order 

*/


#include <bits/stdc++.h>
using namespace std;

//Input 1 = “World Hello”
// Output1 = “Hello World”

string removeSpace(string s){
	s.erase(remove(s.begin(),s.end(),' '),s.end());
	return s;
}
void reverse(string s){
	vector<string> tmp;
	string str = "";
	for(int i=0;i<s.length();i++){
		if(s[i]==' '){
			if(!str.empty()){
				tmp.push_back(str);
			}
			str = "";
		}else{
			str= str+ s[i];
		}
	}
	tmp.push_back(str);
		int j;
		for(j = tmp.size()-1;j>0;j--){
			cout<<tmp[j]<<" ";
		}
		cout<<tmp[0]<<endl;
}
int main() {
	// your code goes here
	string s = "verse   the into      Spiderman";
	reverse(s);
	return 0;
}