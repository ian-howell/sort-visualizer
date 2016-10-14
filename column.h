#ifndef COLUMN_H
#define COLUMN_H
#include "helpers.h"

class Column
{
    private:
        int height;
        Color color;

    public:
        Column() : height(0), color(WHITE) {}
        Column(int h, Color c) : height(h), color(c) {}

        void setHeight(int h) { this->height = h; }
        void setColor(Color c) { this->color = c; }

        /* draw
         *
         * draws the column to the screen
         *
         * Param x {int}: the horizontal location to start drawing from
         * Param y {int}: the vertical location to start drawing from
         * Param color {int}: The color pair to draw the column with
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
