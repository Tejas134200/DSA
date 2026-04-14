class Solution {
public:
    bool isP(vector<int>& position, int m , int no){
        int i = 1;
        int prev = position[0];
        m--;
        while(i<position.size()){
            if(m==0) return true;
            if((position[i]-prev)>=no){
                prev= position[i];
                m--;
            }
            i++;
        }
        if(m==0) return true;
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int low = 1;
        int high = position[n-1]-position[0];
        int ans = 0;
        cout<<isP(position , m , 3);
        while(low<=high){
            int mid = low+(high-low)/2;

            if(isP(position , m , mid)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
        
    }
};