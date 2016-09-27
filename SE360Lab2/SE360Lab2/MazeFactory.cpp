#include <cstring>
#include <cstdlib>  // getenv
#include <iostream>
#include "BombedMazeFactory.h"
#include "EnchantedMazeFactory.h"

// Global singleton instance
MazeFactory* MazeFactory::_instance = 0;
static char __libvar[1024] = {0};

MazeFactory::MazeFactory()
{
    std::cout << "MazeFactory::MazeFactory()" << std::endl;
}

MazeFactory* MazeFactory::Instance() // called in main
{
    if (_instance == 0) {
		std::cout << "Singleton MazeFactory _instance has not been created yet.  Creating now..." << std::endl; // displayed if there is no instance

		const char* displayStyle = getEnv("MAZE_STYLE"); // enviroment set in debug -> properties -> enviroment MAZE_STYLE=enchanted

        if (strcmp(displayStyle, "bombed") == 0)   // string found
            _instance = new BombedMazeFactory; // creates the instance in bombed maze factory 
        else if (strcmp(displayStyle, "enchanted") == 0)
            _instance = new EnchantedMazeFactory; // creates the instance in enchanted maze factory
        // other subtypes
    }
    return _instance; // instance returned to main
}

char* MazeFactory::getEnv(const char* envVar) // method called in line 21
{
   size_t requiredSize = sizeof(__libvar); // sets required size to libvar

   getenv_s( &requiredSize, __libvar, requiredSize, envVar); //set enviroment under debug -> properties -> enviroment MAZE_STYLE=enchanted
   if (requiredSize == 0) //if enviroment is set correctly this if statement should be bybassed if you are entering this if statement see comment above
   {
      std::cout << envVar << " doesn't exist!" << std::endl;
	  std::cin.get(); // used to pause console for viewing
      exit(1);
   }

   return __libvar; // returns _libvar/enviroment name to line 21
}