class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int lr=0,rr=n-1;
        while(lr<=rr){
            int mid=(lr+rr)/2;
            if(matrix[mid][0]==target) return true;
            else if(matrix[mid][0]<target){
                if(matrix[mid][m-1]<target)lr=mid+1;
                // else if(matrix[mid+1][0]==target) return true;
                else{
                    int lc=0,rc=m-1;
                    while(lc<=rc){
                        int mid2=(lc+rc)/2;
                        if(matrix[mid][mid2]==target) return true;
                        else if(matrix[mid][mid2]>target) rc=mid2-1;
                        else if(matrix[mid][mid2]<target) lc=mid2+1;
                    }
                    return false;
                }
            }
            else{
                rr=mid-1;
            }
        }
        return false;
    }
};
