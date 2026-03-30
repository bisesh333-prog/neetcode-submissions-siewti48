class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int l=0,r=n-1, ans=0;
        while(l<r){
            int area=min(heights[l],heights[r])*abs(r-l);
            ans=max(area,ans);
            if(heights[l]<heights[r]){
                l++;
            }
            else if(heights[l]>heights[r]){
                r--;
            }
            else{
                l++;
                r--;
            }
        }
        return ans;
    }
};

