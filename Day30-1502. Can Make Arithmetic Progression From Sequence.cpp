#include<bits/stdc++.h>
using namespace  std;

//Problem link 
//https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int diff = arr[1] - arr[0];
        for(int i=2;i<arr.size();i++){
            int cur_diff = arr[i] - arr[i-1];
            if(cur_diff != diff) return false;
        }
        return true;
        
    }
};