#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

vector<vector<int>> dp;
bool checkPalindrome(const string &s, int left, int right){
    if(dp[left][right]!= -1) return dp[left][right]; 
    while(left < right){
        if(s[left] != s[right]){
            dp[left][right] = false;
            return dp[left][right];
        } 
        left++;
        right--;
    }
    dp[left][right] = true;
    return dp[left][right];
}


string longestPalindrome(string s){
    int n=s.length();
    if(n==0) return "";
    dp = vector<vector<int>>(n, vector<int>(n,-1));
    string maxStr="";
    for(int start=0; start< n; start++){
        for(int end= start; end < n; end++){
            if(checkPalindrome(s, start, end)){
                if(end-start+1 > maxStr.length()){
                    maxStr = s.substr(start, end-start+1);
                }
            }
        }
        
    }
    return maxStr;
}

int main(){
    string s = "kztakrekvefgchersuoiuatzlmwynzjhdqqftjcqmntoyckqfawikkdrnfgbwtdpbkymvwoumurjdzygyzsbmwzpcxcdmmpwzmeibligwiiqbecxwyxigikoewwrczkanwwqukszsbjukzumzladrvjefpegyicsgctdvldetuegxwihdtitqrdmygdrsweahfrepdcudvyvrggbkthztxwicyzazjyeztytwiyybqdsczozvtegodacdokczfmwqfmyuixbeeqluqcqwxpyrkpfcdosttzooykpvdykfxulttvvwnzftndvhsvpgrgdzsvfxdtzztdiswgwxzvbpsjlizlfrlgvlnwbjwbujafjaedivvgnbgwcdbzbdbprqrflfhahsvlcekeyqueyxjfetkxpapbeejoxwxlgepmxzowldsmqllpzeymakcshfzkvyykwljeltutdmrhxcbzizihzinywggzjctzasvefcxmhnusdvlderconvaisaetcdldeveeemhugipfzbhrwidcjpfrumshbdofchpgcsbkvaexfmenpsuodatxjavoszcitjewflejjmsuvyuyrkumednsfkbgvbqxfphfqeqozcnabmtedffvzwbgbzbfydiyaevoqtfmzxaujdydtjftapkpdhnbmrylcibzuqqynvnsihmyxdcrfftkuoymzoxpnashaderlosnkxbhamkkxfhwjsyehkmblhppbyspmcwuoguptliashefdklokjpggfiixozsrlwmeksmzdcvipgkwxwynzsvxnqtchgwwadqybkguscfyrbyxudzrxacoplmcqcsmkraimfwbauvytkxdnglwfuvehpxd";
    cout << longestPalindrome(s) << endl;
    return 0;
}