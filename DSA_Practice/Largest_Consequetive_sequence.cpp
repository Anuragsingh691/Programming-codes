/*
Question:-
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.



Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Approach:-
1. Brute Force
2. Better
3. Optimal
*/

// Better Approach:- Sort and compare elements 
    // Time Complexity:- O(nlogn), Space Complexity:- O(1)

#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
	sort(nums.begin(),nums.end());
	int curr_max = 0,longest = 1, mn = INT_MIN;
	if(n==0){
		return 0;
	}
	for(int i=0;i<n;i++){
		if(mn==(nums[i]-1)){
			mn = nums[i];
			curr_max++;
		}else if(nums[i]!=mn){
			curr_max=1;
			mn = nums[i];
		}
		longest = max(curr_max,longest);
	}
	return longest;
    }

int main(){
    vector<int> arr{0,3,7,2,5,8,4,6,0,1};
    cout<<longestConsecutive(arr);
}
