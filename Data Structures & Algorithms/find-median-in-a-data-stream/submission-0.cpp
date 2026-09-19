class MedianFinder {
public:
    priority_queue<int, vector<int>> first_half;
    priority_queue<int, vector<int>, greater<int>> second_half;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        second_half.push(num);

        while(first_half.size()+1<second_half.size())
        {
            int tmp = second_half.top();
            first_half.push(tmp);
            second_half.pop();
        }

        if(!first_half.empty() and !second_half.empty() && second_half.top()<first_half.top())
        {
            second_half.push(first_half.top());
            first_half.pop();
            first_half.push(second_half.top());
            second_half.pop();
        }
    }
    
    double findMedian() {
        if((first_half.size()+second_half.size())%2==0)
        {
            return ((double)first_half.top() + (double) second_half.top())/(double)2.0;
        }

        return (double) second_half.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */