class Solution {
public:

    void helper(int ind, vector<int>& nums,vector<int>&vct, vector<vector<int>>& ans){
        int n = nums.size();
        ans.push_back(vct);

        for(int i=ind; i<n; i++){
            if(i>ind && nums[i] == nums[i-1]) continue;
                vct.push_back(nums[i]);
                helper(i+1, nums, vct, ans);
                vct.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> vct;
        helper(0,nums,vct, ans);

        return ans;
    }
};