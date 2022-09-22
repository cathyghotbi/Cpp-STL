#include <iostream>
#include <tuple>

class Person
{
public:
  Person(std::string name, std::uint32_t hr, std::uint32_t min, std::uint32_t sec)
    : m_name(name), m_hour(hr), m_minute(min), m_second(sec)
    {
    }
   
  bool operator<(const Person& otherPerson)  
  {
    return std::make_tuple(m_hour, m_minute, m_second) < 
           std::make_tuple(otherPerson.m_hour, otherPerson.m_minute, otherPerson.m_second);
  }

  std::string getName() const
  {
    return m_name;
  }

private:
  std::string m_name;
  std::uint32_t m_hour;
  std::uint32_t m_minute;
  std::uint32_t m_second;
};

void findFasterRunner(Person& onePerson, Person& anotherPerson)
{
  std::cout << onePerson.getName() << " is faster than " << anotherPerson.getName() << 
 ": " << (onePerson < anotherPerson) << std::endl;
}

int main()
{
  Person Robert("Robet", 2, 55, 170);
  Person Sara("Sara", 2, 45, 165);
  Person Kevin("Kevin", 1, 25, 185);
  Person Eli("Eli", 3, 35, 185);

  findFasterRunner(Robert, Sara);
  findFasterRunner(Sara, Robert);
  findFasterRunner(Kevin, Robert);
  findFasterRunner(Robert, Kevin);
  findFasterRunner(Robert, Eli);
  findFasterRunner(Eli, Robert);

  return 0;
}
