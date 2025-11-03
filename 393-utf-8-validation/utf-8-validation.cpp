class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i =0;
        while(i<data.size()){
            int c =0;
            for(int j =7;j>=0;j--){
                if(data[i]&(1<<j)) c++;
                else break;
            }
            if(c==0){
                i++;
                continue;
            }
            if(c==1) return false;
            if(c>4) return false;   // <<< new needed rule

            c--;
            i++;

            while(c--){
                if(i>=data.size()) return false;
                if(!((data[i]&(1<<7)) && !(data[i]&(1<<6)))) return false;
                i++;
            }

        }
        return true;
    }
};
