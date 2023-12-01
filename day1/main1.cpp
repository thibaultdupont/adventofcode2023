#include <bits/stdc++.h>
using namespace std;

int main()
{
  ifstream ifs("input");
  string line;
  int ans=0;
  while(getline(ifs, line)){
    ans += 10*(line[line.find_first_of("0123456789")]-'0');
    ans += line[line.find_last_of("0123456789")]-'0';
  }
  cout << ans << endl;
}
