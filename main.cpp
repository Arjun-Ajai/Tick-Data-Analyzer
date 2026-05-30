#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

struct Tick {
    std::string date;
    double open;
    double high;
    double low;
    double close;
    double volume;
};

int main() {
    std::string file_location;
    std::cout<<"Enter the location of the CSV file : "<<std::endl;
    std::cin>>file_location;
    std::ifstream data_set(file_location);

    if (data_set.is_open()) {
        std::string row;
        std::getline(data_set,row);
        int i=0;
        while (std::getline(data_set,row))
        std::stringstream row_stream(row);
    }

    else{
        std::cerr<<"Error! Could not open or find the file at "<<file_location<<std::endl;
    }

    data_set.close();
    return 0;
    }

