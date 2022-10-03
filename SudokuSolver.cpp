#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool sudok(vector<vector<int>> &solver){
int n=solver.size();
       for(int i=0;i<solver.size();i++){
         for(int j=0;j<solver.size();j++){
            if(solver[i][j]==0){
                for(int x=1;x<10;x++){
                    //solver[i][j]=x;
                    if(isSafe(solver,x,i,j)){
                          solver[i][j]=x;
                          if(sudok(solver)==true) return true;
                          else 
                          solver[i][j]=0;
                    }
                    //return false;

                }
                 return false;

            }
           
    

        }
       }
return true;


}
 bool isSafe(vector<vector<int>> solver,int x,int row,int col){
      int n=solver.size();
      for(int i=0;i<n;i++){
        if(solver[row][i]==x) return false;
        if(solver[i][col]==x) return false;
        if(solver[3*(row/3) + i/3][3*(col/3)+i%3]==x) return false;
      }   
      return  true;
         
      
 }
};
int main(){

   int x;
   cin>>x;
   vector<vector<int>> ans(x,vector<int>(x,0));
for(int i=0;i<x;i++){
    for(int j=0;j<x;j++){
          int k;
          cin>>k;
          ans[i][j]=k;
    }
}
     Solution ob;
     ob.sudok(ans);
     for(int i=0;i<x;i++){
       for(int j=0;j<x;j++){
       cout<<ans[i][j]<<"  ";

       }
       cout<<endl;
     }
return 0;
     
}