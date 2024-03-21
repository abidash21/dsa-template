// Leetcode 347 - Top K frequent Elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for (int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<vector<int>>bucket(n+1);
        for (auto it:mp){
            int ele=it.first;
            int freq=it.second;
            bucket[freq].push_back(ele);
        }
        vector<int>res;
        for (int i=n;i>=0;i--){
            if (bucket[i].size()==0) continue;
            while(k && bucket[i].size()){
                res.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return res;
    }
};
