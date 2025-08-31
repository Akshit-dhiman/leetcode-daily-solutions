class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int pos: nums){
            if(i==0 || i==1 || nums[i-2]!=pos){
                nums[i]=pos;
                i++;
            }
        }
        return i;
    }
};