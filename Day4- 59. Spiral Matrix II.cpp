#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        int top = 0 , left = 0 , bottom = n-1 , right = n-1;
        
        int dir = 0 ; // 0 - L-R , 1 - T-B , 2 - R-L , 3 - B-T
        
        vector<vector<int>>ans(n , vector<int>(n , 0));
        int num = 1;
        
        while(top<=bottom and left<=right){
            
            if(dir == 0){ // L-R   top -> constatnt
                for(int i=left ;i<=right;i++){
                    ans[top][i] = num;
                    num++;
                }
                top++;
                    
            }
            
            else if(dir == 1){ // T-B   right -> const
                for(int i=top;i<=bottom;i++){
                    ans[i][right] = num;
                    num++;
                }
                right--;
            }
            
            else if(dir == 2){ //R-L , bottom ->const
                for(int i= right ; i>=left;i--){
                    ans[bottom][i] = num;
                    num++;
                }
                bottom--;
            }
            
            else{ // dir = 3 B-T , left ->constant
                for(int i=bottom;i>=top;i--){
                    ans[i][left] = num;
                    num++;
                }
                left++;
            }
            
            dir = (dir+1)%4;
        }
        
        return ans;
        
    }
};