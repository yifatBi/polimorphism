
#ifndef POLIMORPHISM_FARMING_H
#define POLIMORPHISM_FARMING_H
#include "Product.h"
#define FRUIT_TYPE 2
#define VEG_TYPE 1
#define MIN_SEASON 1
#define MAX_SEASON 2
#define FARMING_PARAMS 9
/**
 * Abstract class of farming product
 */
class Farming: public Product {
private:
    string m_name;
    int m_seasonsNum;
    int m_suppliersNum;
public:
    virtual int productType() const override {
        return FARMING;
    }

    virtual ~Farming() { }

    Farming(const int id,const vector<std::string> params);
    virtual int farmingType() const = 0;
    void setSeasonsNum(const int seasons);
    void setSuppliersNum(const int suppliers);
    virtual double calcPrice(const int adsFactor) override ;
    virtual void write(ostream& out) const override ;

};


#endif //POLIMORPHISM_FARMING_H
