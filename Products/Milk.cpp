//
// Created by yifat biezuner on 07/05/2016.
//

#include "Milk.h"

void Milk::setMilkType(const int type) {
    if(type!=DRINK&&type!=YOGURT&&type!=CHEESE&&type!=OTHER)
        throw "Wrong milk type";
    m_milkType=type;
}

void Milk::setColoursNum(const int colours) {
    if(colours<0)
        throw "Wrong colours num";
    m_coloursNum=colours;
}

void Milk::setFatPrecentege(const double fat) {
    if(fat<0)
        throw "wrong fat precentege";
    m_fatPrecentege=fat;
}

double Milk::calcPrice(const int adsFactor) {
    return ((Product::calcPrice(adsFactor)+m_coloursNum-m_fatPrecentege)*m_milkType);
}

void Milk::write(ostream &out) const {
    Product::write(out);
    out<<" "<<m_name<<" ("<<m_milkType<<","<<m_coloursNum<<","<<m_fatPrecentege<<")";
}

Milk::Milk(const int id, vector<std::string> params):Product(id,params) {
    m_name=(params.at(5)+" "+params.at(6));
    setMilkType(stoi(params.at(7)));
    setColoursNum(stoi(params.at(8)));
    setFatPrecentege(stoi(params.at(9)));
}













