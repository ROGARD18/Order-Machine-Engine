#include <iostream>
#include <string>
#include <map>

enum class OrderType {
    MARKET,
    LIMIT
};

class Order {
    private:
        int id;
        int price;
        OrderType type;
    public:
        Order(int i, int p, OrderType t) : id(i), price(p), type(t) {}
        void display() {
            std::string typeName = (type == OrderType::MARKET) ? "MARKET" : "LIMIT";
            std::cout << "The Order is: id: "<< id
            << ", price: " << price
            << ", type: " << typeName << ".\n";
        }
};

int main() {
    Order myOrder(1, 1500, OrderType::MARKET);
    myOrder.display();

    std::map<int, int> askBook;
    askBook[1500] = 1;
    askBook[1505] = 2;
    askBook[1510] = 3;
    for (const auto& order : askBook) {
        std::cout << "Prix: " << order.first
        << "-Quantite: " << order.second << ".\n";
    }
}