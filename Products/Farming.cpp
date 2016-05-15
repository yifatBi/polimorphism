#include "Farming.h"

double Farming::calcPrice(const int adsFactor) {
    return Product::calcPrice(adsFactor)*3*(5-m_seasonsNum)+(m_suppliersNum*5)+farmingType();
}

void Farming::write(ostream &out) const {
    Product::write(out);
    out<<" "<<m_name<<" ("<<farmingType()<<","<<m_seasonsNum<<","<<m_suppliersNum<<")";
}


void Farming::setSeasonsNum(const int seasons) {
    if(seasons<MIN_SEASON||seasons>MAX_SEASON)
        throw "Wrong season num";
    m_seasonsNum = seasons;
}

void Farming::setSuppliersNum(const int suppliers) {
    if(suppliers<=0)
        throw "invalid suppliers num";
    m_suppliersNum = suppliers;

}

Farming::Farming(const int id,const vector<std::string> params):Product(id,params){
    if(params.size()<FARMING_PARAMS)
        throw "invalid num of Farming params";
    m_name=params.at(5);
    setSeasonsNum(stoi(params.at(7)));
    setSuppliersNum(stoi(params.at(8)));
}













