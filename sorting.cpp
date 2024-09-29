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

// Bubble Sort - Push the largest element to the right most position by adjacent swapping
// Time Complexity -> Best case - O(n)
//                    Worst case - O(n^2)
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for (int i=n-1;i>=0;i--){
            bool flag=0;
            for (int j=0;j<i;j++){
                if (nums[j]>nums[j+1]){
                     swap(nums[j],nums[j+1]);
                     flag=1;
                }
            }
            if (flag==0) break;
        }
        return nums;
    }