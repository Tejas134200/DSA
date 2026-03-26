class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       vector<int> freq(26,0);
       priority_queue<int> pq;
       queue<pair<int,int>> q;
       int time = 0;
       for(char c:tasks) freq[c-'A']++;
       for(int i =0;i<26;i++){

            if(freq[i]>0)  pq.push(freq[i]);
           
       }
       while(!pq.empty()||!q.empty()){
            time++;
            if(!pq.empty()){
                auto topi = pq.top();
                pq.pop();
            

                topi--;
                if(topi>0)  q.push({topi,time+n});
            
            }

            while(!q.empty()&&q.front().second<=time){
                pq.push(q.front().first);
                q.pop();
            }

       }

       return time;

    
    }
};