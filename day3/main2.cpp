#include <bits/stdc++.h>
#include <cctype>
#include <iterator>
#include <sstream>
using namespace std;

map<pair<int, int>, vector<int>> gears;
int current_line=0;

int main()
{
  ifstream ifs("input");
  int ans=0;

  auto do_line = [](auto& lines){
    auto check_valid =
      [](auto& lines, int i, auto& stars){
        for(int nx=-1;nx<=1;++nx)
          for(int ny=-1;ny<=1;++ny)
            if(i+nx>=0 && i+nx<lines[0].size() && lines[1+ny][i+nx]=='*')
              stars.insert({1+ny, i+nx});
      };

    int ans=0;
    for(int i=0;i<lines[0].size();++i){
      int current=0;
      set<pair<int, int>> stars;
      while(i<lines[0].size() && isdigit(lines[1][i])){
        current *=10;
        current += lines[1][i]-'0';
        check_valid(lines, i, stars);
        ++i;
      }
      for(auto& s : stars)
        gears[{s.first+current_line, s.second}].push_back(current);
    }
    return ans;
  };

  array<string,3> lines;
  getline(ifs, lines[1]);
  lines[0]=string(lines[1].size(), '.');
  getline(ifs, lines[2]);
  do_line(lines);
  lines[1]=lines[2];
  while(getline(ifs, lines[2])){
    ++current_line;
    do_line(lines);
    lines[0] = lines[1];
    lines[1] = lines[2];
  }
  ++current_line;
  lines[2]=string(lines[1].size(), '.');
  do_line(lines);

  for(auto& g:gears){
    if(g.second.size() == 2)
      ans+=g.second[0]*g.second[1];
  }
  cout << ans << endl;
}
