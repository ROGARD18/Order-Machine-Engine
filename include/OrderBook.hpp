#pragma once
#include "Order.hpp"
#include <map>
#include <deque>
#include <functional>
#include <iostream>
#include <algorithm>

class OrderBook {
private:
    std::map<int, std::deque<Order>> asks;
    std::map<int, std::deque<Order>, std::greater<int>> bids;

public:
    void addOrder(Order &order);
    void display() const;
};