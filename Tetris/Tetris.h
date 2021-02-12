#pragma once
#include <vector>
#include <algorithm>
#include "Engine.h"

enum StatesAmount {
    one,
    two,
    four
};

class Square {
public:
    Square() { color = 0; }
    Square(Position p, unsigned short c) : p(p) { color = c; }
    Position p;
    unsigned short color;
};

class Shape : public Square {
public:
    Shape() {
        index = 0;
        statesAmount = one;
    }
    Position coords[4]; //last position is the lowest point
    int index;
    StatesAmount statesAmount;
};

class Tetris : public Engine
{
public:
    Tetris(int, int, int, int);
    bool Start();
    bool Update(float);
    bool IsColliding(Square);
    void DrawShape();
    void NewShape();
    int NextRotation(int);
    ~Tetris();
private:
    bool isSpedUp;
    float timer;
    float speed;
    float timePassed;
    std::vector<Square> squares;
    Shape currentShape;
    Position figures[19][4] = {
        //Last position must always be the lowest point of the figure (highest y)
        { Position(0, 0), Position(1, 0), Position(0, 1), Position(1, 1) }, //0 square boi

        { Position(0, 0), Position(0, 1), Position(0, 2), Position(0, 3) }, //1 long boi - vertical
        { Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2) }, //2 long boi - horizontal

        { Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2) }, //3 s boi - vertical
        { Position(1, 0), Position(2, 0), Position(0, 1), Position(1, 1) }, //4 s boi - horizontal

        { Position(1, 0), Position(1, 1), Position(0, 1), Position(0, 2) }, //5 z boi - vertical
        { Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1) }, //6 z boi - horizontal

        { Position(0, 0), Position(0, 1), Position(0, 2), Position(1, 2) }, //7 L boi - south
        { Position(0, 0), Position(1, 0), Position(2, 0), Position(0, 1) }, //8 L boi - east
        { Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2) }, //9 L boi - north
        { Position(2, 0), Position(2, 1), Position(1, 1), Position(0, 1) }, //10 L boi - west

        { Position(1, 0), Position(1, 1), Position(1, 2), Position(0, 2) }, //11 J boi - south
        { Position(0, 0), Position(1, 0), Position(2, 0), Position(2, 1) }, //12 J boi - east
        { Position(1, 0), Position(0, 0), Position(0, 1), Position(0, 2) }, //13 J boi - north
        { Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1) }, //14 J boi - west

        { Position(0, 0), Position(1, 0), Position(2, 0), Position(1, 1) }, //17 t boi - north
        { Position(1, 0), Position(1, 1), Position(0, 1), Position(1, 2) }, //16 t boi - east
        { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1) }, //15 t boi - south
        { Position(0, 0), Position(0, 1), Position(1, 1), Position(0, 2) } //18 t boi - west
    };
};

