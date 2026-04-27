class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mpp;
        for(int i : nums){
            mpp[i]++;
        }

        vector<pair<int, int>> freq(mpp.begin(), mpp.end());

        sort(freq.begin(), freq.end(), [](const auto& a, const auto& b){
            return a.second>b.second;
        });

        vector<int> result;
        for(int i=0; i<k; i++){
            result.push_back(freq[i].first);
        }
        return result;
    }
};
