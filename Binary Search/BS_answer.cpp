/*
  1.find the type of answer the question is asking. i.e. speed,time;
  2.find the minimum possible value and maximum possible value;(s & e of binary search);
  3.in the while loop S<e or s<=e depends upo whther the extrem ends are possible answer or not
  4.If the question asks return the minimum value, then if condition must check whther the same value or greater than that.
  5.if condition update ans=mid, minimum: r=mid-1 & maximum: r=mid+1
*/

//Leetcode 875

    bool reqTime(int speed,int h,vector<int>&piles){
        int tot=0;
        for (int i=0;i<piles.size();i++){
            tot+=piles[i]/speed;
            if (piles[i]%speed) tot++;
            if (tot>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=*max_element(piles.begin(),piles.end());
        int speed;
        while(s<=e){
            int mid=s+(e-s)/2;
            if (reqTime(mid,h,piles)){
                speed=mid;
                e=mid-1;
            } else {
                s=mid+1;
            }
        }
        return speed;
    }