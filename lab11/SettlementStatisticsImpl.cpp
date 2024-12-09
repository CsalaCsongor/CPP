//
// Created by Csala on 2024. 12. 02..
//

#include "SettlementStatisticsImpl.h"
#include <fstream>
#include <sstream>
#include <iostream>


SettlementStatisticsImpl::SettlementStatisticsImpl(string &fileName) {
    ifstream in(fileName);
    if (!in) {
        throw runtime_error("Nem található a file: " + fileName);
    }

    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string name, county;
        int population;

        if (ss >> name >> county >> population) {
            settlements.emplace(county, Settlement(name, county, population));
        }
        cout << name << " " << county << " " << population << endl;
    }
}

int SettlementStatisticsImpl::numSettlements() const {
    return this->settlements.size();
}

int SettlementStatisticsImpl::numCounties() const {
    int uniqueKeysCount = 0;
    for(auto it = settlements.begin(); it != settlements.end(); it = settlements.upper_bound(it->first))
    {
        uniqueKeysCount++;
    }
    return uniqueKeysCount;
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {

    /*for (const auto& p : settlements) {
        string kulcs = p.first;
        unsigned long long count = settlements.count(kulcs);

        cout << "A '" << kulcs << "' kulcshoz " << count << " érték tartozik." << endl;
    }
    */
    return 0;

}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    vector<Settlement> foundSettlements;
    for (auto it : settlements) {
        if(it.first == county){
            foundSettlements.emplace_back(it.second);
        }
    }
    return foundSettlements;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {

    for (auto it = settlements.lower_bound(county); it != settlements.upper_bound(county); it++) {
        if(it->first == county && it->second.getName() == name){
            return it->second;
        }
    }
   return Settlement("null", "null", 0);
}



