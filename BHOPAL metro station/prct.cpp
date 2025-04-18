#include<iostream>
#include<vector>
#include<utility>
using namespace std;
void example(vector<vector<char>>& matrix){
int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> pref(n,(vector<int>(m,0)));
        for(int j = 0; j< m ;j++)
        {
            int sum  = 0;
            for( int i= 0;i<n ; i++)
            {
                sum+=(matrix[i][j]-'0');
                if(matrix[i][j]=='0')
                sum = 0;
                
                pref[i][j]=sum;
            }
        }
        for(int i=0;i<n; i++)
        {
            for(int j=0; j<m ; j++)
            {
                cout<<pref[i][j]<<" ";
            }
            cout<<endl;
        }
}
int main()
{
    vector<vector<char>> matrix={{"1","0"}};
    example(matrix);
    return 0;
}