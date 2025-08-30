#include <iostream>
#include <climits>
#include <vector>
using namespace std;



void rotate(vector<int>& nums, int k) {
    int n=nums.size();
    k = k % n;
    if(k==0) return;
    vector<int> temp(k);
    for(int i=0; i<k; i++){
        temp[i] = nums[n-k+i];
    }
    for(int i=n-1; i>=k; i--){
        nums[i] = nums[i-k];
    }
    for(int i=0; i<k; i++){
        nums[i] = temp[i];
    }

}

int main (){
    return 0;
}