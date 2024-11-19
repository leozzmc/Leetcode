#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool isValid(vector<int>nums, int start, bool direct){
    int n = nums.size();
    int curr = start;
    while(curr >=0 && curr < n) {
        if(nums[curr] ==0){
            if(direct) curr++;
            else curr--;
        }
        else{
            nums[curr]--;
            direct = !direct;
            if(direct) curr++;
            else curr--;
        }
    }
    for(auto it=nums.begin(); it!=nums.end(); ++it){
        if(*it !=0){
            return false;
        }
    }
    return true;
}

int countValidSelections(vector<int>& nums){

    //select starting position
    int n = nums.size();
    int found = 0;
    for(int i = 0; i< n;i++){
        if(nums[i]==0){
            if(isValid(nums,i,true)){
                found++;
            }
            if(isValid(nums,i,false)){
                found++;
            }
        }
    }
    return found;
}

int main(){
    vector<int> nums= {2,3,4,0,4,1,0};
    cout << countValidSelections(nums) << endl;


}