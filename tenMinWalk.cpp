/* A city provides an app that gives people a path to walk.
Each block (n,s,w,e) takes 1 minute to walk.
Determine if the array path takes exactly 10 minutes and brings you back to original point. */

#include <vector>
#include <iostream>

bool isValidWalk(std::vector<char> walk) 
{
  if (walk.size() != 10) return false;
  
  int sum=0;
  for (int i=0; i<walk.size(); i++)
  {
    if (i=='n') 
        sum+=1;
    else if (i=='s') 
        sum-=1;
    else if (i=='w') 
        sum+=walk.size()+1; //num must be >walk.size() so sum only equals 0 when walk=10 and back at origin point
    else if (i=='e') 
        sum-=walk.size()+1;
  }

  return sum==0;
}

int main()
{
  std::vector<char> path;
  path.push_back('n');
  path.push_back('s');
  std::cout << isValidWalk(path) << std::endl;
}