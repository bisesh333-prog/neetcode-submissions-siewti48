class Solution {
public:
    bool check(string s){
        if(s=="+"||s=="-"||s=="*"||s=="/"){
            return true;
        }
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(!check(tokens[i])) st.push(stoi(tokens[i]));
            else{
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                if(tokens[i]=="+"){
                    st.push(n1+n2);
                }
                else if(tokens[i]=="-"){
                    st.push(n2-n1);
                }
                else if(tokens[i]=="*"){
                    st.push(n2*n1);
                }
                else if(tokens[i]=="/"){
                    st.push(n2/n1);
                }
            }
        }
        return st.top();
    }
};
