#include <iostream>
#include <random>
#include <string>
#include <time.h>
#include <math.h>
using namespace std;


int main(int argc, char* argv[]) {

    srand(time(NULL));
    double x = 0, y = 0, pi = 0;
    float in = 0, tot = 0;
    int points = 0;


    cout << "Estimate with how many points: ";
    cin >> points;

    // For each point generate random x and y components
    // Check if the points lie within the unit circle
    // Divide in circle points by total points and multiply by 4 to estimate pi

    for (int k = 0; k < points; k++) {
        x = (float)rand() / RAND_MAX;
        y = (float)rand() / RAND_MAX;
        if ((x * x) + (y * y) <= 1)
            in++;
        tot++;
    }

    pi = (in / tot) * 4;

    cout << endl << "Pi: " << pi << endl;

    // Just used to stop window from closing.
    cin >> x;


}