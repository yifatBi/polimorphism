#ifndef POLIMORPHISM_FRUIT_H
#define POLIMORPHISM_FRUIT_H

#define FRUIT_PARAMS_NUM 10
#include "Farming.h"
/**
 * Fruit product of type Farming
 */
class Fruit: public Farming {
private:
    double m_sugarAmount;
public:
    Fruit(const int id, const vector<string> &params);

    virtual ~Fruit() { }

    virtual int farmingType() const override {
        return FRUIT_TYPE;
    }

    virtual double calcPrice(const int adsFactor)override;
    virtual void write(ostream& out) const override;
};


#endif //POLIMORPHISM_FRUIT_H
