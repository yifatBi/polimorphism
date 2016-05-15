//
// Created by yifat biezuner on 07/05/2016.
//
#include "Package.h"
#define INDEX_OF_FIRST_NAME 5
double Package::calcPrice(const int adsFactor) {
    return ((Product::calcPrice(adsFactor)*2)*m_numberOfProducts)+(((double)m_coloursNum)/3);
}

void Package::write(ostream &out) const {
    Product::write(out);
    out<<" ";
    printProductsNames(out);
    out<<" ("<<m_numberOfProducts<<","<<m_coloursNum<<")";
}

Package::Package(const int id,const vector<std::string> params):Product(id,params){
    if(params.size()<(MIN_PRODUCT_PARAMS+2))
        throw "invalid num of Package params";
    m_numberOfProducts=stoi(params.at(params.size()-2));
    for(int i=0;i<m_numberOfProducts;i++){
        m_productsNames.push_back(params[INDEX_OF_FIRST_NAME+i]);
    }
    setColursNum(stoi(params.back()));
}

void Package::printProductsNames(ostream &out) const{
    for (int i = 0; i < m_numberOfProducts; ++i) {
        if(i!=0)
            out<<", ";
        out<<m_productsNames[i];
    }
}

void Package::setColursNum(const int colours) {
        if(colours<0)
            throw "Wrong colours num";
        m_coloursNum=colours;
}











