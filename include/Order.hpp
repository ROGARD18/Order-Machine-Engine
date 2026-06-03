#pragma once
#include <string>

enum class OrderType { MARKET, LIMIT };
enum class SideClass { BUY, SELL };

class Order {
private:
    int id;
    int price;
    int quantity;
    OrderType type;
    SideClass side;

public:
    Order(int i, int p, int q, OrderType t, SideClass s);
    void display() const;
    void reduceQuantity(int q);
    int getId() const;
    int getPrice() const;
    int getQuantity() const;
    SideClass getSide() const;
    OrderType getType() const;
};