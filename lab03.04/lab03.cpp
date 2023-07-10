#include"lab03.h"
#include<iostream>
#include<cmath>

using namespace std;

struct Input {
    vector<double> numbers;
    size_t bask  = 0;
};

void findMinMax(vector<double> ar, double& min, double& max) {
    min = ar[0];
    max = ar[0];
    for (double x : ar) {
        if (x < min) {
            min = x;
        }
        else if (x > max) {
            max = x;
        }
    }
}
vector<double> getBarChart(Input *input) {
    vector<double> bins(input->bask);

    double min = 0;
    double max = 0;
    findMinMax(input->numbers, min, max);

    double interval = (max - min) / (double)input->bask;
    for (size_t j = 0; j < input->bask; j++) {
        double left = min + (interval * j);
        double right = left + interval;
        if (j == input->bask - 1)
            right = round(right);
        for (size_t i = 0; i < input->numbers.size(); i++) {
            if ((input->numbers[i] >= left) && (input->numbers[i] <= right)) {
                bins[j]++;
            }
        }
    }
    return bins;
}
bool scaleArr(double max_count, size_t bask, vector<double>& bins) {
    if (max_count > 80) {
        double dividor = max_count / 80;
        for (size_t i = 0; i < bask; i++) {
            bins[i] /= dividor;
        }
        return true;
    }
    else
        return false;
}

int countNumbers(int num) {
    int count = 1;
    while (num /= 10)
        count++;
    return count;
}

vector<double> inputNumbers(istream& in, size_t count) {
    vector<double> vd(count);
    for (int i = 0; i < count; i++) {
        in >> vd[i];
    }
    return vd;
}
int inputNumber(istream& in) {
    int dummy = 0;
    in >> dummy;
    return dummy;
}

Input* readInput(istream& in, bool prompt) {
    if(prompt){
        cerr << "Input numbers count: ";
    }
    size_t count;
    in >> count;
    if(prompt){
        cerr << "Enter numbers: ";
    }
    Input *data = new Input;
    data->numbers = inputNumbers(in, count);
    if(prompt)
        cerr << "Enter amount of baskets: ";
    data->bask = inputNumber(in);
    return data;
}
