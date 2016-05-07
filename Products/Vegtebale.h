//
// Created by yifat biezuner on 07/05/2016.
//

#ifndef POLIMORPHISM_VEGTEBALE_H
#define POLIMORPHISM_VEGTEBALE_H


#include "Farming.h"

class Vegtebale: public Farming {
private:
   double m_vitamins;
public:
    Vegtebale(const int id, const vector<string> &params);
    virtual double calcPrice(const int adsFactor);
    virtual void write(ostream& out) const;

};


#endif //POLIMORPHISM_VEGTEBALE_H
