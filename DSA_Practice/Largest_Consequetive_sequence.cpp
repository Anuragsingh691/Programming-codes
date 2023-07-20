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
// Better approach code:- visual all the sequences in the array 
// Best Approach:- create a set of all element and check if arr[i] is start of sequence if not find the right element to it and length of sequence
// Time Complexity:- O(n), Space Complexity:- O(1)

#include<iostream>
#include <vector>
#include<unordered_set>
using namespace std;

int betterApproachLongestConsecutive(vector<int>& nums) {
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

	int bestLongestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(), nums.end());
        int longest = 0;
        for(auto n: s){
            //if this is the start of the sequence
            if(!s.count(n - 1)){
                int length = 1; 
                while(s.count(n + length))
                    ++length;
                longest = max(longest, length);
            } 

        }
        return longest;
    }

int main(){
    std::vector<int> arr;
	arr.push_back(0);
	arr.push_back(3);
	arr.push_back(7);
	arr.push_back(2);
	arr.push_back(5);
	arr.push_back(8);
	arr.push_back(4);
	arr.push_back(6);
	arr.push_back(0);
	arr.push_back(1);
    std::cout<<bestLongestConsecutive(arr);
	cout<<endl;
	return 0;
}
