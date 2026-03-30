class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        for(int i=0; i<position.size(); i++){
            v.push_back({position[i], speed[i]});
        }
        sort(v.rbegin(), v.rend());
        stack <double> st;
        for(auto it: v){
            if(st.empty()){
                double t = (double)(target-it.first)/it.second;
                st.push(t);
            }
            else{
                double t = (double)(target-it.first)/it.second;
                if(t>st.top()){
                    st.push(t);
                }
            }
        }
        return st.size();
    }
};
