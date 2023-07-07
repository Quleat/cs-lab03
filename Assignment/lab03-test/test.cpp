#include<iostream>
#include<cassert>
#include<iostream>
#include "lab03.h"
using namespace std;
void test() {
    double min = INT_MAX;
    double max = INT_MIN;
    findMinMax({ 1, 2, 3 }, min, max);
    vector<double> bc = getBarChart({ 1,2,3,4 }, 2);
    assert(bc[0] == 2);
    assert(bc[1] == 2);

    if (scaleArr(2, 2, bc))
        assert(false);

    bc[0] = 82;
    scaleArr(82, 2, bc);
    assert(bc[0] < 82);

	assert(min == 1);
	assert(max == 3);

    int num = countNumbers(1555);
    assert(num == 4);
    num = countNumbers(1);
    assert(num == 1);

}

int main() {
	test();
	cout << " TESTING";
}