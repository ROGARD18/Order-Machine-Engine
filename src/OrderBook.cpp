#include "OrderBook.hpp"

void OrderBook::addOrder(Order &order) {
    if (order.getType() == OrderType::MARKET)
    {
        std::cerr << "Error: MARKETS orders can not be stocked.\n";
        return;
    }
    // ask part
    while (order.getSide() == SideClass::SELL && !bids.empty()
        && order.getQuantity() > 0 && order.getPrice() <= bids.begin()->first)
    {
            Order& bestBid = bids.begin()->second.front();
            int tradeQuantity = std::min(order.getQuantity(), bestBid.getQuantity());
            order.reduceQuantity(tradeQuantity);
            bestBid.reduceQuantity(tradeQuantity);
            std::cout << "QUANTITY = " << order.getQuantity() << "\n";
            if (bestBid.getQuantity() == 0) {
                bids.begin()->second.pop_front();
            }
            if (bids.begin()->second.empty()) {
                bids.erase(bids.begin());
            }
            std::cout << "TRADE EXECUTED: [" << tradeQuantity
            << "] @ [" << order.getPrice() << "]\n";
    }
    if (order.getSide() == SideClass::SELL && order.getQuantity() > 0) {
        asks[order.getPrice()].push_back(order);
    }
    // bid part
    while (order.getSide() == SideClass::BUY && !asks.empty()
        && order.getQuantity() > 0 && order.getPrice() >= asks.begin()->first)
    {
            Order& bestAsk = asks.begin()->second.front();
            int tradeQuantity = std::min(order.getQuantity(), bestAsk.getQuantity());
            order.reduceQuantity(tradeQuantity);
            bestAsk.reduceQuantity(tradeQuantity);
            if (bestAsk.getQuantity() == 0) {
                asks.begin()->second.pop_front();
            }
            if (asks.begin()->second.empty()) {
                asks.erase(asks.begin());
            }
            std::cout << "TRADE EXECUTED: [" << tradeQuantity
            << "] @ [" << order.getPrice() << "]\n";
    }
    if (order.getSide() == SideClass::BUY && order.getQuantity() > 0) {
        bids[order.getPrice()].push_back(order);
    }
}

void OrderBook::display() const {
    std::cout << "\n-----ASKS-----\n\n";
    for (const auto &ask : asks)
    {
        std::cout << "-" << ask.first << ": \n";
        for (const auto &order : ask.second)
        {
            std::cout << "   ";
            order.display();
        }
    }
    std::cout << "\n-----BIDS-----\n\n";
    for (const auto &bid : bids)
    {
        std::cout << "-" << bid.first << ": \n";
        for (const auto &order : bid.second)
        {
            std::cout << "   ";
            order.display();
        }
    }
}