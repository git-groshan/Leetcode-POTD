#include<bits/stdc++.h>
using namespace std;

//problem link
//https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/

#define ll long long int
class Solution {
public:
int maxValue(int n, int index, int maxSum) {
int emptyR = n - index - 1;
int emptyL = index;
int h = maxSum, l = 1;
ll res = 0;
while(l <= h){
int mid = (h-l)/2 + l;
ll leftSum = 0, rightSum=0, el=mid-1;
if(emptyR <= el)

rightSum = (el*(el+1))/2 - ((el-emptyR)*(el-emptyR+1))/2;
else
rightSum = (el*(el+1))/2 + (emptyR - el);
if(emptyL <= el)
leftSum = (el*(el+1))/2 - ((el-emptyL)*(el-emptyL+1))/2;
else
leftSum = (el*(el+1))/2 + (emptyL - el);
ll sum = leftSum + mid + rightSum;
if(sum <= maxSum){
l = mid+1;
res = mid;
}else{
h = mid-1;
}
}
return res;
}
};

/*
    Constraints:

1 <= n <= maxSum <= 109
0 <= index < n
*/

//Problem statement

/*
    1802. Maximum Value at a Given Index in a Bounded Array
Medium

2206

350

Add to List

Share
You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:

nums.length == n
nums[i] is a positive integer where 0 <= i < n.
abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
The sum of all the elements of nums does not exceed maxSum.
nums[index] is maximized.
Return nums[index] of the constructed array.

Note that abs(x) equals x if x >= 0, and -x otherwise.

 

Example 1:

Input: n = 4, index = 2,  maxSum = 6
Output: 2
Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].
Example 2:

Input: n = 6, index = 1,  maxSum = 10
Output: 3
 

Constraints:

1 <= n <= maxSum <= 109
0 <= index < n
*/