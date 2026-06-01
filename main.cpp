#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
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
    double daily_move{};
};

int main() {
    std::string file_location;
    std::cout<<"Enter the location of CSV file : "<<std::endl;
    std::cin>>file_location;
    std::ifstream data_set(file_location);
    std::vector<Tick> ticks;
    if (data_set.is_open()) {
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
    double total_volume{};
    double typical_volume_price{};
    double vwap{};
    for (Tick& tick : ticks) {
        tick.daily_move=((abs(tick.close-tick.open))/tick.open)*100;
        total_volume+=tick.volume;
        typical_volume_price+=((tick.high+tick.low+tick.close)/3)*tick.volume;
    }
    vwap=typical_volume_price/total_volume;
    if (ticks.empty()) {
        std::cerr<<"No data loaded";
        return 1;
    }
    auto highest_volume_day = std::max_element(
        ticks.begin(),ticks.end(),
        [](const Tick& a, const Tick& b){
            return a.volume<b.volume;
        });
    auto lowest_volume_day = std::min_element(
        ticks.begin(),ticks.end(),
        [](const Tick& a, const Tick& b){
            return a.volume<b.volume;
        });
    std::sort(
        ticks.begin(),ticks.end(),
        [](const Tick& a, const Tick& b){
            return a.daily_move>b.daily_move;
        });
    std::cout<<std::fixed<<std::setprecision(2);
    std::cout << "========================================\n";
    std::cout << "      TICK DATA ANALYSIS REPORT\n";
    std::cout << "========================================\n\n";
    std::cout<<std::setw(28)<<"VWAP : "<<vwap<<std::endl;
    std::cout<<std::setw(28)<<"Biggest daily move:"<<ticks[0].date<<" "<<ticks[0].daily_move<<std::endl;
    std::cout<<std::setw(28)<<"Highest Volume day : "<<highest_volume_day->date<<"  "<<highest_volume_day->volume<<std::endl;
    std::cout<<std::setw(28)<<"Lowest Volume day: "<<lowest_volume_day->date<<"  "<<lowest_volume_day->volume<<std::endl;

    std::cout<<"The top 5 volatile days are : "<<std::endl<<std::endl;
    for (int i=0;i<5;i++) {
        std::cout<<i<<"  "<<ticks[i].date<<"  "<<ticks[i].volume<<std::endl;
    }
    return 0;
}
