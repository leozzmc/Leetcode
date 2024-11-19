#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        if(nums2.size()==0) return;
        if(m==0){
            for(int i=0; i< nums2.size(); i++){
                num1[i] = nums2[i];
            }
            return;
        }
        
        int i=m;
        int j=0;
        int k=m;
        while(j<n){
            nums1[k]=nums2[j];
            j++;
            k++;
        }
        sort(nums1.begin(), nums1.begin() + m +n);
    }

int main(){
    vector<int> nums1={4,0,0,0,0,0};
    vector<int> nums2={1,2,3,5,6};
    int m=1, n=5;
    merge(nums1, m, nums2, n);
    for(auto i=0; i<nums1.size();++i){
        cout << nums1[i] << " ";
    }

    return 0;
}