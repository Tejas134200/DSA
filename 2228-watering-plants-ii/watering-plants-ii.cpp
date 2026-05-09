class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int a = capacityA;
        int b = capacityB;
        int res = 0;

        for(int i = 0, j=n-1;i<n/2;i++,j--){
            if(plants[i]>a){
                a=capacityA;
                res++;
            }
            a-=plants[i];
            if(plants[j]>b){ b = capacityB ;res++;}
            b-=plants[j];
        }
        if(n%2==1){
            if(a>=plants[n/2]||b>=plants[n/2]){}
            else res++;
        }
        return res;
    }
};