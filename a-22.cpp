#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;


void paraGenRecur(int leftNum, int rightNum, string s, vector<string>& r);
vector<string> generateParenthesis(int n) {
    vector<string> ret;
    paraGenRecur(n, n, "", ret);
    return ret;
}

void paraGenRecur(int leftNum, int rightNum, string s, vector<string>& r){
    if(leftNum==0 && rightNum==0){
        r.push_back(s);
    }
    if(leftNum>0){
        paraGenRecur(leftNum-1, rightNum, s+'(', r);
    }
    if(leftNum<rightNum){
        paraGenRecur(leftNum, rightNum-1, s+')', r);
    }
}

int main(){
    auto paras = generateParenthesis(3);
    for(auto& s: paras){
        cout<<s<<endl;
    }
}
