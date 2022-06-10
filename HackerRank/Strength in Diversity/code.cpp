#include <bits/stdc++.h>
using namespace std;

//this functions returns the parent of the set. same method used in the Kruskal algorithm last week.
int unionSet(int* parent, int u){
  if (parent[u] == u){
    return u;
  }
  return unionSet(parent, parent[u]);
}

// calculate the combinations
int nCr(int n, int r)
{
    int res = 1;
    for (int i = n; i > n - r; i--)
        res = res * i;
    for (int i = 1; i <= r; i++)
        res = res / i;
    return res;
}


int findCombinations(int n, vector<pair<int, int>> edges){
    // each node represent a student and each edge represet a pair. we have to find the number of connected graphs and thier vertices.
  int parent[n];    
  for (int i = 0; i < n; i++)
  {
    parent[i] = i; // first let the parent of each node to itself
  }

  for (int i = 0; i < (int)edges.size(); i++)
  {
    parent[unionSet(parent, edges[i].second)] = unionSet(parent, edges[i].first);   //find the common set.
  }
    
    // this for loop finalize the parent array because in some cases there may be two parents for same set.
  for (int i = 0; i < n; i++) {
        parent[i] = unionSet(parent, parent[i]);
  }
  unordered_map<int, int> dist; // hashmap for store the number of students in same district
  for (int i = 0; i < n; i++)
  {
    dist[parent[i]]++;
  }
  int comb = nCr(n, 2); // all the combinations 

  for (int i = 0; i < n; i++)
  {
    if (parent[i]==i){
      comb -= nCr(dist[i], 2);  // remove the combinations form from same district
    }
  }
  return comb;
}

int main()
{
    int n, p;   
    cin >> n >> p;
    vector<pair<int, int>> edges(p);    // append each edges to vector pair
    int u, v;
    for (int i = 0; i < p; i++)
    { 
      cin >> u >> v;
      edges[i].first = u;
      edges[i].second = v;
    }
    int pairs = findCombinations(n, edges);
    cout << pairs;
    return 0;
}