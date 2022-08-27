
#include <iostream>
#include <vector>
#include <algorithm>

class Entity
{
public:
  Entity(std::string name, std::uint32_t id)
  : m_name(name), m_id(id)
  {
  }

static std::vector<std::string> getAllNames(std::vector<Entity> en)
{
  std::vector<std::string> entityNames{};
  
   std::transform(std::begin(en), std::end(en),
                  std::back_inserter(entityNames),        
                    [](Entity e){
                       return e.m_name;

  });  

  return entityNames;
}

public:
  std::string m_name;
  std::uint32_t m_id;
};

int main() 
{
  std::vector<Entity> test;
  
  Entity en1("en1", 1);
  test.push_back(en1);
  Entity en2("en2", 2);
  test.push_back(en2);
  Entity en3("en3", 3);
  test.push_back(en3);
  Entity en4("en4", 4);
  test.push_back(en4);
  Entity en5("en5", 5);
  test.push_back(en5);

  std::vector<std::string> result = Entity::getAllNames(test);
  
  std::cout << "names are: " << std::endl;
  for(auto it : result)
  {
    std::cout << it << " ";  
  }
  std::cout << std::endl;

  return 0;
}
