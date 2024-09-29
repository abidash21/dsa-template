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

// Insertion Sort - Take and element and place it in correct position by swapping adjacent elements in backward direction 
// within the subarray(from starting postion till the element position)
// Time Complexity -> Best case - O(n)
//                    Worst case - O(n^2)
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for (int i=1;i<n;i++){
            int j=i;
            while(j>=1 && nums[j]<nums[j-1]){
                swap(nums[j],nums[j-1]);
                j--;
            }
        }
        return nums;
    }

// Important point - reason of best case senerio;
/*
1.Selection Sort - The main idea is to find the minimum element in rest of the array 
                   and place it to the available left most position. In every iteration 
                   there may be different minimum element hence it is important to traverse 
                   through the whole array every time. Hence the complexity is O(n^2).

2.Bubble Sort - The main idea is to find the maximum element in rest of the array and 
                take it to the right most position through swapping. While finding the 
                maximum element in first attempt through swapping ,if no swap happens is done
                int first iteration then, it is ensured that all elements are in sorted position.
                Only inner loop will run once,hence the complexity is O(n).

3.Insertion Sort - The main idea is to take an element and place it in the right place in the subarray
                   from the starting element to the current element. While comparing current element with 
                   previous element if it is greater then no swap will happen because all the elements before
                   that element is already sorted order. Only outer loop will run once in case of already sorted
                   array because everytime the inner loops starts it will exit because of the condition of while loop,
                   so inner loop will run once for every outer loop, hence the time complexity is O(n).
*/