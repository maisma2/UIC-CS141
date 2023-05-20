#include <iostream>
using namespace std;

/*  This is an example of a  program that prints out NSAMPLES number of
pseudo-random numbers. We use the modulo operator to restrict the range
of those random numbers  between the integers  [0, RNG_RANGE) note that
RNG_RANGE  is not included.  An important  component to  generating the
random numbers is the seed value.

The seed value allows you to set the initial state of the random number
generator,  which means you will  get the same  "random" numbers every-
time.  You can set the seed value with the srand function, try changing
the argument to different numbers.*/

const int RNG_RANGE = 100;
const int NSAMPLES = 10;

int
main()
{
    srand(2);
    for (int sample = 1; sample <= NSAMPLES; sample++) {
        int rnum = rand() % RNG_RANGE;
        cout << rnum << ' ';
    }
    cout << endl;
    return 0;
}
