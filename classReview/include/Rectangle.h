#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle
{
    private:
        int length;
        int breadth;
    public:
        Rectangle(int l, int b);
        int area();
        void changeLength(int l);
        virtual ~Rectangle();

    protected:


};

#endif // RECTANGLE_H
