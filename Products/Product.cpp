#include "Product.h"
#define SHELF_START 1
#define SHELF_END 5
#define LINE_START "A"
#define LINE_END "Z"


Product::~Product()
{
}

void Product::write(ostream & out) const
{
	out<< m_id << " "<< m_line<< " "<<m_shelf<<" ("<<m_amount<<","<<productType()<<","<<m_area<<")";
}

void Product::setShelf(const int shelf) {
	if(shelf<SHELF_START||shelf>SHELF_END)
		throw "Wrong shelf location";
	m_shelf = shelf;

}

void Product::setLine(const char line) {
	if(line<LINE_START[0]||line>LINE_END[0])
		throw "Wrong line number";
	m_line = line;
}

void Product::setAmount(const double amount) {
	if(amount<0)
		throw "Wrong amount";
	m_amount=amount;
}


void Product::setArea(const int area) {
	m_area = area;
}

double Product::calcPrice(const int adsFactor) {
	return m_area*m_amount*adsFactor;
}

Product::Product(const int id,const vector<std::string> params):m_id(id) {
	if(params.size()<MIN_PRODUCT_PARAMS)
		throw "invalid num of product params";
	setLine(params.at(0)[0]);
	setShelf(stoi(params.at(1)));
	setAmount(stod(params.at(2)));
	setArea(stoi(params.at(4)));
}

void Product::print() const {
	write(cout);
}


ostream& operator<<(ostream& out, const Product& product) {
	product.write(out);
	return out;
}

















