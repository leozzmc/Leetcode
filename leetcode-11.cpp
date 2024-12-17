#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height){
    int maxArea = 0;
    int left = 0;
    int right = height.size()-1;
    while(left < right){
        if(height[right]>height[left]){
           maxArea = max(maxArea, height[left]*(right-left)); 
        } 
        else{
           maxArea = max(maxArea, height[right]*(right-left));
        }
        if(height[left] < height[right]) left++;
        else right--;
        
    }
    return maxArea;

}
int main(){
    // vector<int> height ={1,8,6,2,5,4,8,3,7};
    vector<int> height ={1,1};
    cout << maxArea(height) << endl;  // Output: 49
    return 0;
}