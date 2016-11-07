#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>
#include <cmath>
using namespace std;

int maxArea(vector<int>& height) {

    int areaMax = 0;
    if(height.size() < 2){
        return 0;
    }
    vector<pair<int, int>> sorted_list(height.size());
    for(int i = 0; i<sorted_list.size(); i++){
        sorted_list[i] = pair<int, int>(i, height[i]);
    }
    sort(sorted_list.begin(), sorted_list.end(),[](const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.second > p2.second;
            });
    int maxInterval = 0;
    int minIndex = height.size();
    int maxIndex =  0;
    for(int i=0; i<sorted_list.size(); i++){
        int index = sorted_list[i].first;
        int height = sorted_list[i].second;
        minIndex = min(minIndex, index);
        maxIndex = max(maxIndex, index);
        maxInterval = max(maxInterval, abs(index - minIndex));
        maxInterval = max(maxInterval, abs(index - maxIndex));
        areaMax = max(maxInterval * height, areaMax);
    }
    return areaMax;
}


int main(){
    vector<int> paras = {1,2,3,4,5};
    cout << maxArea(paras);
}
