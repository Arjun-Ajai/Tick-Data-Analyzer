#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
int main() {
    std::string file_location;
    std::cout<<"Enter the location of the CSV file : "<<std::endl;
    std::cin>>file_location;
    std::ifstream data_set(file_location);
    if (data_set.is_open()) {
        std::string row;
        while (std::getline(data_set,row))
            std::cout<<row<<std::endl;
        }
    else {
        std::cerr<<"Error! Could not open or find the file at "<<file_location<<std::endl;
    }

    data_set.close();
    return 0;
    }

