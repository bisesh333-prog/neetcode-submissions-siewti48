class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(left.empty()) left.push(num);
        else{
            if(left.top()>=num) left.push(num);
            else right.push(num);
            int lsize = left.size();
            int rsize;
            if(!right.empty()){
                rsize = right.size();
            }
            else{
                rsize = 0;
            }
            while(lsize-rsize>1){
                right.push(left.top());
                rsize++;
                left.pop();
                lsize--;
            }
            while(rsize-lsize>0){
                left.push(right.top());
                lsize++;
                right.pop();
                rsize--;
            }
        }
        return;
    }
    
    double findMedian() {
        if((left.size()+right.size())%2==0) return double(left.top()+right.top())/double(2);
        else return double(left.top());
    }
};
