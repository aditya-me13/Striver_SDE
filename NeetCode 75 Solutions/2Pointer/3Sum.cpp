// Problem Link: https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        if(n < 3){
            return {};
        }

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int i = 0; i<n; i++){
            if(i != 0 && nums[i]==nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j < k){
                long long sum;
                sum = nums[i];
                sum += nums[j];
                sum += nums[k];

                if(sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                    
                }
                else if(sum > 0){
                    k--;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
                else{
                    j++;
                    while(j<k && nums[j] == nums[j-1]) j++;
                }
            }
        }
        return ans;
    }
};