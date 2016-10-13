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
};

#endif
