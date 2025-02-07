#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
map<int ,vector<int>> adj;
map <int , bool > mark;
//bool mark [100];
 
void dfs(int v){
    mark[v] = true;
    for (int u : adj[v]){
        if (!mark[u]){
            dfs(u);
        }
    }
}
 
int main (){
    int n, z, noz=0;
    cin >> n >> z;
 
     vector<vector<int>> languages(n);
 
    for (int i = 0; i < n; i++) {
        adj[i] = vector<int>(); 
    }
 
    
    for (int i = 0; i < n; i++) {
        int k;  
        cin >> k;
        if (k==0)
            noz++;
        for (int j = 0; j < k; j++) {
            int lang;
            cin >> lang;
            languages[i].push_back(lang);
        }
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int lang1 : languages[i]) {
                for (int lang2 : languages[j]) {
                    if (lang1 == lang2) {
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                        break;
                    }
                }
            }
        }
    }
}