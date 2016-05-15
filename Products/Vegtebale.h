//
// Created by yifat biezuner on 07/05/2016.
//

#ifndef POLIMORPHISM_VEGTEBALE_H
#define POLIMORPHISM_VEGTEBALE_H


#include "Farming.h"
#define VEG_PARAMS_NUM 10
/**
 * Vegtebale product of type Farming
 */
class Vegtebale: public Farming {
private:
   double m_vitamins;
public:

    virtual int farmingType() const override {
        return VEG_TYPE;
    }

    virtual ~Vegtebale() { }

    Vegtebale(const int id, const vector<string> &params);
    virtual double calcPrice(const int adsFactor)override;
    virtual void write(ostream& out) const override;

};


#endif //POLIMORPHISM_VEGTEBALE_H
