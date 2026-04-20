class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        string ans(n+m-1 , 'a');
        vector<int> isFix(n+m-1 , 0);

        for(int i =0;i<n;i++){
            if(str1[i]=='T'){
                for(int j =i;j<i+m;j++){
                    ans[j] = str2[j-i];
                    isFix[j] = 1;
                }
            }
        }
        for(int i =0;i<n;i++){
            if(str1[i]=='F'){
                
                bool ok = true;

                for(int j=0;j<m;j++){
                    if(ans[i+j]!=str2[j]){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    for(int j = m-1;j>=0;j--){
                    if(ans[i+j]==str2[j]){
                        if(isFix[i+j]==0){
                            ans[i+j]='b';
                            break;
                        }
                    }
                    
                }
                }
                
            }
        }

        for(int i =0;i<n;i++){
            bool ok = true;

            for(int j=0;j<m;j++){
                if(ans[i+j]!=str2[j]){
                    ok = false;
                    break;
                }
            }

            if((str1[i]=='T'&&!ok) || (str1[i]=='F'&& ok)) return "";
        }
        return ans;
    }
};