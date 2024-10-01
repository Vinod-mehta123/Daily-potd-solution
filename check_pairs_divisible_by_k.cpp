class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>map(k, 0);
        for(int i=0; i<n; i++){
            int rem = (arr[i] % k + k) % k;
            map[rem]++;
        }

        if(map[0] % 2 != 0){
            return false;
        }

        for(int i=1; i<= k/2; i++){
            int counterhalf = k - i;
            if(map[counterhalf]  != map[i]){
                return false;
            }
        }
        return true;
    }
};