#ifndef ANT_H
#define ANT_H



class Ant
{
    public:
        Ant();
        virtual ~Ant();

        void move();


    protected:
        int m_Health_Points;
        int m_Agression;
        int m_Vision_Range;
        void decrease_health();
        int m_x, m_y;

    private:


};

#endif // ANT_H
