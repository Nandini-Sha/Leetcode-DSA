class MedianFinder {
private:
    priority_queue<int,vector<int>,greater<int>> RightMin;
    priority_queue<int> LeftMax;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        LeftMax.push(num);

        RightMin.push(LeftMax.top());
        LeftMax.pop();

        if(RightMin.size()>LeftMax.size()){
            LeftMax.push(RightMin.top());
            RightMin.pop();
        }
        
    }
    
    double findMedian() {
        if(LeftMax.size() == RightMin.size()) return (LeftMax.top()+RightMin.top())/2.0;

        return LeftMax.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */