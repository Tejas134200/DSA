/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool isLeaf (vector<vector<int>>& grid,int x,int y,int n,int val){
        for(int i=x; i<x+n; i++){
            for(int j=y; j<y+n; j++){
                if(grid[i][j]!=val)return false;
            }
        }
        return true;
    }
    Node* f(vector<vector<int>>& grid,int x,int y,int n){
        
        if(isLeaf(grid,x,y,n,grid[x][y])){
            Node* node = new Node(grid[x][y],true);
            return node;
        }
        
        Node* node = new Node(1,false);
        node->topLeft = f(grid,x,y,n/2);
        node->topRight = f(grid,x,y+n/2,n/2);
        node->bottomLeft = f(grid,x+n/2,y,n/2);
        node->bottomRight = f(grid,x+n/2,y+n/2,n/2);
        return node;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return f(grid,0,0,n);
    }
};