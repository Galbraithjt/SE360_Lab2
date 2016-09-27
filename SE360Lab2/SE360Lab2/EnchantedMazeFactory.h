#ifndef ENCHANTEDMAZEFACTORY_H
#define ENCHANTEDMAZEFACTORY_H

#include "MazeFactory.h"

class EnchantedMazeFactory : public MazeFactory
{
    public:
        EnchantedMazeFactory();
        ~EnchantedMazeFactory();

        virtual std::string className() {
            return std::string("EnchantedMazeFactory");
        }

    protected:
    private:
};

#endif // ENCHANTEDMAZEFACTORY_H
