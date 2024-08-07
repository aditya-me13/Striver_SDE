// Problem Link : https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        
        while(low <= high){
            mid = (low+high)>>1;
            
            // found the element
            if(nums[mid]==target) return mid;
            
            // left part is sorted
            if(nums[low]<=nums[mid]){
                if(nums[low] <= target && nums[mid] >= target){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            
            // else right will be sorted
            else{
                if(nums[mid] <= target && nums[high] >= target){
                    low = mid +1;
                }
                else{
                    high = mid -1;
                }
            }
        }
        return -1;
    }
};