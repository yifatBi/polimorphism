#ifndef POLIMORPHISM_MILKOTHER_H
#define POLIMORPHISM_MILKOTHER_H
#define INDEX_OF_FIRST_NAME 10

#include "Milk.h"
/**
 * Other Milk product of type Milk
 */
class MilkOther: public Milk {
private:
    int m_numOfNonMilkProducts;
    vector<string> m_namesNonMilkProducts;
    void printNonMilkProfucts(ostream &out)const;
public:
    MilkOther(const int id, const vector<std::string> params);

    virtual ~MilkOther() { }

    virtual double calcPrice(const int adsFactor);
    virtual void write(ostream& out) const;
};


#endif //POLIMORPHISM_MILKOTHER_H
