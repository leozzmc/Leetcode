#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Codec {
public:

    string message="";
    vector<pair<int,string>> repairList;
    vector<string> returnList;

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        for(string str: strs){
            message+= str;
            repairList.push_back({str.length(), str});
        }
        
        for(int i=0; i< message.length();i++){
            message[i] = message[i] - 13;
        }
        cout << "Encoded Message:" << message << endl;
        return message;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) { 
        
        returnList.clear();

        int pos=0;
        for(int i=0; i< s.length();i++){
            s[i] = s[i] + 13;
        }
 
        for(auto &repair: repairList){
            int length = repair.first;
            string decodeStr = s.substr(pos, length);
            returnList.push_back(decodeStr);
            pos+=length;
        }
        return returnList;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));