#include <iostream>
#include <string>
#include <memory>
#include <map>

// class Order {
//     private:
//         int price;
//     public:
//         Order(int p) {
//             price = p;
//         }
//         void createOrder() {
//             std::unique_ptr<Order> ptr = std::make_unique<Order>(1500)
//         }
//         int getPrice() {
//             return price;
//         }
// };


// int main() {
//     Order myOrder(1500);
//     Order.createOrder()
//     std::cout  << "Target: " << myOrder.getPrice();
//     return 0;
// }

class Trade {
    private:
        int price;
        int quantity;
    public:
        Trade(int p, int q) {
            price = p;
            quantity = q;
        }
        void display() {
            std::cout << "Transaction: " << quantity << " titres a " << price << "cts.\n";
        }
};

int main() {
    std::unique_ptr<Trade> myTrade = std::make_unique<Trade>(210, 10);
    myTrade->display();
    std::map<int, int> askBook;
    askBook[1500] = 1;
    askBook[1505] = 2;
    askBook[1510] = 3;
    std::cout << "La quantite disponible pour le prix de 1505 est de " << askBook[1505] << ".\n";
}