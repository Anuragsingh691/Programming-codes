/* 
QS:- Given two version numbers, version1 and version2, compare them.

Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and may contain leading zeros. Every revision contains at least one character. Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid version numbers.

To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer value ignoring any leading zeros. This means that revisions 1 and 001 are considered equal. If a version number does not specify a revision at an index, then treat the revision as 0. For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.

Example 1:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both "01" and "001" represent the same integer "1".

Leetcode Link:- https://leetcode.com/problems/compare-version-numbers/description/

 previous approach for without entailing 0's
    class Solution {
public:
string removespace(string s)
{
    //traversing the string
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            s.erase(s.begin() + i);
            i--;
        }
    }
    return s;
}
    int compareVersion(string version1, string version2) {
        string v1 = removespace(version1);
        string v2 = removespace(version2);
    int n1 = v1.size();
	int n2 = v2.size();
	int subs = abs(n1-n2);
	int iv1 = stoi(v1);
	int iv2 = stoi(v2);
	int p = pow(10,subs);
	if(n1>n2){
		iv2 = iv2 * p;
	}else if(n2>n1){
		iv1 = iv1 * p;
	}
	if(iv1>iv2){
		return 1;
	}else if(iv1<iv2){
		return -1;
	}else{
		return 0;
	} // 1010 , 1001
    }
};
*/

// optimal approach:- 
#include<iostream>
#include <vector>
#include<unordered_set>
using namespace std;

    int compareVersion(string version1, string version2) {
   vector<int> v1, v2;
        long long ans = 0;
        for(int i=0;i<version1.size();i++){
            if(version1[i]=='.'){
                v1.push_back(ans);
                ans = 0;
            }
            else{
                ans = ans*10 + (version1[i]-'0');
            }
        }
        v1.push_back(ans);
        ans = 0;
        for(int i=0;i<version2.size();i++){
            if(version2[i]=='.'){
                v2.push_back(ans);
                ans = 0;
            }
            else{
                ans = ans*10 + (version2[i]-'0');
            }
        }
        v2.push_back(ans);
        
        if(v1.size()<v2.size()){
            while(v1.size()!=v2.size()) v1.push_back(0);
        }
        else{
            while(v1.size()!=v2.size()) v2.push_back(0);
        }
        
        for(int i=0;i<v1.size();i++){
            if(v1[i]<v2[i]) return -1;
            if(v1[i]>v2[i]) return 1;
        }
        return 0;
    }

    int main(){
        string version1 = "1.0.1";
	string version2 = "1";
    cout<<compareVersion(version1,version2);
    return 0;
    }