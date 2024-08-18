# include <iostream>
# include <vector>
using namespace std;

vector<int> resultsArray(vector<int>& nums, int k) {
    vector<int> result;
    for(int i = 0; i <= nums.size() - k ; i++){
        bool isValid = true;
        for(int j=i+1; j< i+k; j++){
            
            if(nums[j] - nums[j-1] != 1){
                isValid = false;
                break;
            }
                // The last element in the subarray
            if(isValid){
                result.push_back(nums[i+k-1]);
            }
            else{
                result.push_back(-1);
            }
            }
            
        }
        int size = nums.size() - k +1;
        while(result.size() < size){
            result.push_back(-1);
        }
        
        return result;       
};

int main(){

    //vector<int> number = {3,2,3,2,3,2};
    //int  length = 2;
    vector<int> number = {1,2,3,4,3,2,5};
    int length = 3;
    vector<int> resultsList = resultsArray(number, length);
    for(int i=0; i< resultsList.size(); i++){
        cout << resultsList[i] << endl;
    }
    
    return 0;
}