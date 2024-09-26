#include <iostream>
#include <string>
using namespace std;

string simpleCipher(string en, int k) {
    string decrypt = ""; 
    k = k % 26;  
    

    for (char c : en) {
        if (c >= 'A' && c <= 'Z') { 
            char newChar = (c - 'A' - k + 26) % 26 + 'A'; 
            decrypt += newChar;
        } else if (c >= 'a' && c <= 'z') { 
            char newChar = (c - 'a' - k + 26) % 26 + 'a';
            decrypt += newChar;
        } else {
            decrypt += c; 
        }
    }
    return decrypt; 
}

int main() {
    string encrypted = "Ohqqllbh'ernoblZnxrnovtabvfrcynlva'vagurfgerrgTbaanornovtznafbzrqnlLbhtbgzhqbalbhesnpr,LbhovtqvftenprXvpxvatlbhepnanyybiregurcynprFvatvat!Jrjvyy,jrjvyyebpxlbhJrjvyy,jrjvyyebpxlbh!OhqqllbhnerlbhatznauneqznafubhgvatvagurfgerrgtbaangnxrbagurjbeyqfbzrqnlLbhtbgoybbqbalbhesnpr,LbhovtqvftenprJnivatlbhonaarenyybiregurcynprJrjvyy,jrjvyyebpxlbh!Fvatvat!Jrjvyy,jrjvyyebpxlbh!OhqqllbhnernabyqznacbbeznaCyrnqvatjvgulbherlrftbaanznxrlbhfbzrcrnprfbzrqnlLbhtbgzhqbalbhsnpr,Lbhovtqvftenpr!Fbzrobqlorggrechglbhonpxvagblbhcynpr!Jrjvyy,jrjvyyebpxlbh!Fvatvat!Jrjvyy,jrjvyyebpxlbh!Pbzrba!Jrjvyy,jrjvyyebpxlbhRirelobqlJrjvyy,jrjvyyebpxlbh";
    int k = 13; 
    
    cout << simpleCipher(encrypted, k) << endl;

    return 0;
}

