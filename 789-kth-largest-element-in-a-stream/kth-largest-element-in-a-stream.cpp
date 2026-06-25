class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> stream;
    int el;
    KthLargest(int k, vector<int>& nums) {
        int i = 0;
        el = k;
        while(i<k && i<nums.size()){
            stream.push(nums[i++]);
        }
        while(i<nums.size()){
            if(nums[i]>stream.top()){
                stream.pop();
                stream.push(nums[i]);
            }
            i++;
        }
    }
    
    int add(int val) {
        stream.push(val);
        if(stream.size()>el){
                stream.pop();
        }
        return stream.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */