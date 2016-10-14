#ifndef COLUMN_H
#define COLUMN_H

class Column
{
    private:
        int height;

    public:
        Column(int h) : height(h) {}

        /* draw
         *
         * draws the column to the screen
         *
         * Param x {int}: the horizontal location to start drawing from
         * Param y {int}: the vertical location to start drawing from
         */
        void draw(int x, int y);

        /* Operator overload: <
         *
         * returns a boolean value depending on the height of the two
         * columns to be compared
         *
         * Param c1, c2 {Column, Column}: the two columns to be compared
         */
        friend bool operator < (const Column& c1, const Column& c2);

        /* Operator overload: >
         *
         * returns a boolean value depending on the height of the two
         * columns to be compared
         *
         * Param c1, c2 {Column, Column}: the two columns to be compared
         */
        friend bool operator > (const Column& c1, const Column& c2);
};

#endif
