#include"lab03.h"

using namespace std;

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
vector<double> getBarChart(vector<double> arr, int bask) {
    vector<double> bins(bask);

    double min = 0;
    double max = 0;
    findMinMax(arr, min, max);

    double interval = (max - min) / (double)bask;
    for (int j = 0; j < bask; j++) {
        double left = min + (interval * j);
        double right = left + interval;
        if (j == bask - 1)
            right = round(right);
        for (int i = 0; i < arr.size(); i++) {
            if ((arr[i] >= left) && (arr[i] <= right)) {
                bins[j]++;
            }
        }
    }
    return bins;
}
bool scaleArr(int max_count, int bask, vector<double>& bins) {
    if (max_count > 80) {
        double dividor = (double)max_count / 80;
        for (int i = 0; i < bask; i++) {
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