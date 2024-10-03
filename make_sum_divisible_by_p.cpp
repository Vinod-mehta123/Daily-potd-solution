class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long total_sum = 0;
        for(int num: nums){
            total_sum += num;
        }
        int rem = total_sum % p;
        if(rem == 0){
            return 0;
        }

        unordered_map<int, int>prefixMod;
        prefixMod[0] = -1;

        long prefixSum =0;
        int minLength = nums.size();
        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];
            int currMod = prefixSum % p;
            int targetMod = (currMod - rem + p) % p;

            if(prefixMod.find(targetMod) != prefixMod.end()){
                minLength = min(minLength, i-prefixMod[targetMod]);
            }
            prefixMod[currMod] = i;
        }
        return minLength == nums.size() ? -1 : minLength;

    }
};