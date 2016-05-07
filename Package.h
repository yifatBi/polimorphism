//
// Created by yifat biezuner on 07/05/2016.
//

#ifndef POLIMORPHISM_PACKAGE_H
#define POLIMORPHISM_PACKAGE_H


#include "Product.h"

class Package: public Product{
private:
    int m_numberOfProducts;
    vector<string> m_productsNames;
    int m_coloursNum;
public:
    Package(const int id, vector<std::string> params);
    void setProductsNames();
    virtual double calcPrice(const int adsFactor);
    virtual void write(ostream& out) const;
    virtual void print()const;


};


#endif //POLIMORPHISM_PACKAGE_H
