#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include "lab03.h"
#include <curl\curl.h>

using namespace std;

const auto IMAGE_WIDTH = 800;
auto IMAGE_HEIGHT = 800;
const auto TEXT_BASELINE = 20;
const auto TEXT_WIDTH = 50;
const auto BIN_HEIGHT = 20;
const auto BLOCK_WIDTH = 30;
const auto BLOCK_LEFT = 10;
const auto BLOCK_BASELINE = 25;
const auto TEXT_DIST = 15;
const auto TEXT_LEFT = BLOCK_WIDTH / 3;
const auto TEXT_SIZE = 1;

vector<string> colors = { "green", "red", "blue", "grey", "black"};

void showBarChartText(vector<double> bins);
void svgBegin(int width, int height);
void svgEnd();
void showBarChartSvg(vector<double> arr);

int main() {
    curl_global_init(CURL_GLOBAL_ALL);
    setlocale(LC_ALL, "Russian");
    const auto input = readInput(cin, true);
    const auto bins = getBarChart(input);
    showBarChartSvg(bins);

    return 0;
}

void svgBegin(int width, int height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svgEnd() {
    cout << "</svg>\n";
}

void svgText(double x, double y, string text) {
    cout << "<text x = '" << x << "' y = '" << y << "' font-size='" << TEXT_SIZE * 10 << "px'>"
        << text <<
        "</text>\n";
}

void svgRect(double x = 0, double y=0, double width=BLOCK_WIDTH, double height=BLOCK_WIDTH, string stroke="black", string fill="black") {
    cout << "<rect x ='" << x <<
        "' y = '" << y <<
        "' width = '" << width <<
        "' height = '" << height <<
        "' stroke = '" << stroke <<
        "' fill = '" << fill <<
        "' />\n";
}

vector<double> getArr(int count) {
    vector<double> vd(count);
    for (int i = 0; i < count; i++) {
        cin >> vd[i];
    }
    return vd;
}

void showBarChartText(vector<double> bins) {
    size_t bask = bins.size();
    double max_count = *max_element(bins.begin(), bins.end());
    if (scaleArr(max_count, bask, bins))
        max_count = 80;
    for (int i = 0; i < bask * max_count; i++) {
        if ((i % bask == 0) && (i != 0)) {
            cout << "\n";
        }
        if (round(bins[i % bask]) > (i / bask))
            cout << "*";
        else
            cout << " ";
    }
}

void showBarChartSvg(vector<double> bins) {
    vector<double> counts = bins;
    double max_count = *max_element(bins.begin(), bins.end());
    scaleArr(max_count, bins.size(), bins);
    IMAGE_HEIGHT = BIN_HEIGHT * (int)round(max_count);
    svgBegin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    for (size_t i = 0; i < bins.size(); i++) {
        const double bin_height = BIN_HEIGHT * bins[i];
        int count = countNumbers((int)trunc(counts[i]));
        svgText((TEXT_LEFT + BLOCK_WIDTH * i) - (i - 1) * TEXT_SIZE, TEXT_BASELINE, to_string(((int)counts[i])));
        svgRect(BLOCK_WIDTH * i, BLOCK_BASELINE, BLOCK_WIDTH, bin_height, colors[i], colors[i]);
        top += BIN_HEIGHT;
    }
    svgEnd();
}