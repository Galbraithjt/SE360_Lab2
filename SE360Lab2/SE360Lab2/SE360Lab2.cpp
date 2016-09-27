// SE360Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MazeFactory.h"
#include "BombedMazeFactory.h"


int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "Demonstrating the singleton pattern." << std::endl;

    // access the singleton
	// MazeFactory* maze1 = new MazeFactory();  // This one fails at compile time
	MazeFactory* maze1 = new BombedMazeFactory(); // creates new bombed factory

    MazeFactory* maze = MazeFactory::Instance();

    std::cout << "The instantiated factory is: " << maze->className() << std::endl; // displays current factory instance
	std::cout << "Press enter/return key to close" << std::endl;
	std::cin.get(); //used to pause console for viewing
	return 0;
}

