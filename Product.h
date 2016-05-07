#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <sstream>
#define PACKAGE 2
#define MILK 3
#define FARMING 1

using namespace std;


class Product
{
	int m_id;
	char m_line;
	int m_shelf;
	double m_amount;
	double m_cost;
	int m_productType;
	int m_area;

public:
	Product() {};
	Product(const int id, vector<std::string> params);
	~Product();
	const int getId()const{return m_id;}

	virtual void read(istream& in);
	virtual void write(ostream& out) const;
	virtual void print()const;
	void setShelf(const int shelf);
	void setLine(const char line);
	void setAmount(const double amount);
	void setProductType(const int productType);
	void setArea(const int area);
	virtual double calcPrice(const int adsFactor);
};
ostream& operator<<(ostream& out, const Product& product);

