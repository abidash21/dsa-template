// Selection Sort - select the minimum element and swap with the left most element
// Time Complexity -> Best case - O(n^2)
//                    Worst case - O(n^2)
 vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for (int i=0;i<n-1;i++){
            int mini=i;
            for (int j=i;j<n;j++){
                if (nums[j]<nums[mini]) mini=j;
            }
            swap(nums[mini],nums[i]);
        }
        return nums;
    }