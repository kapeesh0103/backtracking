#include<bits/stdc++.h>
using namespace std;
  vector<string> result;
vector<vector<int>> vis(5,vector<int> (5,0));
class Solution{
    public:
    void rat(vector<vector<int>> &m , string dir, int x,int y,int n ){
        if(x==n-1 && y==n-1){
            result.push_back(dir);
            return ;
            
        }
        if(m[x][y]==0 || vis[x][y]==1) return;
        vis[x][y]=1;
        if(x<n-1) rat(m,dir +'D',x+1,y,n);
        if(y<n-1) rat(m,dir +'R',x,y+1,n);
        if(x>0) rat(m,dir +'U',x-1,y,n);
        if(y>0) rat(m,dir +'L',x,y-1,n);
        vis[x][y]=0;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
      //  if(m[0][0]==0 || m[n-1][n-1]==0) return result;
     // result.clear();
    //  for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         vis[i][j]=false;
    //     }
    //  }
     result.clear();
     if(m[0][0]==0 || m[n-1][n-1]==0) return result;
        rat(m,"",0,0,n);
        if(result.size()>0)
        sort(result.begin(),result.end());
        return result;
        
    }
};
int main(){
    // int t;
    // cin>>t;
    // while(t--){
        int n;
        cin>>n;
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                int x;
                cin>>x;
                temp.push_back(x);
            }
            v.push_back(temp);
        }
Solution ob;
 vector<string> ans=ob.findPath(v,n);
 if(ans.size()==0){
    return -1;
 }
 else{
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
 }

   // }
    return 0;
}