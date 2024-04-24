#include "pid.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

long double PID::setpoint = 26.19231;
int PID::width = 10000;

std::ofstream file("plot.svg");

PID::PID(long double min, long double max, long double Kp, long double Ki, long double Kd, long double dt) : dt(dt), max(max), min(min), Kp(Kp), Ki(Ki), Kd(Kd), integral(0), prev_error(0){}

long double PID::calculate(long double setpoint, long double current_state)
{
    long double error = setpoint - current_state; // Error számítás

    long double Op = Kp * error; // Proportional súlyozása

    integral += error * dt; // Integral rész számítása későbbre

    long double Oi = Ki * integral; // Integral rész súlyozása

    long double Od = Kd * (error - prev_error) / dt; // Derivative rész számolása és súlyozása

    long double output = Od + Oi + Op; // Output a három tagból

    // outout max és min között?
    if (output < min)
        output = min;
    if (output > max)
        output = max;

    prev_error = error;

    long int output_int = (long int)std::round(output);

    return output;
}

void PID::make_svg() const
{
    if (file.is_open())
    {
        file << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"" << width << "\" height=\"300\">\n\n";
        file << "<line x1=\"40\" y1=\"0\" x2=\"" << width << "\" y2=\"0\" style=\"stroke:black;stroke-width:2\" />\n";
        file << "<line x1=\"40\" y1=\"0\" x2=\"40\" y2=\"100\" style=\"stroke:black;stroke-width:2\" />\n\n";
        file << "<line x1=\"40\" y1=\"" << std::setprecision(10) << setpoint << "\" x2=\"" << width << "\" y2=\"" << std::setprecision(10) << setpoint << "\" style=\"stroke:black;stroke-width:0.5\" />\n\n";
    }
    else
        throw(-1);
}

    void PID::finish_svg(long double x, long double y) const
{
    file << "<text x=\"5\" y=\"30\" font-size=\"5\" fill=\"white\">" << x << "</text>\n";
    file << "<text x=\"5\" y=\"60\" font-size=\"5\" fill=\"white\">" << std::setprecision(10) << y << "</text>\n";
    file << "<text x=\"5\" y=\"90\" font-size=\"5\" fill=\"white\">" << std::setprecision(10) << setpoint << "</text>\n";
    file << "\n</svg>";
    file.close();
}


    void PID::plot(long double y, int x) const
{
    file << "<circle cx=\"" << ((double)x) / 32 + 40 << "\" cy=\"" << y << "\" r=\"0.25\" fill=\"red\" />\n";
}