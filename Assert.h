#include<math.h>
using namespace std;

void assertEqual(double a, double b, double tolerance = 0.00001)
{
    if(! abs(a - b) < tolerance)
    {
        cout << "difference between " << a << " and " << b << ": " << abs(a - b) << endl;
    }
    assert(abs(a - b) < tolerance);
}