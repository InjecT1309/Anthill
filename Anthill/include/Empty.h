#ifndef EMPTY_H
#define EMPTY_H

#include <string>

#include "Point2D.h"
#include "Fill.h"

using std::string;

class Empty : public Point2D
{
    public:
        Empty(int x, int y);
        Empty(int x, int y, int scent_level);
        virtual ~Empty();

        void setScentToMax();
        void lowerScent();
        int getScentLevel();

    protected:

    private:
        int m_scent_level;
};

#endif // EMPTY_H
