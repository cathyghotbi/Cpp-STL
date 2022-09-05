
// iterators
// https://en.cppreference.com/w/cpp/container/map
// https://en.cppreference.com/w/cpp/container/map/rbegin


#include <iostream>
#include <map>

int main() 
{
  std::map<int, std::string> test{{11, "eleven"}, {2, "two"}, {5, "five"}, {1, "one"}, {10, "ten"}};
  //----------------------------------------------------------------------------------------
  // iterator with for loop
  for(auto it = test.begin(); it != test.end(); it++)
  {
    //std::cout << (*it).first << ' ' << (*it).second << "; ";
    std::cout << it->first << ' ' << it->second << "; ";
  }
  //---------------------------------------------------------------------------------------- 
  // range-based for loop from C++17
  for(auto& [key, value] : test)
  {
    std::cout << key << ' ' << value << "; ";
  }
  std::cout << std::endl;
  //----------------------------------------------------------------------------------------
  // reverse iteration
  for(auto revIt = test.rbegin(); revIt != test.rend(); revIt++)
  {
    std::cout << (*revIt).first << ' ' << (*revIt).second << "; ";
  }
  std::cout << std::endl;
  //----------------------------------------------------------------------------------------
  return 0;
}
