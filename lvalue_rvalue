#include <iostream>

class LRvalue
{
public:
  LRvalue()
  {
    std::cout << "c-tor" << std::endl;
  }
  
  void func(int& x) //void func(const int& x) works for both lvalue and rvalue
  {
    std::cout << "func with arg Lvalue " << x << std::endl;
  }
  
  void func(int&& x)
  {
    std::cout << "func with arg Rvalue " << x << std::endl;
  }
};


int main() {
  LRvalue lrvalue;
  
  int var = 10;
  
  lrvalue.func(var);
  lrvalue.func(55);
  
  return 0;
}
