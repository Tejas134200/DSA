class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int col = encodedText.size()/rows;
        string ans ="";
        for(int i =0;i<col;i++){
            for(int j=0;j<rows;j++){
                int c = i+j;
                if(c<col){
                    ans+=encodedText[col*j+c];
                }
            }
        }
        int i = ans.size()-1;
        while(!ans.empty()&&ans.back()==' ') ans.pop_back();

        return ans;
    }
};