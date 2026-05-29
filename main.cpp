#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
int main() {
    std::string file_location,row,date,low,high,close,Volume;
    std::cout<<"Enter the location of the .csv file : "<<std::endl;
    std::cin>>file_location;
    std::ifstream data_set(file_location);
    if (data_set.is_open()) {
        std::getline(data_set,row);
        std::stringstream ss(row);
    }
}
