class Solution {
public:
    void solver(int ind, int target, vector<int>&candidates, vector<int>& path,  vector<vector<int>>&ans){
        int n = candidates.size();
            if(target == 0){
                ans.push_back(path);
                return;
            }
            
        for(int i=ind; i<n; i++){
            if(i>ind && candidates[i] == candidates[i-1]) continue;

            if(candidates[i]>target) break;

            path.push_back(candidates[i]);
            solver(i+1, target-candidates[i],candidates , path, ans);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(candidates.begin(), candidates.end());

        solver(0, target, candidates, path, ans);
        return ans;
    }
};
