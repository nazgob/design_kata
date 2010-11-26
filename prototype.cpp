#include <iostream>

// Specify the kinds of objects to create using a prototypical instance, and
// create new objects by copying this prototype.

class MapSite
{
  public:
    virtual MapSite* Clone() = 0;
};

class Maze : public MapSite
{
  public:
    virtual Maze* Clone()
    {
      std::cout << "Cloning Maze!" << std::endl;
      return new Maze(*this);
    }
};

class Room: public MapSite
{
  public:
    virtual Room* Clone()
    {
      std::cout << "Cloning Room!" << std::endl;
      return new Room(*this);
    }
};

class Wall: public MapSite
{
  public:
    virtual Wall* Clone()
    {
      std::cout << "Cloning Wall!" << std::endl;
      return new Wall(*this);
    }
};

class MazePrototypeFactory
{
  public:
    MazePrototypeFactory(Maze* m, Wall* w, Room* r) :
      mProtoMaze(m),
      mProtoRoom(r),
      mProtoWall(w)
  {
  }
    ~MazePrototypeFactory()
    {
      delete mProtoMaze; mProtoMaze = NULL;
      delete mProtoRoom; mProtoRoom = NULL;
      delete mProtoWall; mProtoWall = NULL;
    }

    virtual MapSite* MakeMaze() const
    {
      return mProtoMaze->Clone();
    }

    virtual MapSite* MakeRoom() const
    {
      return mProtoRoom->Clone();
    }

    virtual MapSite* MakeWall() const
    {
      return mProtoWall->Clone();
    }

  private:
    Maze* mProtoMaze;
    Room* mProtoRoom;
    Wall* mProtoWall;
};

class MazeGame
{
  public:
    void CreateMaze(MazePrototypeFactory* mazeFactory)
    {
      std::cout << "Constructing maze!" << std::endl;
      MapSite* m = mazeFactory->MakeMaze();
      MapSite* r = mazeFactory->MakeRoom();
      MapSite* w = mazeFactory->MakeWall();
      // in a real life situation we would collect created objects and compose
      // real maze out of them

      delete m; m = NULL;
      delete r; r = NULL;
      delete w; w = NULL;
    }
};


class BombedRoom : public Room 
{
  public:
    virtual BombedRoom* Clone()
    {
      std::cout << "Cloning BombedRoom!" << std::endl;
      return new BombedRoom(*this);
    }
};

int main()
{
  std::cout << "Prototype GoF Kata" << std::endl;
  std::cout << "--------------" << std::endl;

  // easy game
  MazePrototypeFactory* simpleMazeFactory = new MazePrototypeFactory(new Maze, new Wall, new Room);
  MazeGame simpleMazeGame;
  simpleMazeGame.CreateMaze(simpleMazeFactory);
  delete simpleMazeFactory; simpleMazeFactory = NULL;

  std::cout << "--------------" << std::endl;

  // hard game
  MazePrototypeFactory* trapMazeFactory = new MazePrototypeFactory(new Maze, new Wall, new BombedRoom);
  MazeGame hardMazeGame;
  hardMazeGame.CreateMaze(trapMazeFactory);
  delete trapMazeFactory; trapMazeFactory = NULL;

  return 0;
}

