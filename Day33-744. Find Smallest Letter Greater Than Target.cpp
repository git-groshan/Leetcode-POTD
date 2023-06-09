#include<bits/stdc++.h>
using namespace std;

//Problem link

//https://leetcode.com/problems/find-smallest-letter-greater-than-target/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int idx = upper_bound(letters.begin() , letters.end() , target) - letters.begin();
        
        if(idx == letters.size()) return letters[0];
        
        return letters[idx];
        
    }
};