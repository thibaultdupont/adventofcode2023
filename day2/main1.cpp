#include <bits/stdc++.h>
using namespace std;

int main()
{
  unordered_map<string, int> max_color =
  {
    {"red", 12},
    {"green", 13},
    {"blue", 14}
  };

  ifstream ifs("input");
  string line;
  int ans=0;
  while(getline(ifs, line)){
    stringstream ssline(line);
    string game, semicolon, subset;
    int n;
    ssline >> game >> n >> semicolon;
    bool accepted = true;
    while(getline(ssline, subset, ';')){
      stringstream ss(subset);
      string color;
      while(getline(ss, color, ',')){
        string c;
        int cpt;
        stringstream sscolor(color);
        sscolor >> cpt >> c;
        if(cpt>max_color[c])
          accepted = false;
      }
    }
    if(accepted){
      ans+=n;
    }
  }
  cout << ans << endl;
}
