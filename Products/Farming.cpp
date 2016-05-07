//
// Created by yifat biezuner on 07/05/2016.
//

#include "Farming.h"

double Farming::calcPrice(const int adsFactor) {
    return Product::calcPrice(adsFactor)*3*(5-m_seasonsNum)+(m_suppliersNum*5)+m_farmingType;
}

void Farming::write(ostream &out) const {
    Product::write(out);
    out<<" "<<m_name<<" ("<<m_farmingType<<","<<m_seasonsNum<<","<<m_suppliersNum<<")";
}

void Farming::setFarmingType(const int type) {
    if(type!=FRUIT_TYPE&&type!=VEG_TYPE)
        throw "Wrong Farm type";
    m_farmingType=type;
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

Farming::Farming(const int id, vector<std::string> params):Product(id,params){
    m_name=params.at(5);
    setFarmingType(stoi(params.at(6)));
    setSeasonsNum(stoi(params.at(7)));
    setSuppliersNum(stoi(params.at(8)));
}












