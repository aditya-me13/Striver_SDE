class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for(int i=0 ; i<nums.size() ; i++){
            // remove from front if out of window size
            if(!dq.empty() && dq.front()==i-k) dq.pop_front();

            // remove from back if non decreasing order is broken
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};