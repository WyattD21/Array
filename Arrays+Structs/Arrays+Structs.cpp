#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib> // For exit()

const int NUM_RUNNERS = 5;
const int NUM_DAYS = 7;

void readData(std::string names[], int miles[][NUM_DAYS]);
void calculateStats(const std::string names[], const int miles[][NUM_DAYS], double totals[], double averages[]);
void displayResults(const std::string names[], const int miles[][NUM_DAYS], const double totals[], const double averages[]);

int main() {
    std::string names[NUM_RUNNERS];
    int miles[NUM_RUNNERS][NUM_DAYS];
    double totals[NUM_RUNNERS] = { 0 };
    double averages[NUM_RUNNERS] = { 0 };

    readData(names, miles);
    calculateStats(names, miles, totals, averages);
    displayResults(names, miles, totals, averages);

    return 0;
}

void readData(std::string names[], int miles[][NUM_DAYS]) {
    std::ifstream inputFile("runners.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file 'runners.txt'. Make sure it exists in the correct location." << std::endl;
        exit(1);
    }

    // Read data from the file
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        inputFile >> names[i];
        for (int j = 0; j < NUM_DAYS; ++j) {
            inputFile >> miles[i][j];
        }
    }

    inputFile.close();
}

void calculateStats(const std::string names[], const int miles[][NUM_DAYS], double totals[], double averages[]) {
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        for (int j = 0; j < NUM_DAYS; ++j) {
            totals[i] += miles[i][j];
        }
        averages[i] = totals[i] / NUM_DAYS;
    }
}

void displayResults(const std::string names[], const int miles[][NUM_DAYS], const double totals[], const double averages[]) {
    std::cout << std::setw(15) << std::left << "Name";
    for (int i = 0; i < NUM_DAYS; ++i) {
        std::cout << std::setw(8) << std::right << "Day " << i + 1;
    }
    std::cout << std::setw(10) << std::right << "Total";
    std::cout << std::setw(12) << std::right << "Average" << std::endl;

    std::cout << std::setw(15) << std::left << "-------------";
    for (int i = 0; i < NUM_DAYS; ++i) {
        std::cout << std::setw(8) << std::right << "--------";
    }
    std::cout << std::setw(10) << std::right << "--------";
    std::cout << std::setw(12) << std::right << "----------" << std::endl;

    for (int i = 0; i < NUM_RUNNERS; ++i) {
        std::cout << std::setw(15) << std::left << names[i];
        for (int j = 0; j < NUM_DAYS; ++j) {
            std::cout << std::setw(8) << std::right << miles[i][j];
        }
        std::cout << std::setw(10) << std::right << std::fixed << std::setprecision(2) << totals[i];
        std::cout << std::setw(12) << std::right << std::fixed << std::setprecision(2) << averages[i] << std::endl;
    }
}

