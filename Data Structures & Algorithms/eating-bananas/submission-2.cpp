class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxm = *max_element(piles.begin(), piles.end());
        int l=1, r=maxm, ans=INT_MAX;
        while(l<=r){
            int mid = (l+r)/2;
            int len=0;
            for(int i=0;i<piles.size();i++){
                if(piles[i]%mid) len+=piles[i]/mid+1;
                else len+=piles[i]/mid;
            }
            if(len<=h){
                ans=min(ans,mid);
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return ans;
    }
};
