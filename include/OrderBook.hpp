#pragma once
#include "Order.hpp"
#include <map>
#include <deque>
#include <functional>
#include <iostream>
#include <algorithm>

class OrderBook {
private:
    std::vector<std::deque<Order>> asks;
    std::vector<std::deque<Order>> bids;
    int minPriceTick;
    int bestBidPrice;
    int bestAskPrice;
public:
    OrderBook(int minPrice, int maxPrice) : 
        minPriceTick(minPrice),
        bids(maxPrice - minPrice + 1),
        asks(maxPrice - minPrice + 1),
        bestBidPrice(-1),
        bestAskPrice(maxPrice - minPrice + 1)
    {}
    void addOrder(Order &order);
    void display() const;
};