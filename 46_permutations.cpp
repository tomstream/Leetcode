class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<bool> valid(nums.size(),true);
        vector<int> current;
        
        helper(ret, nums, valid, current);
        return ret;
    }
    void helper(vector<vector<int>>& ret, vector<int>& nums, vector<bool>& valid, vector<int>& current){
        if(nums.size()==current.size()){
            ret.push_back(current);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(valid[i]==false)continue;
            valid[i] = false;
            current.push_back(nums[i]);
            helper(ret, nums, valid, current);
            current.pop_back();
            valid[i] = true;
        }
    }
};
