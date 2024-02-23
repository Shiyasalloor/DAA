#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
using namespace std;

const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int x){
   priority_queue<PII, vector<PII>, greater<PII> > Q;
   int y;
   long long minimumCost = 0;
   PII p;
   Q.push(make_pair(0, x));
   while(!Q.empty()){
      p = Q.top();
      Q.pop();
      x = p.second;
      if(marked[x] == true)
         continue;
      minimumCost += p.first;
      marked[x] = true;
      for(int i = 0; i < adj[x].size(); ++i){
         y = adj[x][i].second;
         if(marked[y] == false)
            Q.push(adj[x][i]);
      }
   }
   return minimumCost;
}

int main(){
   int nodes, edges, x, y;
   long long weight, minimumCost;
   cout << "\n\t PRIM'S ALGORITHM \nEnter the number of Node : ";
   cin >> nodes;
   cout << "Enter the number of Edges : ";
   cin >> edges;
   cout << "Enter source, destination, and weight of each edge respectively : \n";
   for(int i = 0; i < edges; ++i){
      cin >> x >> y >> weight;
      adj[x].push_back(make_pair(weight, y));
      adj[y].push_back(make_pair(weight, x));
   }
   minimumCost = prim(1);
   cout << "--------------------------------------------\n";
   cout << "The Minimal Cost : " << minimumCost << " units" << endl;
   cout << "--------------------------------------------\n";
   return 0;
}
