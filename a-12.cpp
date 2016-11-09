#include <iostream>
#include <vector>
#include <string>

using namespace std;



string intToRoman(int num) {
    string intRomanMap[4][10] =
    {
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"", "M", "MM", "MMM"}
    };
    string ret = "";
    for(int i = 0; i<4; i++){
        int index = num % 10;
        ret = intRomanMap[i][index] + ret;
        num /= 10;
    }
    return ret;
}


int main(){
    cout<<intToRoman(1234);
}
