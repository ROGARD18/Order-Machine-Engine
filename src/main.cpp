#include "OrderBook.hpp"
#include "Order.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>

struct DotSeparator : std::numpunct<char> {
    char do_thousands_sep() const override { return '.'; }
    std::string do_grouping() const override { return "\3"; }
};

int main()
{
    OrderBook Book;
    int orders_number = 10000000;

    std::vector<Order> orders;
    orders.reserve(orders_number);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> priceDist(1400, 1600);
    std::uniform_int_distribution<> qtyDist(1, 100);
    std::uniform_int_distribution<> sideDist(0, 1);

    std::cout << "Generation of " << orders_number
    << " orders in memory...\n";

    for (int i = 0; i < orders_number; i++) {
        SideClass side = (sideDist(gen) == 0) ? SideClass::BUY : SideClass::SELL;
        Order order(i + 1, priceDist(gen), qtyDist(gen), OrderType::LIMIT, side);
        orders.push_back(order);
    }

    std::cout << "Start ...\n";
    auto start = std::chrono::high_resolution_clock::now();
    for (auto& order : orders) {
        Book.addOrder(order);
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = end - start;
    double seconds = diff.count();
    double ops = orders_number / seconds;

    std::cout.imbue(std::locale(std::cout.getloc(), new DotSeparator));
    std::cout << "\n---- RESULTS OF BENCHMARK ----\n";
    std::cout << "Processed orders : " << orders_number << "\n";
    std::cout << "Total time       : " << seconds << " seconds\n";
    std::cout << "Performance      : " << static_cast<int>(ops)
    << " orders/seconds\n";

    // Book.display();
    return 0;
}