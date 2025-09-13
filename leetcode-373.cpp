#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


class Solution {
    public:
        vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
            vector<vector<int>> resultPairs;
    
            //define heap
            auto comparator = [&](const pair<int, int> &leftPair, const pair<int, int> &rightPair){
                long long sumLeft = (long long)(nums1[leftPair.first] +  nums2[leftPair.second]);
                long long sumRight = (long long)(nums1[rightPair.first] + nums2[rightPair.second]);
                return sumLeft > sumRight;
            };
            priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comparator)> minHeap(comparator);
            
            // form the pairs
            int limit = min((int)nums1.size(), k);
            for(int i=0; i<limit; i++){
                minHeap.push({i,0});
            }
    
            while(!minHeap.empty() && k-->0){
                auto [i, j] = minHeap.top();
                minHeap.pop();
                resultPairs.push_back({nums1[i],nums2[j]});
                if (j + 1 < (int)nums2.size()) {
                    minHeap.push({i, j + 1});
                }
            }
    
            return resultPairs;
        }
    };
void main(){};