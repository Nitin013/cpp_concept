
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include<iterator>
using namespace std;


class m_map
{
public:
  map<int, vector<int>> m;
  vector<int> weight;
};
int find(vector<int> &vec, int a)
{
  while (vec[a] != a)
  {
    a = vec[a];
  }
  return a;
}


void kruscal(m_map &obj, int n)
{
  vector<int> vec(n + 1);
  for (int i = 0; i < vec.size() + 1; i++)
  {
    vec[i] = i;
  }
  map<int, vector<int>> ans;
  for (int i = 0; i < obj.weight.size(); i++)
  {
    int a = obj.m[obj.weight[i]][0];
    int b = obj.m[obj.weight[i]][1];
    if (find(vec, a) != find(vec, b))
    {
      int a1 = find(vec, a);
      int b1 = find(vec, b);
      vec[a1] = b1;
      ans[obj.weight[i]].push_back(a);
      ans[obj.weight[i]].push_back(b);
      vector<int>::iterator it = obj.m[obj.weight[i]].begin();
      obj.m[obj.weight[i]].erase(it, it + 1);
    }
  }
  map<int, vector<int>>::iterator it=ans.begin();
  for (it = ans.begin(); it != ans.end(); it++)
  {
    cout << it->first << " ";
    for (int i = 0; i < it->second.size(); i++)
    {
      cout << it->second[i];
    }
    cout << endl;
  }
}



int main()
{
  cout << "enter the no. of nodes of graph";
  int n, i = 1;
  cin >> n;
  m_map obj;
  while (i)
  { // to get realtion between nodes
    cout << "enter the path ";
    int k, j, w;
    cin >> k >> j;
    cout << "enter the weight";
    cin >> w;
    obj.m[w].push_back(k);
    obj.m[w].push_back(j);
    obj.weight.push_back(w);
    cout << "enter 1 to make more connection" << endl
         << "enter 0 to stop ";
    cin >> i;
  }
  sort(obj.weight.begin(), obj.weight.end());
  kruscal(obj, n);
  return 0;
}
