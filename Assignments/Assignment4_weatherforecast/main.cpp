/* 
Assignment 4: Weather Forecast

This assignment works with template functions and lambdas to become the best weather forecaster
at the Stanford Daily. Be sure to read the assignment details in the PDF.

Submit to Paperless by 11:59pm on 2/16/2024.
*/

// TODO: import anything from the STL that might be useful!
#include <iostream>
#include <vector>


// TODO: write convert_f_to_c function here. Remember it must be a template function that always returns
// a double.
// [function definition here]

template<typename Function>
std::vector<double> get_forecast(std::vector<std::vector<int>> readings, Function fn) {
    // TODO: write get_forecast here!

}

int main() {
    std::vector<std::vector<int>> readings = {
        {70, 75, 80, 85, 90},
        {60, 65, 70, 75, 80},
        {50, 55, 60, 65, 70},
        {40, 45, 50, 55, 60},
        {30, 35, 40, 45, 50},
        {50, 55, 61, 65, 70},
        {40, 45, 50, 55, 60}
    };

    // TODO: Convert temperatures to Celsius and output to output.txt

    // TODO: Find the maximum temperature for each day and output to output.txt

    // TODO: Find the minimum temperature for each day and output to output.txt

    // TODO: Find the average temperature for each day and output to output.txt

    return 0;
}