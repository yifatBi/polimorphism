//
// Created by yifat biezuner on 07/05/2016.
//

#include "Cheese.h"

void Cheese::setTops(const int tops) {
    if(tops<0)
        throw "Invalid tops num";
    m_tops=tops;
}

Cheese::Cheese(const int id, vector<std::string> params):Milk(id,params) {
    setTops(stoi(params.at(10)));
}

double Cheese::calcPrice(const int adsFactor) {
    return Milk::calcPrice(adsFactor)+m_tops;
}

void Cheese::write(ostream &out) const {
    Milk::write(out);
    out<<" ("<<m_tops<<")";
}

void Cheese::print() const {
    Milk::print();
    cout<<" ("<<m_tops<<")";
}









