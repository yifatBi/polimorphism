//
// Created by yifat biezuner on 07/05/2016.
//

#ifndef POLIMORPHISM_FARMING_H
#define POLIMORPHISM_FARMING_H
#include "Product.h"
#define FRUIT_TYPE 2
#define VEG_TYPE 1
#define MIN_SEASON 1
#define MAX_SEASON 2

class Farming: public Product {
private:
    int m_farmingType;
    string m_name;
    int m_seasonsNum;
    int m_suppliersNum;
public:
    virtual void ProductAbs() const override {

    }

    virtual ~Farming() { }

    Farming(const int id, vector<std::string> params);
    virtual void FarmAbs() const = 0;
    void setFarmingType(const int type);
    void setSeasonsNum(const int seasons);
    void setSuppliersNum(const int suppliers);
    virtual double calcPrice(const int adsFactor) override ;
    virtual void write(ostream& out) const override ;

};


#endif //POLIMORPHISM_FARMING_H
