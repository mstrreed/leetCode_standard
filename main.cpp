#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<char>>& a,int r,int c,int n)
{
    bool ans=true;
    if(a[r][c]=='O'&&(r==n-1||c==n-1||r==0||c==0))
    {
        return false;
    }
    if(a[r][c]=='X')
    {
        return true;
    }
    if(a[r][c]=='S')
    {
        return true;
    }
    a[r][c]='S';
     ans=ans&isSafe(a,r+1,c,n);
     ans=ans&isSafe(a,r,c+1,n);
     ans=ans&isSafe(a,r-1,c,n);
     ans=ans&isSafe(a,r,c-1,n);
    a[r][c]='O';
    return ans;

}
    void solve(vector<vector<char>>& board) {
        for(int i;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='O'&&isSafe(board,i,j,board.size()))
                {
                    board[i][j]='X';
                }
            }
        }
        vector<vector<char>> board1=board;
        for(auto i:board1)
        {
            for(auto j:i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

int main()
{
    vector<vector<char>> board={{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    solve(board);
    return 0;

}
