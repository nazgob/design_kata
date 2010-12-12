#include <iostream>
#include <vector>

// Convert the interface of the class into another interface clients expect.
// Adapter lets classes work together that couldn't otherwise because of
// incompatibile interfaces.

// notes:
// there are two types of adapters:
// 1. class adapter (using multiple inheritence)
// 2. object adapter (using object composition)
// I favor composition over inheritence so below you can see object adapter

class Square // simple data carrier
{
  public:

    Square(size_t x, size_t y, size_t len) :
      x_(x), y_(y), len_(len) {}

    size_t x_;
    size_t y_;
    size_t len_;
};

class SceneManager // simple data collector
{
  public:
    void AddSquare(Square sq)
    {
      squares_vec.push_back(sq);
    }

  protected:
    std::vector<Square> squares_vec;
};

class Renderer // renders stuff to stdio using x, y and len
{
  public:
    void RenderSquare(size_t x, size_t y, size_t len)
    {
      std::cout << "Rendering square:" << " x = " << x
        << " y = " << y
        << " len = " << len
        << std::endl;
    }
};

// adapting SceneManager to use Renderer interface
class RendererAdapter : public SceneManager
{
  public:
    void RenderAllSquares()
    {
      for(std::vector<Square>::const_iterator it = squares_vec.begin();
          it != squares_vec.end();
          ++it)
      {
        bnsr.RenderSquare(it->x_, it->y_, it->len_);
      }
    }
  protected:
    Renderer bnsr;
};

int main()
{
  std::cout << "Adapter GoF Kata" << std::endl;

  Square foo(0, 0, 10);
  Square bar(2, 2, 7);
  Square baz(4, 4, 20);

  RendererAdapter adapter;

  adapter.AddSquare(foo);
  adapter.AddSquare(bar);
  adapter.AddSquare(baz);

  adapter.RenderAllSquares();
}

