#include <iostream>

// Provide an interface for creating famiilies of related
// or dependend objects witout specifying their concrete classes.

class Button
{
  public:
    virtual void Draw() const = 0;
};

class MacButton : public Button
{
  public:
    virtual void Draw() const
    {
      std::cout << "Drawing pretty Mac button!" << std::endl;
    }
};

class WinButton : public Button
{
  public:
    virtual void Draw() const
    {
      std::cout << "Drawing ugly Win button..." << std::endl;
    }
};


class GUIFactory
{
  public:
    virtual Button* getButton() const = 0;
};

class MacGUIFactory: public GUIFactory
{
  public:
    virtual Button* getButton() const
    {
      return new MacButton();
    }
};

class WinGUIFactory : public GUIFactory
{
  public:
    virtual Button* getButton() const
    {
      return new WinButton(); 
    }
};


int main()
{
  std::cout << "Abstact Factory GoF Kata" << std::endl;

  GUIFactory* guiFactory = NULL;
  Button* button = NULL;

  // Mac stuff
  guiFactory = new MacGUIFactory(); // notice that this in the only diff between Mac and Win code!
  button = guiFactory->getButton();
  button->Draw();

  // we all love c++
  delete guiFactory; guiFactory = NULL;
  delete button; button = NULL;

  // Win stuff
  guiFactory = new WinGUIFactory(); // notice that this in the only diff between Mac and Win code!
  button = guiFactory->getButton();
  button->Draw();

  // we all love c++
  delete guiFactory; guiFactory = NULL;
  delete button; button = NULL;

  return 0;
}

