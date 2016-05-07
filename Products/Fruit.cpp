//
// Created by yifat biezuner on 07/05/2016.
//

#include "Fruit.h"

Fruit::Fruit(const int id, const vector<string> &params):Farming(id,params) {
    m_sugarAmount = stod(params.at(9));
}

double Fruit::calcPrice(const int adsFactor) {
    return Farming::calcPrice(adsFactor)+(m_sugarAmount/2);
}

void Fruit::write(ostream &out) const {
    Farming::write(out);
    out<<" ("<<m_sugarAmount<<")";
}









