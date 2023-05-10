#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m = matrix.size() , n = matrix[0].size();
        int top , left , right , bottom;
        top = 0 , left =0 , right = n-1 , bottom = m-1;
        
        int direction = 0; // 0 - L-R , 1- T-B , 2-R-L , 3 - B-T
        
        while(top<=bottom and left<=right){
            if(direction ==0 ){
                for(int i = left ;i<=right;i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(direction == 1){
                for(int i= top;i<=bottom;i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(direction == 2){
                for(int i= right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            else{
                for(int i=bottom;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            
            direction = (direction+1)%4;
        }
        return ans;
    }
};