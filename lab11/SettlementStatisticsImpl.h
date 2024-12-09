//
// Created by Csala on 2024. 12. 02..
//

#ifndef LAB11_SETTLEMENTSTATISTICSIMPL_H
#define LAB11_SETTLEMENTSTATISTICSIMPL_H
#include "SettlementStatistics.h"

class SettlementStatisticsImpl : public SettlementStatistics{
public:
    explicit SettlementStatisticsImpl(string &fileName);
    multimap<string, Settlement> settlements;
private:

    virtual int numSettlements() const;

    virtual int numCounties() const;

    virtual int numSettlementsByCounty(const string &county) const;

    virtual vector <Settlement> findSettlementsByCounty(
            const string &county) const;

    virtual Settlement findSettlementsByNameAndCounty(
            const string &name, const string &county) const;

    virtual Settlement maxPopulation() const ;

    virtual Settlement minPopulation() const ;

    virtual vector <Settlement> findSettlementsByName(
            const string &name) ;

};


#endif //LAB11_SETTLEMENTSTATISTICSIMPL_H
