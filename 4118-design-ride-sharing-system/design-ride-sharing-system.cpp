class RideSharingSystem {
public:
    queue<int> r , d;
        unordered_set<int> al;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        r.push(riderId);
        al.insert(riderId);
    }
    
    void addDriver(int driverId) {
        d.push(driverId);
        
    }
    
    vector<int> matchDriverWithRider() {
        while(!r.empty()&&!d.empty()){
        int rider = r.front();
        r.pop();
        
        if(!al.count(rider)) continue;
        int driver = d.front();d.pop();
        al.erase(rider);
        return {driver,rider};
        }
        return {-1,-1};
    }
    
    void cancelRider(int riderId) {
        al.erase(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */