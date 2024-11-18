#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    // Place element of nums2 into nums1 array
    for(int i=n; i< nums1.size(); i++){
        nums1[m+i] = nums2[i];
    }
    
    //sort elements
    sort(nums1.begin(), nums1.begin() + m + n);
    
}

int main(){
    vector<int> nums1={1,2,3,0,0,0};
    vector<int> nums2={2,5,6};
    int m=3, n=3;
    merge(nums1, m, nums2, n);
    for(auto i=0; i<nums1.size();++i){
        cout << nums1[i] << " ";
    }

    return 0;
}