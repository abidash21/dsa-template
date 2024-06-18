// Leetcode Question: 307. Range Sum Query - mutable

/* Time Complexity:- 
    buildTree - O(n)
    updateTree - O(log(n))
    queryTree - O(log(n))
*/

// space Complexity:- O(n)
// maximum total space a segment tree takes - 4*size of the nums array
   
class SegmentTree {
    vector<int>seg;
public:
    SegmentTree() {}
    SegmentTree(vector<int>&nums){
        int n=nums.size();
        seg.resize(4*n,0);
        buildTree(0,0,n-1,nums);
    }

    void buildTree(int pos,int left,int right,vector<int>&nums){
        if (left==right){
            seg[pos]=nums[left];
            return;
        }
        int mid=left+(right-left)/2;
        buildTree(2*pos+1,left,mid,nums);
        buildTree(2*pos+2,mid+1,right,nums);
        seg[pos]=seg[2*pos+1]+seg[2*pos+2];
    }

    void updateTree(int idx,int val,int pos,int left,int right){
        if (left==right){
            seg[pos]=val;
            return;
        }
        int mid=left+(right-left)/2;
        if (idx<=mid){
            updateTree(idx,val,2*pos+1,left,mid);
        } else {
            updateTree(idx,val,2*pos+2,mid+1,right);
        }
        seg[pos]=seg[2*pos+1]+seg[2*pos+2];
    }

    int queryTree(int qleft,int qright,int left,int right,int pos){
        if (qleft<=left && qright>=right) return seg[pos];
        if (qleft>right || qright<left) return 0;
        int mid=left+(right-left)/2;
        int l=queryTree(qleft,qright,left,mid,2*pos+1);
        int r=queryTree(qleft,qright,mid+1,right,2*pos+2);
        return l+r;
    }
};
class NumArray {
    SegmentTree st;
    int n;
public:
    NumArray(vector<int>& nums) {
        this->st=SegmentTree(nums);
        this->n=nums.size();
    }
    
    void update(int index, int val) {
        st.updateTree(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return st.queryTree(left,right,0,n-1,0);
    }
};
