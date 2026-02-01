class Solution {
public:
    string reverseByType(string A) {
      int n = A.size();

      int i = 0, j = n - 1;
      while(i <= j) {
        if(isalpha(A[i]) && isalpha(A[j]))
          swap(A[i++], A[j--]);
        else if(isalpha(A[i]))
          --j;
        else if(isalpha(A[j]))
          ++i;
        else {
          ++i;
          --j;
        }
      }

      i = 0;
      j = n - 1;
      while(i <= j) {
        if(!isalpha(A[i]) && !isalpha(A[j]))
          swap(A[i++], A[j--]);
        else if(!isalpha(A[i]))
          --j;
        else if(!isalpha(A[j]))
          ++i;
        else {
          ++i;
          --j;
        }
      }
      return A;
    }
};