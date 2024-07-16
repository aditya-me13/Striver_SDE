class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        // trivial case
        if(n < 4){
            return {};
        }
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n-3; i++){
            if(i && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n-2; j++){
                if(j != i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1;
                int l = n - 1;
                while(k < l){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[k++], nums[l--]});
                        while(k < l && nums[k] == nums[k-1]) k++;
                        while(k < l && nums[l] == nums[l+1]) l--; 
                    }

                    else if(sum > target){
                        l--;
                        while(k<l && nums[l] == nums[l+1]) l--;
                    }
                    else{
                        k++;
                        while(k<l && nums[k] == nums[k-1]) k++;
                    }
                }
            }
        }
        return ans;

    }
};