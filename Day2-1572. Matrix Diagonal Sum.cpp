#include<bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int n = mat.size();
        if(n&1) sum-= mat[n/2][n/2];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) sum+=mat[i][j];
                if(i+j == n-1) sum+=mat[i][j];
            }
        }
        
        return sum ;
    }
};
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum =0;
        int mid = mat[n/2][n/2];
        if(n&1) sum -= mid;
        for(int i=0;i<n;i++){
            sum += mat[i][i];//principal Diagonal i = j
            sum += mat[i][n-i-1];//secondry diag i= n - j -1 or j = n-i-1;
        }
        return sum;
    }
};