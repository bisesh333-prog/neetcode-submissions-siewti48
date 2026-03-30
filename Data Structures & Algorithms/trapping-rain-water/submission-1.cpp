class Solution {
public:
    int trap(vector<int>& height) {
        int l=0, maxm=0, p=0;
        int n = height.size();
        if(n==1)return 0;
        for(int r=1;r<n;r++){
            if(height[l]>height[r]){
                p += height[l]-height[r];
            }
            else{
                maxm+=p;
                p=0;
                l=r;
            }
        }
        int r = n-1;
        p=0;
        for(int l=n-2;l>=0;l--){
            if(height[r]>=height[l]){
                p += height[r]-height[l];
            }
            else{
                maxm+=p;
                p=0;
                r=l;
            }
        }
        return maxm;
    }
};
