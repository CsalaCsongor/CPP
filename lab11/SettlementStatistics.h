//
// Created by Csala on 2024. 12. 02..
//

#ifndef LAB11_SETTLEMENTSTATISTICS_H
#define LAB11_SETTLEMENTSTATISTICS_H
#include "Settlement.h"
#include <vector>
#include <map>

class SettlementStatistics {
    multimap<string, Settlement> settlements;

    virtual int numSettlements() const = 0;

    virtual int numCounties() const = 0;

    virtual int numSettlementsByCounty(const string &county) const = 0;

    virtual vector <Settlement> findSettlementsByCounty(
            const string &county) const = 0;

    virtual Settlement findSettlementsByNameAndCounty(
            const string &name, const string &county) const = 0;

    virtual Settlement maxPopulation() const = 0;

    virtual Settlement minPopulation() const = 0;

    virtual vector <Settlement> findSettlementsByName(
            const string &name) = 0;

};
#endif //LAB11_SETTLEMENTSTATISTICS_H
