class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int,int> mp;
        for(auto &it:obstacles){
            mp[it[0]+30000*it[1]]++;
        }
        char dir[] = {'N','E','W','S'};

        int cd = 0;
        int x =0;
        int y =0;
        int ans =0;
        int i =0;
        while(i<commands.size()){
            if(commands[i]==-1) cd = (cd+1)%4;
            else if(commands[i]==-2) cd = (cd+4-1)%4;
            else{
                if(dir[cd]=='N'){
                    while(commands[i]--){
                        if(!mp.count(x+(y+1)*30000)){
                            y=y+1;
                            ans=max(ans , y*y+x*x);
                        }else{
                            break;
                        }
                    }
                    i++;
                    continue;
                }
                else if(dir[cd]=='E'){
                    while(commands[i]--){
                        if(!mp.count(x+1+(y)*30000)){
                            x=x+1;
                            ans=max(ans , y*y+x*x);
                        }else{
                            break;
                        }
                    }
                    i++;
                    continue;
                }
                else if(dir[cd]=='W'){
                    while(commands[i]--){
                        if(!mp.count(x+(y-1)*30000)){
                            y=y-1;
                            ans=max(ans , y*y+x*x);
                        }else{
                            break;
                        }
                    }
                    i++;
                    continue;
                }
                else if(dir[cd]=='S'){
                    while(commands[i]--){
                        if(!mp.count(x-1+(y)*30000)){
                            x-=1;
                            ans=max(ans , y*y+x*x);
                        }else{
                            break;
                        }
                    }
                    i++;
                    continue;
                }
            }
            i++;
        }
        return ans;
    }
};