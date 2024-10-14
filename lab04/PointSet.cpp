#include "PointSet.h"
#include "Point.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <random>

#define M 100


PointSet::PointSet(int n) {
    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, M); // return a number in the given range

   points.reserve(n);
    bool megVan[M][M] ={0};
    while(points.size() < n)
   {
       int x = dist(mt);
       int y = dist(mt);
if(!megVan[x][y]){
    points.push_back(Point(x, y));
    megVan[x][y] = true;
                }
   }
computeDistances();
}

void PointSet::printPoints() const {
    for(Point p: this->points)
    {
        cout<<"{" <<p.getX() << ","  <<p.getY() << "}"<<endl;
    }
}

void PointSet::computeDistances() {
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i+1; j < points.size(); ++j) {
          distances.push_back(points[i].distanceTo(points[j]));
        }
    }
}

double PointSet::maxDistance() const {
    auto pos = max_element(distances.begin(), distances.end());
    if(pos == distances.end()){
        return NAN;
    }
    return *pos;
}

int PointSet::numDistinctDistances() {
    vector<double> distances = this->distances;
    sort(distances.begin(), distances.end());
    auto it = unique(distances.begin(), distances.end());
    return it - distances.begin();
}

double PointSet::minDistance() const {
    auto pos = min_element(distances.begin(), distances.end());
    if(pos == distances.end()){
        return NAN;
    }
    return *pos;
}

void PointSet::printDistances() const {
    for(double d: this->distances)
    {
        cout<< d <<" , ";
    }
}

int PointSet::numDistances() const {
    return distances.size();
}


