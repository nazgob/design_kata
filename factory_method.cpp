#include <iostream>

// Define an interface for creating an object, but let subclasses decide which
// class to instantiate. Factory Method lets a class defer intantiation to
// subclasses.

class Product
{
  public:
    virtual void Use() const = 0;
};

class ConcreteProduct : public Product 
{
  public:
    virtual void Use() const
    {
      std::cout << "Using Concrete Product is really awesome!" << std::endl;
    }
};

class Application
{
  public:
    virtual Product* createProduct() const = 0;
};

class ConcreteApplication : public Application
{
  public:
    virtual Product* createProduct() const
    {
      return new ConcreteProduct();
    }
}; 

int main()
{
  std::cout << "Factory Method GoF Kata" << std::endl;

  // we're programming to interfaces here; we know nothing about
  // ConcreteProduct!
  Application* application = new ConcreteApplication();
  Product* product = application->createProduct();
  product->Use();

  delete application;
  delete product;

  return 0;
}

