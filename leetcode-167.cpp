#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target){
    int left=0;
    int right = numbers.size()-1;
    while(left < right){
        if(numbers[left]+ numbers[right] == target){
            return {left+1, right+1};
        }
        else if(numbers[left] + numbers[right] < target){
            left++;
        }
        else{
            right--;
        }
    }
    return {};
}


int main(){
    vector<int> numbers = {-10,-8,-2,1,2,5,6};
    int target = 0;
    vector<int> result = twoSum(numbers, target);
    if (!result.empty()) {
        cout << "Index1: " << result[0] << ", Index2: " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }



    return 0;
}