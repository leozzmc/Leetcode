class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
    
            int left = 0;
            int right = s1.length()-1;
            string tempStr = s2;
    
            //build table
            unordered_map<char, int> umap1;
            for(char c: s1){
                umap1[c]++;
            }
           
    
            // using sliding window to check permutation in substring
            for(int left = 0; left + s1.length() <= s2.length(); left++){
                string subString = tempStr.substr(left, s1.length());
                unordered_map<char, int> umap2 = umap1;
                for(char c: subString){
    
                    if(umap2.find(c)!=umap2.end()){
                        umap2[c]--;
                        if (umap2[c] == 0) {
                            umap2.erase(c);
                        }
                    }
                    else{
                       break;
                    }
                }
                if (umap2.empty()) return true;
            }
            return false;
        }
    };