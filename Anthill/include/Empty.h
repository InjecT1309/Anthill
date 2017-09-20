#ifndef EMPTY_H
#define EMPTY_H

#include <string>

#include "Point2D.h"
#include "Fill.h"

using std::string;

class Empty : public Point2D
{
    public:
        Empty();
        Empty(int x, int y);
        virtual ~Empty();

        void set_scent_to_max();
        void lower_scent();
        int get_scent_level();

    protected:

    private:
        int m_scent_level;
};

#endif // EMPTY_H
