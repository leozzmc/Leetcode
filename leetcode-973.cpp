

class Solution {
    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
            auto comparator = [](const vector<int>& leftVec, const vector<int>& rightVec) {
                long long d1 = 1LL * leftVec[0] * leftVec[0] + 1LL * leftVec[1] * leftVec[1];
                long long d2 = 1LL * rightVec[0] * rightVec[0] + 1LL * rightVec[1] * rightVec[1];
                return d1 > d2;
            };
            priority_queue<vector<int>,vector<vector<int>>, decltype(comparator)> distanceHeap(comparator);
    
            for(const auto&p: points){
                distanceHeap.push(p);
            }
    
            vector<vector<int>> result;
            result.reserve(k);
            for(int i=0; i<k; i++){
                if(!distanceHeap.empty()){
                    result.push_back(distanceHeap.top());
                    distanceHeap.pop();
                }
            }
            return result;
        }
    };