#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#endif // HISTOGRAM_H_INCLUDED

#pragma once

#include <vector>
#include <iostream>
using namespace std;

struct Input;
void findMinMax(vector<double> ar, double& min, double& max);
vector<double> getBarChart(Input *input);
bool scaleArr(double max_count, size_t bask, vector<double>& bins);
int countNumbers(int num);
Input* readInput(istream& in, bool prompt);
int inputNumber(istream& in);
vector<double> inputNumbers(istream& in, size_t count);
