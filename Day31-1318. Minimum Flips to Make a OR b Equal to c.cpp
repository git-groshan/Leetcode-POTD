#include<bits/stdc++.h>
using namespace std;

//problem link
//https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

// class Solution {
// public:
//     int minFlips(int a, int b, int c) {
        
//         // return abs(a+b-c);
//         int ans =0;
//         for(int i=0;i<=31;i++){
//             int k = 1<<i;
//             int bitA = a&k;
//             int bitB = b&k;
//             int bitC = b&k;
            
//             if(bitA | bitB != bitC){
//                 if(bitC==1) ans++;
//                 else ans+=(bitA + bitB);
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while (a > 0 || b > 0 || c > 0) {
            int bitA = a & 1;
            int bitB = b & 1;
            int bitC = c & 1;
            if ((bitA | bitB) != bitC) {
                if (bitC == 1) {
                    flips++;
                } else {
                    flips += (bitA + bitB);
                }
            }   
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return flips;
    }
};