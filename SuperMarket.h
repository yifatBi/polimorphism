#pragma once

#include "Product.h"

class SuperMarket
{
private:
	string m_name;
	int m_factor_ads;
	int m_numOfProducts;
	Product** m_products;
	bool isIdExist(const int id)const;
public:
	SuperMarket() :m_numOfProducts(0), m_products(NULL) {};
	SuperMarket(const string& name,const int factor_ads) :m_numOfProducts(0),m_name(name),m_factor_ads(factor_ads), m_products(NULL) {};
	SuperMarket(const string& name, int numOfProducts, const Product** products);
	void changeFactor(const int factor);
	double culcAllProductsPrice()const;
	void read(istream& in);
	void readProducts(istream& in);
	Product* createProduct(istream& in);
	void addProduct(const string& id,const string& values);
	void write(ostream& out) const;
	void writeProducts(ostream& out) const;
	
	~SuperMarket();
};

ostream& operator<<(ostream& out, const SuperMarket& superm);
istream& operator>>(istream& in, SuperMarket& superm);

