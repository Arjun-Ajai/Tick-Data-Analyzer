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
    double open{};
    double high{};
    double low{};
    double close{};
    double adj_close{};
    double volume{};
};

int main() {
    std::string file_location;
    std::cout<<"Enter the location of CSV file : "<<std::endl;
    std::cin>>file_location;
    std::ifstream data_set(file_location);
    if (data_set.is_open()) {
        std::vector<Tick> ticks;
        std::string row;
        std::getline(data_set,row);
        while (std::getline(data_set,row)){
            int column=0;
            std::stringstream row_stream(row);
            std::string cell;
            Tick temp_tick;
        while (std::getline(row_stream,cell,',')) {
            if (column==0) {
                temp_tick.date = cell;
            }
            else if (column==1) {
                temp_tick.open=std::stod(cell);
            }
            else if (column==2) {
                temp_tick.high=std::stod(cell);
            }
            else if (column==3) {
                temp_tick.low=std::stod(cell);
            }
            else if (column==4) {
                temp_tick.close=std::stod(cell);
            }
            else if (column==5) {
                temp_tick.adj_close=std::stod(cell);
            }
            else if (column==6) {
                temp_tick.volume=std::stod(cell);
            }
            column++;
        }
            ticks.push_back(temp_tick);
        }

    }

    else{
        std::cerr<<"Error! Could not open or find the file at "<<file_location<<std::endl;
    }

    data_set.close();
    return 0;
}
