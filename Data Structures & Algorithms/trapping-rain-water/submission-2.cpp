class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftmax=height[0], rightmax=height[n-1];
        int l=0,r=n-1, p=0;
        while(l<r){
            if(height[l]<height[r]){
                l++;
                leftmax=max(leftmax,height[l]);
                p+=leftmax-height[l];
            }
            else{
                r--;
                rightmax=max(rightmax,height[r]);
                p+=rightmax-height[r];
            }
        }
        return p;
    }
};
