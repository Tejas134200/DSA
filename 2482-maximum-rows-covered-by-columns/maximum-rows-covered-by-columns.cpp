class Solution {
public:
    int check(vector<vector<int>> mat){
        int n = mat.size();
        int m = mat[0].size();
        int ans =0;
        for(int i =0;i<n;i++){
            int c =0;
            for(int j =0;j<m;j++){
                c+=mat[i][j];
            }
            if(c==0) ans++;
        }
        return ans;
    }
    void findc(int i , int num , vector<vector<int>>& mat , int& ans ){
        if(num==0){
            int k = check(mat);
            ans=max(ans,k);
            return;
        }
        if(i==mat[0].size()) return;
        if(mat[0].size() - i < num) return;
        vector<vector<int>> temp = mat;
        for(int j =0;j<mat.size();j++){
            mat[j][i]=0;
        }
        findc(i+1,num-1,mat,ans);
        mat=temp;
        findc(i+1,num,mat,ans);
        return;


    }
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int maxi = -1;
        findc(0,numSelect,matrix,maxi);
        return maxi;
    }
};