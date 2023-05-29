#include<bits/stdc++.h>
using namespace std;

//problem link

//https://leetcode.com/problems/design-parking-system/

class ParkingSystem {
public:
    
    int big = 0 , medium=0 , small=0;
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->small = small;
        this->medium = medium;
        
    }
    
    bool addCar(int carType) {
        if(carType == 1){
           if(big == 0) return false;
            big--;
            return true;
            
        }
        else if(carType == 2){
            if(medium==0) return false;
            medium--;
            
            return true;
        }
        else{
            if(small==0) return false;
            small--;
            return true;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */