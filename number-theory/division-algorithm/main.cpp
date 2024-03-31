/*
Visualization of the division algorithm from Number Theory in a C++ program.

Nikolas Achatz 1/14/2021

*/

#include <iostream>
#include <string>
#include <bits/stdc++.h> 

using namespace std;



// Division algorithm takes a and b. This states that b | a (b divides a).
// To do this we need to fist check if a is greater than b, if it isn't the remainder is simply
// a and q is 0. Otherwise we want to loop until the remainder is less than b because the algorithm
// states 0 <= r < b and we need to maintain this statement. From here we just take the remainder to be
// r - b and we add to the quotient. Once r > b we are complete.
// a = q * b + r, Division Algorithm, Computational Number Theory
void divisionalgo(int a, int b){

    int q;
    int r;

    if (b == 0) {
        cout << "You cannot divide by 0" << endl;
        return;
    }

    if(a >= b)
    {
        q = 0;
        r = a;

        while(r >= b)
        {
            r = r - b;
            q++;

        }
    }else{
        q = 0;
        r = a;


    }


    cout << "a = quotient*b + remainder" << endl;
    cout << a << " = " << b << " * " << q << " + " << r << endl;


}

int main(){
    int a, b;
    time_t s, e;

    cout << "Enter a" << endl;
    cin >> a;
    cout << "Enter b" << endl;
    cin >> b;

    s = clock();
    divisionalgo(a,b);
    e = clock();

    double time = double(e - s) / double(CLOCKS_PER_SEC);

    cout << "Time for division algo: " << fixed << time << setprecision(5);

    cout << endl;



    return 0;
}