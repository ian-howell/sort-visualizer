#ifndef COLUMN_H
#define COLUMN_H

class Column
{
    private:
        int height;

    public:
        Column() : height(0) {}
        Column(int h) : height(h) {}

        void setHeight(int h) { this->height = h; }

        /* draw
         *
         * draws the column to the screen
         *
         * Param x {int}: the horizontal location to start drawing from
         * Param y {int}: the vertical location to start drawing from
         * Param color {int}: The color pair to draw the column with
         */
        void draw(int x, int y, int color);

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
