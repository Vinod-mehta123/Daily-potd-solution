class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> set(arr.begin(), arr.end());

        unordered_map<int, int> map;
        int rank = 1;
        for (const int& num : set) {
            map[num] = rank++;
        }
        vector<int> ans;
        for (int num : arr) {
            ans.push_back(map[num]);
        }
        return ans;
    }
};