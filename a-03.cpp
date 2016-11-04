#include <iostream>
#include <algorithm>
using namespace std;
int lengthOfLongestSubstring(string s){
    long maxlen = 0;
    auto subiter=s.begin();
    for(auto iter=s.begin(); iter!=s.end(); iter++){
        auto finditer = find_end(subiter, iter, iter, iter + 1);
        if(finditer != iter){
            subiter = finditer + 1;
        }
        maxlen = max(maxlen, iter - subiter + 1);
    }
    return maxlen;

}

int main(int argc, char** argv){
    if(argc < 2){
        return 0;
    }
    string s = argv[1];
    cout << lengthOfLongestSubstring(s);
    return 0;
}

