/**
 * Basic functionality of shop product
 * This is abstract can't be created itself
 * save product basic params
 */
#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <sstream>
#define PACKAGE 2
#define MILK 3
#define FARMING 1
#define MIN_PRODUCT_PARAMS 5

using namespace std;


class Product
{
	int m_id;
	char m_line;
	int m_shelf;
	double m_amount;
	int m_area;

public:
	Product() {};
	Product(const int id,const vector<std::string> params);
	virtual ~Product();
	virtual int productType() const = 0;
	const int getId()const{return m_id;}

	virtual void write(ostream& out) const;
	virtual void print()const;
	void setShelf(const int shelf);
	void setLine(const char line);
	void setAmount(const double amount);
	void setArea(const int area);
	//calc price of product according the algorithm
	virtual double calcPrice(const int adsFactor);
};
ostream& operator<<(ostream& out, const Product& product);

