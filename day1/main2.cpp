#include <bits/stdc++.h>
using namespace std;

int main()
{
  array<string, 20> search_list = {"0","1","2","3","4","5","6","7","8","9","0",
    "one","two","three","four","five","six","seven","eight", "nine"};

  array<string, 20> reverse_search_list;
  for(int i=0; i<20;++i){
    reverse_search_list[i] = string(search_list[i].rbegin(), search_list[i].rend());
  }

  auto find_first_of_string = [](string str, auto& search_list){
    unsigned m = -1;
    int idx = 0;
    for(int i = 0; i<search_list.size(); ++i){
      unsigned n = str.find(search_list[i]);
      if(n<m){
        m=n;
        idx=i;
      }
    }
    return idx;
  };

  ifstream ifs("input");
  string line;
  int ans=0;
  while(getline(ifs, line)){
    ans+=find_first_of_string(line,search_list)%10*10;
    line = string(line.rbegin(), line.rend());
    ans+=find_first_of_string(line,reverse_search_list)%10;
  }
  cout << ans << endl;
}
