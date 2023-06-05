#include<bits/stdc++.h>
using namespace std;

//Problem link 
//https://leetcode.com/problems/check-if-it-is-a-straight-line/

class Solution {
public:
    
    
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int n = coordinates.size();
        if(n==2) return true;
        int x = coordinates[0][0];
        int y = coordinates[0][1];
        int a = coordinates[1][0];
        int b = coordinates[1][1];
        double m = INT_MIN;
        if(b-y!=0)
        m = (a-x)/(double)(b-y);
        cout<<"M is "<<m<<endl;
        
        for(int i=2;i<n;i++){
            int a = coordinates[i][0];
            int b = coordinates[i][1];
            double m1 = INT_MIN;
            if(b-y!=0)
            m1 = (a-x)/(double)(b-y);
            cout<<"m1 is "<<m1<<endl;
            if(m1!=m) return false;
        }
        
        return true;
    }
};