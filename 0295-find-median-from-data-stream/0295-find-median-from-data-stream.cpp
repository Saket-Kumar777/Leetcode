class MedianFinder {
public:
    priority_queue<int> mxheap ;
    priority_queue<int, vector<int>, greater<int>> mnheap ;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        mxheap.push(num);
        mnheap.push(mxheap.top());
        mxheap.pop() ;

        if(mxheap.size() < mnheap.size())
        {
            mxheap.push(mnheap.top());
            mnheap.pop() ;
        }
    }
    
    double findMedian() {
        if(mxheap.size() > mnheap.size()) return mxheap.top();
        else return (mxheap.top() + mnheap.top()) / 2.0 ;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */