#include <iostream>

// Ensure a class only has one instance, and provide a global point of access
// to it.

// few things to remember:
// 1. singleton is just an enchanted global
// 2. some people regard it as an antipattern
// 3. it's pain when you need it tread safe (impossible)
// 4. it's pain when unit testing! again, it's a global state!
// 5. it's useful for simple factories and such
// 6. there are many versions of this

class MeyersSingleton // MeyersSingleton is simple and clean
{
  public:
    static MeyersSingleton& getInstance()
    {
      static MeyersSingleton s;
      return s;
    }

    void DoSomething() const
    {
      std::cout << "Doing something!" << std::endl;
    }

  private:
    MeyersSingleton() {}
    MeyersSingleton& operator=(const MeyersSingleton&);
    MeyersSingleton(const MeyersSingleton&);
};

int main()
{
  std::cout << "Singleton GoF Kata" << std::endl;
  MeyersSingleton::getInstance().DoSomething();
}

