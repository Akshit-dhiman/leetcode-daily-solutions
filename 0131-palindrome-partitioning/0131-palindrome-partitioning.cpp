class Solution {
public:
    bool ispalindrome(int start,int end, string s){
        while(start<end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }

    void helper(int ind, string s, vector<string>&path, vector<vector<string>>&ans){
        int n= s.size();
        if(ind == n ){
            ans.push_back(path);
            return;
        }

        for(int end = ind; end<n; end++){
            if(ispalindrome(ind, end, s)){
                path.push_back(s.substr(ind, end-ind+1));
                helper(end+1, s, path, ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;

        helper(0, s, path, ans);

        return ans;
    }
};