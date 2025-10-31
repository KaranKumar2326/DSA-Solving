class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>freq(n,0);
        for(auto i : nums){
            freq[i]++;
        }
        vector<int> ans;
        for(int i = 0; i<n;i++){
            if(freq[i]>1){
                ans.push_back(i);
            }
        }


        return ans;
    }
};