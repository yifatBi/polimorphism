//
// Created by yifat biezuner on 07/05/2016.
//

#include "MilkOther.h"

MilkOther::MilkOther(const int id, vector<std::string> params) : Milk(id, params) {
    m_numOfNonMilkProducts = stoi(params.back());
    for(int i=0;i<m_numOfNonMilkProducts;i++){
        m_namesNonMilkProducts.push_back(params[INDEX_OF_FIRST_NAME+i]);
    }
}

double MilkOther::calcPrice(const int adsFactor) {
    return Milk::calcPrice(adsFactor)+(m_numOfNonMilkProducts*5);
}

void MilkOther::write(ostream &out) const {
    Milk::write(out);
    out<<" ";
    printNonMilkProfucts(out);
    out<<" "<<"("<<m_numOfNonMilkProducts<<")";
}

void MilkOther::printNonMilkProfucts(ostream &out) const {
    for (int i = 0; i < m_numOfNonMilkProducts; ++i) {
        if(i!=0)
            out<<", ";
        out<<m_namesNonMilkProducts[i];
    }
}









