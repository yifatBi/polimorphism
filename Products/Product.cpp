#include "Product.h"
#define SHELF_START 1
#define SHELF_END 5
#define LINE_START "A"
#define LINE_END "Z"


Product::~Product()
{
}

void Product::read(istream & in)
{
	cout << "Please enter cost : " << endl;
	in >> m_cost;
}

void Product::write(ostream & out) const
{
//	out << typeid(*this).name() + 1<< endl;
//	out << "Name : " << m_name << endl;
//	out << "Price : " << m_cost << endl;
	out<< m_id << " "<< m_line<< " "<<m_shelf<<" ("<<m_amount<<","<<m_productType<<","<<m_area<<")";
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

void Product::setProductType(const int productType) {
	if(productType!=FARMING&&productType!=MILK&&productType!=PACKAGE)
		throw "Wrong product type";
	m_productType = productType;
}

void Product::setArea(const int area) {
	m_area = area;
}

double Product::calcPrice(const int adsFactor) {
	return m_area*m_amount*adsFactor;
}

Product::Product(const int id, vector<std::string> params):m_id(id) {
	setLine(params.at(0)[0]);
	setShelf(stoi(params.at(1)));
	setAmount(stod(params.at(2)));
	setProductType(stoi(params.at(3)));
	setArea(stoi(params.at(4)));
}

void Product::print() const {
	write(cout);
}


ostream& operator<<(ostream& out, const Product& product) {
	product.write(out);
	return out;
}

















