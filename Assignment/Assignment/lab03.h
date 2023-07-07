#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#endif // HISTOGRAM_H_INCLUDED

#pragma once

#include <vector>
using namespace std;

void findMinMax(vector<double> ar, double& min, double& max);
vector<double> getBarChart(vector<double> arr, int bask);
bool scaleArr(int max_count, int bask, vector<double>& bins);
int countNumbers(int num);