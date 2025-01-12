#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <iomanip>
#include "GPS_0404_s2024.h"
using namespace std;

int main(int argc, char *argv[]) {
    // Check if we have enough arguments for two points (program name + 4 coordinates).
    if (argc < 5) 
    {
        std::cout << "Usage: " << argv[0] << " <latA> <lonA> <latB> <lonB>\n" << std::endl;
        return 1;
    }

    // Parse latitude and longatude for point A and B from command line arguments.
    double x1 = std::atof(argv[1]);
    double x2 = std::atof(argv[2]);
    double y1 = std::atof(argv[3]);
    double y2 = std::atof(argv[4]);

    // Initialize GPS_DD objects for points A and B.
    GPS_DD x(x1, x2);
    GPS_DD y(y1, y2);

    // Calculate and print the distance between point A and B.
    double distance = x.distance(y);

    cout << "{\"distance\": " << fixed << setprecision(6) << distance << "}" << endl;

    // use cout for distance

    return 0;
}