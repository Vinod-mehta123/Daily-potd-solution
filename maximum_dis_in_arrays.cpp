class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        if(arrays.size() < 2){
            return 0;
        }
        int global_min = arrays[0][0];
        int global_max = arrays[0].back();
        int result = 0;

        for(int i=1; i<arrays.size(); i++){

            int local_min = arrays[i][0];
            int local_max = arrays[i].back();

            result = max(result , max(global_max - local_min, local_max - global_min));

            global_min = min(local_min, global_min);
            global_max = max(local_max, global_max);
        }
        return result;
    }
};