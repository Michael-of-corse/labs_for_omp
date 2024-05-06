#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <vector>


typedef std::vector<std::vector <int>> matrix;
using namespace std;

int main()
{
  int n; cin>>n;
  matrix vec(n,std::vector<int> (n));
  for (auto& i : vec){
    for (auto& j:i){
      cin >> j;
    }
  }
  bool flc=0, flr=0,flx=0;
  int s0=0;
for(int i=0;i!=vec.size();++i)s0+=vec[0][i];
#pragma omp parallel{
#pragma omp sections{
  #pragma omp section{
    int s=0;
    for(int i =1; i !=vec.size(); ++i){
      for(int j:vec[i])s+=j;
      if(s0!=s){flr=1;break;break;}
        s=0;
    }
  }
  #pragma omp section{
  int s=0;
  for(int i=0;i!=vec.size();++i){
    for(int j=0;j!=vec.size();++j)s+=vec[j][i];
    if(s0!=s){flc=1;break;break;}
    s=0
  }
  #pragma omp section{
  int sx=0, sy=0;
  for(int i=0;i!=vec.size();++i){
    sx+=vec[i][i];
    sy+=vec[i][vec.size()-i];
  }
  if(sx!=sy){flx=1;}
  }
}
//}
//   }
// }
// }


}
