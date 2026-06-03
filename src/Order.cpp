#include "Order.hpp"
#include <iostream>

Order::Order(int i, int p, int q, OrderType t,
    SideClass s) : id(i), price(p), quantity(q), type(t), side(s) {}

void Order::display() const {
    std::string typeName = (type == OrderType::MARKET) ? "MARKET" : "LIMIT";
    std::string sideName = (side == SideClass::BUY) ? "BUY" : "SELL";
    std::cout << "The Order is: id: " << id << ", price: " << price << ", quantity: " << quantity << ", type: " << typeName << ", side: " << sideName << ".\n";
}

void Order::reduceQuantity(int q) {
    quantity -= q;
}

int Order::getId() const { return id; }
int Order::getPrice() const { return price; }
int Order::getQuantity() const { return quantity; }
SideClass Order::getSide() const { return side; }
OrderType Order::getType() const { return type; }