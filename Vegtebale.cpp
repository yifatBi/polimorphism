//
// Created by yifat biezuner on 07/05/2016.
//

#include "Vegtebale.h"

Vegtebale::Vegtebale(const int id, const vector<string> &params):Farming(id,params) {
    m_vitamins = stod(params.at(9));
}

double Vegtebale::calcPrice(const int adsFactor) {
    return Farming::calcPrice(adsFactor)+(m_vitamins*2);
}

void Vegtebale::write(ostream &out) const {
    Farming::write(out);
    out<<" ("<<m_vitamins<<")";
}

void Vegtebale::print() const {
    Farming::print();
    cout<<" ("<<m_vitamins<<")";
}







