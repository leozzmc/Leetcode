#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=0;
        int right = *max_element(piles.begin(), piles.end()); 
        int result = right;

        while(left <= right){
            int k = left + (right-left) /2;
            if(canFinish(piles, h, k)){
                    result = k;
                    right = k-1;
            }
            else{
                    left = k+1;
            }
        }
        return result;
    }
		
    bool canFinish(vector<int>&piles, int h, int k){
            long long hours = 0;
            for(int i=0; i< piles.size(); i++){
                        if(k>0) hours += (piles[i]  + k -1) / k;
                        else if(k<=0) return false;
                        if(hours > h) return false;
            }
            return true;
}
};