#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>



class PID
{
private:
    long double min;
    long double max;
    long double prev_error;
    long double integral;
    long double Kp;
    long double Ki;
    long double Kd;
    long double dt;

public:
    PID(long double, long double, long double, long double, long double, long double);

    long double calculate(long double, long double);
    void make_svg() const;

    void finish_svg(long double x, long double y) const;
    void plot(long double y, int x) const;
    
    static long double setpoint;
    static int width;
};