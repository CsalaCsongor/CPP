//
// Created by Csala on 2024. 12. 02..
//
#include <string>
#include <ostream>

#ifndef LAB10_SETTLEMENT_H
#define LAB10_SETTLEMENT_H

using namespace std;
class Settlement {
    string name = "";
    string county = "";
    int population = 0;
// constructor, getters, setters, inserter operator
public:
    Settlement(const string &name, const string &county, int population);

    const string &getName() const;
    const string &getCounty() const;
    int getPopulation() const;

    void setName(const string &name);
    void setCounty(const string &county);
    void setPopulation(int population);

    friend ostream &operator<<(ostream &os, const Settlement &settlement);

    bool operator<(const Settlement& other) const {
        return name < other.name;
    }
};



#endif //LAB10_SETTLEMENT_H
