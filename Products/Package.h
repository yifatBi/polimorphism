#ifndef POLIMORPHISM_PACKAGE_H
#define POLIMORPHISM_PACKAGE_H


#include "Product.h"
/**
 * Package product
 */
class Package: public Product{
private:
    int m_numberOfProducts;
    vector<string> m_productsNames;
    int m_coloursNum;
    void printProductsNames(ostream &out)const;

public:
    virtual int productType() const override {
        return PACKAGE;
    }


public:
    Package(const int id,const vector<std::string> params);

    virtual ~Package() { }

    void setColursNum(const int colours);
    virtual double calcPrice(const int adsFactor) override ;
    virtual void write(ostream& out) const override;

};


#endif //POLIMORPHISM_PACKAGE_H
