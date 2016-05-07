//
// Created by yifat biezuner on 07/05/2016.
//
#include "Package.h"

double Package::calcPrice(const int adsFactor) {
    return Product::calcPrice(adsFactor);
}

void Package::write(ostream &out) const {
    Product::write(out);
}

void Package::print() const {
    Product::print();
}

Package::Package(const int id, vector<std::string> params):Product(id,params){
    m_numberOfProducts=stoi(params.at(params.size()-2));
}

void Package::setProductsNames() {
//    (begin(array), end(array));
}









