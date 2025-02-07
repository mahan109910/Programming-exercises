#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<pair<int, int>> points;  // ذخیره‌ی مختصات نقاط
map<int, vector<int>> adj;      // لیست مجاورت گراف
bool mark[100];

void dfs(int v){
    mark[v] = true;
    for(int u : adj[v]){
        if (!mark[u]){
            dfs(u);
        }
    }
}


int main () {
    int n;
    cin >> n;
    points.resize(n);

    map <int ,vector<int>> xGroup , yGroup;

    for(int i=0 ; i<n ; i++){
        cin >> points[i].first >> points[i].second;
        xGroup[points[i].first].push_back(i);
        yGroup[points[i].second].push_back(i);
    }

    for (auto &[_ , in] : xGroup){
        for (int i=1 ; i<in.size() ; i++){
            adj[in[i]].push_back(in[i-1]);
            adj[in[i-1]].push_back(in[i]);
        }

    }

    for (auto &[_ , in] : yGroup){
        for (int i=1 ; i<in.size() ; i++){
            adj[in[i]].push_back(in[i-1]);
            adj[in[i-1]].push_back(in[i]);
        }

    }

    int key = 0;
    for (int v=0; v<n ; v++){
        if (!mark[v]){
            dfs(v);
            key++;
        }
    }
    
    cout <<  key-1;

    return 0;
}