class KthLargest {
private:
    int capacity;
    priority_queue<int,vector<int>,greater<int>> minheap;
public:
    KthLargest(int k, vector<int>& nums) {
        // minheap.clear();
        capacity=k;
        for(auto num:nums){
            if(minheap.size()<k){
                minheap.push(num);
            }
            else{
                if(num>minheap.top()){
                    minheap.pop();
                    minheap.push(num);
                }
            }
        }
    }
    
    int add(int val) {
        if(minheap.size()<capacity){
                minheap.push(val);
            }
        else{
            if(val>minheap.top()){
                minheap.pop();
                minheap.push(val);
            }
        }
        return minheap.top();
    }
};
