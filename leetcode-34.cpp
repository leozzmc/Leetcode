class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
    
            int left = 0;
            int mid = 0;
            int right = nums.size()-1;
            vector<int> indexList;
            vector<int> returnVec;
            bool founded= false;
            
            while(left <= right){
                mid = left + (right  - left)/2;
                if(target > nums[mid]){
                    left = mid+1;
                }
                else if(target < nums[mid]){
                    right = mid-1;
                }
                else{ // target == mid
                    founded = true;
                    indexList.push_back(mid);
                    break;
                }
            }
            if(founded){
                int r = mid + 1;
                int r_right = nums.size() - 1;
                while(r <= r_right){
                    int right_mid = r + (r_right - r) / 2;
                    if(target > nums[right_mid]){
                        r = right_mid + 1;
                    }
                    else if(target < nums[right_mid]){
                        r_right = right_mid - 1;
                    }
                    else{
                        indexList.push_back(right_mid);
                        r = right_mid + 1;
                    }
                }
    
                int l_left = 0;
                int l = mid - 1;
                while(l_left <= l){
                    int left_mid = l_left + (l - l_left) / 2;
                    if(target > nums[left_mid]){
                        l_left = left_mid + 1;
                    }
                    else if(target < nums[left_mid]){
                        l = left_mid - 1;
                    }   
                    else{
                        indexList.push_back(left_mid);
                        l = left_mid - 1; 
                    }
                }
    
                sort(indexList.begin(), indexList.end());
                returnVec = {indexList[0], indexList[indexList.size()-1]};
            }
            else{
                returnVec = {-1,-1};
            }
            return returnVec;
        }
    };