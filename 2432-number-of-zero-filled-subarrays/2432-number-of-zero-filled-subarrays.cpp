class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long total = 0, consecutive = 0;

        for(auto n: nums){
            if(n==0){
                consecutive++;
            }else{
                total+= consecutive*(consecutive+1)/2;
                consecutive = 0;
            }
        }
        if(consecutive > 0){
            total+= consecutive*(consecutive+1)/2;
        }
        return total;
    }
};