//
// Created by yifat biezuner on 07/05/2016.
//

#ifndef POLIMORPHISM_MILK_H
#define POLIMORPHISM_MILK_H
#define DRINK 1
#define YOGURT 2
#define CHEESE 3
#define OTHER 4


#include "Product.h"

class Milk: public Product {
private:
   int m_milkType;
    string m_name;
    int m_coloursNum;
    double m_fatPrecentege;
public:
    Milk(const int id, vector<std::string> params);
    void setMilkType(const int type);
    void setColoursNum(const int colours);
    void setFatPrecentege(const double fat);
    virtual double calcPrice(const int adsFactor);
    virtual void write(ostream& out) const;
    virtual void print()const;
};


#endif //POLIMORPHISM_MILK_H
