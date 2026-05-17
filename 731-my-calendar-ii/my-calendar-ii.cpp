class MyCalendarTwo {
public:
    map<int,int> mp;
    bool isP(){
        int count =0;
        for(auto it:mp){
            count+=it.second;
            if(count>=3) return false;
        }
        return true;
    }
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
        if(isP()) return true;
        else{
            mp[startTime]--;
            mp[endTime]++;
            return false;
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */