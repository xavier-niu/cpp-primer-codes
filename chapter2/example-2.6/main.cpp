#include <iostream>
#include <string>
#include "Sales_data.h"

int main() {

    Sales_data data1, data2;

    double price = 0;
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;

    std::cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    // add data1 and data2 together if transactions are for the same ISBN (aka bookNo)
    if (data1.bookNo == data2.bookNo) {
        unsigned int totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
        if (totalCnt != 0) 
            std::cout << totalRevenue / totalCnt;
        else
            std::cout << "(no sales)";
        std::cout << std::endl;
        return 0;
    } else {
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1;
    }

    return 0;
}