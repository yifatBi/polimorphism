#ifndef POLIMORPHISM_CHEESE_H
#define POLIMORPHISM_CHEESE_H


#include "Milk.h"
#define CHEESE_PARAMS_NUM 11
/**
 * Cheese product of type milk
 */
class Cheese: public Milk{
private:
    int m_tops;
public:
    Cheese(const int id,const vector<std::string> params);
    virtual ~Cheese(){};
    void setTops(const int tops);
    virtual double calcPrice(const int adsFactor);
    virtual void write(ostream& out) const;

};


#endif //POLIMORPHISM_CHEESE_H
