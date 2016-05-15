
#include "Cheese.h"
void Cheese::setTops(const int tops) {
    if(tops<0)
        throw "Invalid tops num";
    m_tops=tops;
}

Cheese::Cheese(const int id,const vector<std::string> params):Milk(id,params) {
    if(params.size()<CHEESE_PARAMS_NUM)
        throw "invalid num of Cheese params";
    setTops(stoi(params.at(10)));
}

double Cheese::calcPrice(const int adsFactor) {
    return Milk::calcPrice(adsFactor)+m_tops;
}

void Cheese::write(ostream &out) const {
    Milk::write(out);
    out<<" ("<<m_tops<<")";
}










