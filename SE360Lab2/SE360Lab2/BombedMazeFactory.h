#ifndef BOMBEDMAZEFACTORY_H
#define BOMBEDMAZEFACTORY_H

#include "MazeFactory.h"

class BombedMazeFactory : public MazeFactory
{
    public:
        BombedMazeFactory();
        ~BombedMazeFactory();

        virtual std::string className() {
            return std::string("BombedMazeFactory");
        }

    protected:
    private:
};

#endif // BOMBEDMAZEFACTORY_H
