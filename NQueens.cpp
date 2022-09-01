#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
void NQueen(int col,vector<vector<string>> &board,vector<string> &sol,vector<int> leftRow,vector<int> upper,vector<int> lower){
     int n=sol.size();
if(col==n){
     board.push_back(sol);
     return;
}
for(int row =0 ;row<n;row++){
    if(leftRow[row]==0 && upper[n-1+col-row]==0 && lower[row +col]==0){
       sol[row][col]='Q';
       leftRow[row]=1;
       lower[row+col]=1;
       upper[n-1+col-row]=1;
       NQueen(col+1,board,sol,leftRow,upper,lower);
       leftRow[row]=0;
       lower[row+col]=0;
       upper[n-1+col-row]=0;
       sol[row][col]='.';





    }
}
}
vector<vector<string>> so(int n){
    vector<vector<string>> ans;
    vector<string> sol(n);
    string s(n,'.');
      for(int i=0;i<n;i++) sol[i]=s;
      vector<int> leftRow(n,0),upper(2*n-1,0),lower(2*n-1,0);
      NQueen(0,ans,sol,leftRow,upper,lower);
      return ans;
}
};
int main(){
int n;
cin>>n;
vector<vector<string>> an;
Solution of;
an=of.so(n);
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<an[0][i][j]<<"  ";
    }
    cout<<endl;
}
cout<<endl<<endl;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<an[1][i][j]<<"  ";
    }
    cout<<endl;
}
return 0;

}

