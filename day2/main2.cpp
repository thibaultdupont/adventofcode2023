#include <bits/stdc++.h>
using namespace std;

int main()
{
  ifstream ifs("input");
  string line;
  int ans=0;
  while(getline(ifs, line)){
    unordered_map<string, int> num_color;
    stringstream ssline(line);
    string game, semicolon, subset;
    int n;
    ssline >> game >> n >> semicolon;
    while(getline(ssline, subset, ';')){
      stringstream ss(subset);
      string color;
      while(getline(ss, color, ',')){
        string c;
        int cpt;
        stringstream sscolor(color);
        sscolor >> cpt >> c;
        num_color[c] = max(num_color[c],cpt);
      }
    }
    int power = 1;
    for(auto& l:num_color){
      power*=l.second;
    }
    ans+=power;
  }
  cout << ans << endl;
}
