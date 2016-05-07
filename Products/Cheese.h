//
// Created by yifat biezuner on 07/05/2016.
//

#ifndef POLIMORPHISM_CHEESE_H
#define POLIMORPHISM_CHEESE_H


#include "Milk.h"

class Cheese: public Milk{
private:
    int m_tops;
public:
    Cheese(const int id, vector<std::string> params);
    virtual ~Cheese(){};
    void setTops(const int tops);
    virtual double calcPrice(const int adsFactor);
    virtual void write(ostream& out) const;

};


#endif //POLIMORPHISM_CHEESE_H
