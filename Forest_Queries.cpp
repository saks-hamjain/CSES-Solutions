#include <bits/stdc++.h>
using namespace std;
class Forest
{
     public:
      int n;
      vector<vector<int>> prefix;

     Forest(int n ,vector<vector<char>> matrix)
    {
      this->n = n;
      prefix = vector<vector<int>>(n+1,vector<int>(n+1,0));
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<n;j++)
        {
            if(matrix[i][j] == '*')
            prefix[i+1][j+1] = 1+prefix[i+1][j] + prefix[i][j+1] - prefix[i][j];
            else
                prefix[i+1][j+1] = 0+prefix[i+1][j] + prefix[i][j+1] - prefix[i][j];
     }
     }
     }

      int calculate(int row1,int col1,int row2,int col2)
     {
        int sum = prefix[row2+1][col2+1] - prefix[row1][col2+1] - prefix[row2+1][col1] +prefix[row1][col1];
      return sum;
     }
};
      int main()
       {
          int n,q;
          cin>>n>>q;
          vector<vector<char>>matrix(n,vector<char>(n,'.'));


          for(int i=0;i<n;i++)
          {
             for(int j=0;j<n;j++)
                {
                    cin>>matrix[i][j];
                 }
          }


          Forest obj(n,matrix);
          for(int i=0;i<q;i++)
          {
               int row1,col1,row2,col2;
                cin>>row1>>col1>>row2>>col2;
                cout<<obj.calculate(row1-1,col1-1,row2-1,col2-1)<<endl;
          }


         return 0;

        }