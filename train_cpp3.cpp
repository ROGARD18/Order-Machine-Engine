#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <functional>

enum class OrderType {
    MARKET,
    LIMIT
};

class Order {
    private:
        int id;
        int price;
        int quantity;
        OrderType type;
    public:

        Order(int i, int p, int q, OrderType t) : id(i), price(p), quantity(q), type(t) {}

        void display() const {
            std::string typeName = (type == OrderType::MARKET) ? "MARKET" : "LIMIT";
            std::cout << "The Order is: id: "<< id
            << ", price: " << price
            << ", quantity: " << quantity
            << ", type: "<< typeName << ".\n";
        }

        int getID() const {
            return id;
        }

        int getPrice() const {
            return price;
        }

        int getQuantity() const {
            return quantity;
        }

        OrderType getType() const {
            return type;
        }
};

class OrderBook {
    private:
        std::map<int, std::vector<Order>> asks;
        std::map<int, std::vector<Order>, std::greater<int>> bids;
    public:

        void addAsk (const Order& order) {
            if (order.getType() == OrderType::MARKET) {
                std::cerr << "Error: MARKETS orders can not be stocked.\n";
                return;
            }
            asks[order.getPrice()].push_back(order);
        }

        void addBid(const Order& order) {
            if (order.getType() == OrderType::MARKET) {
                std::cerr << "Error: MARKETS orders can not be stocked.\n";
                return;
            }
            bids[order.getPrice()].push_back(order);
        }

        void display() const {
            std::cout << "\n-----ASKS-----\n\n";
            for (const auto& ask : asks) {
                std::cout << "-" << ask.first << ": \n";
                for (const auto& order : ask.second) {
                    std::cout << "   ";
                    order.display();
                }
            }
            std::cout << "\n-----BIDS-----\n\n";
            for (const auto& bid : bids) {
                std::cout << "-" << bid.first << ": \n";
                for (const auto& order : bid.second) {
                    std::cout << "   ";
                    order.display();
                }
            }
        }
};  

int main() {
    Order Order1(1, 1500, 20, OrderType::LIMIT);
    Order Order2(2, 1500, 10, OrderType::LIMIT);
    Order Order3(3, 1500, 15, OrderType::LIMIT);
    Order Order4(4, 1520, 5, OrderType::LIMIT);
    Order Order5(5, 1480, 10, OrderType::LIMIT);
    Order Order6(6, 1480, 15, OrderType::LIMIT);
    Order Order7(7, 1245, 8, OrderType::MARKET);
    OrderBook OrderBook1;
    
    OrderBook1.addAsk(Order1);
    OrderBook1.addAsk(Order3);
    OrderBook1.addAsk(Order4);
    OrderBook1.addAsk(Order6);
    OrderBook1.addBid(Order2);
    OrderBook1.addBid(Order5);
    OrderBook1.addBid(Order7);
    OrderBook1.display();
}