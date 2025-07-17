class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int cnt=0, ls=INT_MIN, largest=1;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size() ; i++){
            if(nums[i]-1==ls){
                cnt++;
                ls=nums[i];
            }
            else if(ls != nums[i]){
                cnt=1;
                ls=nums[i];
            }
            largest=max(cnt, largest);
        }
        return largest;
    }
};