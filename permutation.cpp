#include<bits/stdc++.h>
using namespace std;
void recur(vector<int> &ds,vector<int> gi,vector<vector<int>> &ans,vector<int> &vis){
    if(ds.size()==gi.size()){
        ans.push_back(ds);
        return ;
    }
    for(int i=0;i<gi.size();i++){
        if(!vis[i]){
            ds.push_back(gi[i]);
            vis[i]=1;
            recur(ds,gi,ans,vis);
            vis[i]=0;
            ds.pop_back();
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<vector<int>> ans;vector<int> temp;
    vector<int> vis(n,0);
    recur(temp,arr,ans,vis);
    for(auto i: ans){
        for(auto j:i){
            cout<<j<<"  ";
        }
        cout<<endl;
    }
    return 0;

}