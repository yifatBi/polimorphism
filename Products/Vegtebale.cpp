#include "Vegtebale.h"

Vegtebale::Vegtebale(const int id, const vector<string> &params):Farming(id,params) {
    if(params.size()<VEG_PARAMS_NUM)
        throw "invalid num of Vegtebale params";
    m_vitamins = stod(params.at(9));
}

double Vegtebale::calcPrice(const int adsFactor) {
    return Farming::calcPrice(adsFactor)+(m_vitamins*2);
}

void Vegtebale::write(ostream &out) const {
    Farming::write(out);
    out<<" ("<<m_vitamins<<")";
}








