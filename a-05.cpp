/* Longest Palindromic Substring
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000,
 * and there exists one unique longest palindromic substring.
 * */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string longestPalindrome(string s){
    string new_s="#";
    for(auto c:s){
        new_s = new_s + c + '#';
    }
    vector<int> counts(new_s.size());
    for(int i=0; i<new_s.size(); i++){
        int j=1;
        while(true){
            if(i-j<0 || i+j>new_s.size()-1)
                break;
            if(new_s[i-j]==new_s[i+j])
                j+=1;
            else
                break;
        }
        counts[i]=j-1;
    }
    vector<int> realcounts(counts.size());
    int k=0;
    transform(counts.begin(), counts.end(), realcounts.begin(),[&](int i){
               // cout << k;
                if(k++&1)return (i&1)?i:i+1;
                else return i;
            });

    int max_pivot = max_element(realcounts.begin(), realcounts.end()) - realcounts.begin();
// if(realcounts[max_pivot]==1)
    string ret = string(new_s.begin()+max_pivot-counts[max_pivot], new_s.begin()+max_pivot+counts[max_pivot]+1);
    auto end = copy_if(ret.begin(), ret.end(), ret.begin(), [](const char c){
            return c!='#';
            });
    ret = string(ret.begin(), end);
    return ret;
}


int main(int argc, char** argv){
    string s = argv[1];
    cout << longestPalindrome(s);
    return 0;
}
