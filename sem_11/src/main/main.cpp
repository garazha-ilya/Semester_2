#include <iostream>
#include "sem11.hpp"

using namespace std;

int main()
{
    cout << "All length metrix are in metres, destiny is kg/m^3, colour is given by one letter!" << endl;
    Line a(2);
    Material red_copper('r', 8890);
    Wire red_copper_wire_length_2(a, red_copper);
    PlaneShape b(4, 5);
    Material cement('g', 1600);
    Slate slate_cement_4_5(b, cement);
    VolumetricFigure c(1, 2, 3);
    Material clay('g', 1800);
    Brick brick_clay_1_2_3(c, clay);
    red_copper_wire_length_2.print_info();
    slate_cement_4_5.print_info();
    brick_clay_1_2_3.print_info();
    return 0;
}