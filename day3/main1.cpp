#include <bits/stdc++.h>
using namespace std;

int main()
{
  ifstream ifs("input");
  int ans=0;

  auto do_line = [](auto& lines){
    auto check_valid =
      [](auto& lines, int i){
        for(int nx=-1;nx<=1;++nx)
          for(int ny=-1;ny<=1;++ny)
            if(i+nx>=0 && i+nx<lines[0].size() && !isdigit(lines[1-ny][i+nx]) && lines[1-ny][i+nx]!='.')
              return true;
        return false;
      };

    int ans=0;
    for(int i=0;i<lines[0].size();++i){
      int current=0;
      bool valid = false;
      while(i<lines[0].size() && isdigit(lines[1][i])){
        current *=10;
        current += lines[1][i]-'0';
        valid = valid || check_valid(lines, i);
        ++i;
      }
      if(valid)
        ans += current;
  }
  return ans;
};
array<string,3> lines;
getline(ifs, lines[0]);
lines[1]=lines[0];
getline(ifs, lines[2]);
ans += do_line(lines);
lines[1]=lines[2];
while(getline(ifs, lines[2])){
  ans += do_line(lines);
  lines[0] = lines[1];
  lines[1] = lines[2];
}
lines[2] = lines[1];
ans += do_line(lines);
cout << ans << endl;
}
