
// iterators
// https://en.cppreference.com/w/cpp/container/vector
// https://en.cppreference.com/w/cpp/algorithm/remove
// https://en.cppreference.com/w/cpp/container/vector/reserve
#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
  std::vector<int> test{11, 2, 5, 1, 10, 55, 3, 22};
  //----------------------------------------------------------------------------------------
  // index-based for loop
  for(int i = 0; i != test.size(); i++)
  {
    std::cout << test[i] << ' ';
  }
  std::cout << std::endl;
  //----------------------------------------------------------------------------------------
  // iterator with for loop
  for(auto it = test.begin(); it != test.end(); it++)
  {
    std::cout << *it << ' ';
  }
  std::cout << std::endl;
  //----------------------------------------------------------------------------------------  
  // range-based for loop
  for(auto& value : test)
  {
    std::cout << value << ' ';
  }
  std::cout << std::endl;
  //---------------------------------------------------------------------------------------- 
  // deleting odd numbers while iterating the vector
  test.erase(std::remove_if(test.begin(),
                            test.end(),
                            [](int elem){return (elem % 2) == 1;}),
            test.end()); // return it to the 'new end' since removing invalidates the it
  for(auto& value : test)
  {
    std::cout << value << ' ';
  }
  std::cout << std::endl;
  //----------------------------------------------------------------------------------------  
  // inserting an item while iterating the vector, adding some odd values
  for(auto it = test.begin(); it != test.end(); it++)
  {
    if((*it % 2) == 0)
    {
      test.push_back((*it)+1);
    }
  }

  for(auto& value : test)
  {
    std::cout << value << ' ';
  }
  std::cout << std::endl;
  //----------------------------------------------------------------------------------------  
 //Increase the capacity of the vector (the total number of elements that the vector can hold without requiring reallocation)
  test.reserve(test.size()*2);
  for(auto it = test.begin(); it != test.end(); it++)
  {
    if((*it % 2) == 0)
    {
      test.push_back((*it)+1);
    }
  }
  for(auto& value : test)
  {
    std::cout << value << ' ';
  }
  std::cout << std::endl;
  //----------------------------------------------------------------------------------------
  return 0;
}
