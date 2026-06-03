#include "OrderBook.hpp"

int main()
{
    Order order1(1, 1500, 5, OrderType::LIMIT,
        SideClass::SELL);
    Order order2(2, 1500, 10, OrderType::LIMIT,
        SideClass::SELL);
    Order order3(3, 1500, 15, OrderType::LIMIT,
        SideClass::SELL);
    Order order4(4, 1500, 20, OrderType::LIMIT,
        SideClass::BUY);
    OrderBook Book;
    Book.addOrder(order1);
    Book.addOrder(order2);
    Book.addOrder(order3);
    Book.addOrder(order4);
    Book.display();
    return 0;
}