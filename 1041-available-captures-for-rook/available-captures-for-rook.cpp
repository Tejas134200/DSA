class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int row=0;
        int col=0;
        int count=0;
       for(int i=0;i<board.size();i++)
       {
        for(int j=0;j<board[0].size();j++)
        {
            if(board[i][j]=='R')
            {
                row=i;
                col=j;
                break;
            }
        }
       }
       int rt=row;
       int ct=col;
       while(rt>=0)
       {
            if(board[rt][col]=='B') break;
            if(board[rt][col]=='p') 
            {
                count+=1;
                break;
            }
            rt--;
       }
       rt=row;
       ct=col;
       while(ct>=0)
       {
            if(board[row][ct]=='B') break;
            if(board[row][ct]=='p') 
            {
                count+=1;
                break;
            }
            ct--;
       }
       rt=row;
       ct=col;
       while(rt<board.size())
       {
            if(board[rt][col]=='B') break;
            if(board[rt][col]=='p') 
            {
                count+=1;
                break;
            }  
            rt++;   
       }
       rt=row;
       ct=col;
       while(ct<board[0].size())
       {
            if(board[row][ct]=='B') break;
            if(board[row][ct]=='p') 
            {
                count+=1;
                break;
            }  
            ct++;   
       }
       return count;
    }
};