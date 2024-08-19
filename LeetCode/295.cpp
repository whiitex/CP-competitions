class MedianFinder {
    double med, l = 1e9, r = 1e9;
    int tot = 0;
    multiset<int> rx, lx;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        ++tot;
        if (tot == 1) {
            med = double(num); return;
        }

        if (r == 1e9 and l == 1e9) {
            if (num > med) rx.insert(num), lx.insert(med);
            else lx.insert(num), rx.insert(med);

            l = double(*lx.rbegin()); lx.erase(lx.find(*lx.rbegin()));
            r = double(*rx.begin()); rx.erase(rx.begin());
            med = (l + r) / 2; 
        } else {
            lx.insert(int(l)); rx.insert(int(r));
            l = 1e9; r = 1e9;

            if (num > *lx.rbegin()) rx.insert(num);
            else lx.insert(num);

            if (rx.size() > lx.size()) med = double(*rx.begin()), rx.erase(rx.begin());
            else med = double(*lx.rbegin()), lx.erase(lx.find(*lx.rbegin()));
        }

    }
    
    double findMedian() {
        return med;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */