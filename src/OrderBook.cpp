#include "OrderBook.hpp"

void OrderBook::addOrder(Order &order) {
    if (order.getType() == OrderType::MARKET)
    {
        std::cerr << "Error: MARKETS orders can not be stocked.\n";
        return;
    }

    int priceIndex = order.getPrice() - minPriceTick;

    // ask part
    while (order.getSide() == SideClass::SELL && bestBidPrice > -1
        && order.getQuantity() > 0 && priceIndex <= bestBidPrice)
    {
            Order& bestBid = bids[bestBidPrice].front();
            int tradeQuantity = std::min(order.getQuantity(), bestBid.getQuantity());
            order.reduceQuantity(tradeQuantity);
            bestBid.reduceQuantity(tradeQuantity);
            if (bestBid.getQuantity() == 0) {
                bid[bestBidPrice].pop_front();
            }
            if (bids[bestBidPrice].empty()) {
                while (bestBidPrice >= 0 && bids[bestBidPrice].empty()) {
                    bestBidPrice--;
                }
            }
    }
    if (order.getSide() == SideClass::SELL && order.getQuantity() > 0) {
        asks[priceIndex].push_back(order);
    }
    // bid part
    while (order.getSide() == SideClass::BUY && bestAskPrice < 
        && order.getQuantity() > 0 && priceIndex >= asks[bestAskPrice - minPriceTalk]->first)
    {
            Order& bestAsk = asks[bestAskPrice]->second.front();
            int tradeQuantity = std::min(order.getQuantity(), bestAsk.getQuantity());
            order.reduceQuantity(tradeQuantity);
            bestAsk.reduceQuantity(tradeQuantity);
            if (bestAsk.getQuantity() == 0) {
                asks[bestAskPrice - minPriceTalk]->second.pop_front();
            }
            if (asks[bestAskPrice - minPriceTalk]->second.empty()) {
                asks.erase(asks[bestAskPrice - minPriceTalk]);
            }
    }
    if (order.getSide() == SideClass::BUY && order.getQuantity() > 0) {
        bids[priceIndex].push_back(order);
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