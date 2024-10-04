class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        if(n % 2 != 0){
            return -1;
        }
        int group = n/2;
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += skill[i];
        }
        int targetSum = sum /group;
        sort(skill.begin(), skill.end());
        int left = 0;
        int right = n-1;
        long long chem = 0;
        while(left < right){
            if(skill[left] + skill[right] != targetSum){       //1 2 3 | 3 4 5
                return -1;
            }
            chem += skill[left] * skill[right];
            left++;
            right--;
        }

        return chem;
    }
};