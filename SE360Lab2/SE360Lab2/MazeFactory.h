#ifndef MAZEFACTORY_H
#define MAZEFACTORY_H

#include <string>

class MazeFactory
{
    public:
        static MazeFactory* Instance();  // singleton access method

        virtual std::string className() {
            return std::string("MazeFactory");
        }

    protected:
        MazeFactory();

    private:
        static MazeFactory* _instance;

		// Implement a wrapper getenv()
		static char* getEnv(const char* envVar);
};


#endif // MAZEFACTORY_H