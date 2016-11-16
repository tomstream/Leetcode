#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct Sum{
    int sum;
    int a;
    int b;
};


vector<vector<int>> threeSum(vector<int>& nums) {

    vector<vector<int>> ret;
    if(nums.size()<3)return ret;
    vector<int> pos, neg;
    int zero=0;
    for(auto num: nums){
        if(num>0){
            pos.push_back(num);
        }else if(num==0){
            zero+=1;
        }else{
            neg.push_back(-num) ;
        }
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    vector<int> uniquePos(pos.size());
    vector<int> uniqueNeg(neg.size());
    auto it=std::unique_copy (pos.begin(),pos.end(),uniquePos.begin());
    uniquePos.resize( std::distance(uniquePos.begin(),it) );
    it=std::unique_copy (neg.begin(),neg.end(),uniqueNeg.begin());
    uniqueNeg.resize( std::distance(uniqueNeg.begin(),it) );


    vector<Sum> posSum;
    vector<Sum> negSum;
    set<pair<int,int>> posSumSet, negSumSet;
    for(int i=0;i<neg.size();i++){
        for(int j=0;j<i;j++){
            int neg1=neg[i]<neg[j]?neg[i]:neg[j],neg2=neg[i]<neg[j]?neg[j]:neg[i];
            if(negSumSet.find(pair<int,int>(neg1,neg2))==negSumSet.end()){
              negSumSet.insert(pair<int,int>(neg1,neg2));
              Sum s = {neg1+neg2,neg1,neg2};

              negSum.push_back(s);
          }
        }
    }

    for(int i=0;i<pos.size();i++){
        for(int j=0;j<i;j++){
            int pos1=pos[i]<pos[j]?pos[i]:pos[j],pos2=pos[i]<pos[j]?pos[j]:pos[i];
            if(posSumSet.find(pair<int,int>(pos1,pos2))==posSumSet.end()){
              posSumSet.insert(pair<int,int>(pos1,pos2));
              Sum s = {pos1+pos2,pos1,pos2};

              posSum.push_back(s);
          }
        }
    }

    sort(posSum.begin(),posSum.end(),[](const Sum& s1, const Sum& s2){return s1.sum<s2.sum;});
    sort(negSum.begin(),negSum.end(),[](const Sum& s1, const Sum& s2){return s1.sum<s2.sum;});


    for(int i=0,j=0;i<uniquePos.size();i++){
        while(j+1<negSum.size() && negSum[j].sum<uniquePos[i] ){
            j++;
        }

        if(j>=negSum.size())break;
        while(negSum[j].sum==uniquePos[i]){
            vector<int> in={uniquePos[i],-negSum[j].a, -negSum[j].b};
            ret.push_back(in);
            j++;
        }
    }
    for(int i=0,j=0;i<uniqueNeg.size();i++){
        while(j+1<posSum.size() && posSum[j].sum<uniqueNeg[i]){
            j++;
        }
        if(j>=posSum.size())break;
        while(posSum[j].sum==uniqueNeg[i]){
            vector<int> in={-uniqueNeg[i],posSum[j].a,posSum[j].b};
            ret.push_back(in);
            j++;
        }
    }

    if(zero){
        for(int i=0,j=0;i<uniqueNeg.size();i++){
            while(j+1<uniquePos.size() && uniquePos[j]<uniqueNeg[i] ){
                j++;
            }
            if(j>=uniquePos.size())break;
            if(uniquePos[j]==uniqueNeg[i]){
                vector<int> in={-uniqueNeg[i],uniquePos[j],0};
                ret.push_back(in);
                j++;
            }
        }
    }
    if(zero>=3){
      vector<int> in{0,0,0};
      ret.push_back(in);
    }
    return ret;
}

int main(){
    vector<int> a = {-3,-4,-2,0,2,2,-2,1,-1,2,3,-1,-5,-4,-5,1};
    auto ret=threeSum(a);
    for(auto& v:ret){
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
