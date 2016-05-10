/**
 * Basic functionality of shop product
 * This is abstract can't be created itself
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

using namespace std;


class Product
{
	int m_id;
	char m_line;
	int m_shelf;
	double m_amount;
	double m_cost;
	int m_area;

public:
	Product() {};
	Product(const int id, vector<std::string> params);
	virtual ~Product();
	virtual int productType() const = 0;
	const int getId()const{return m_id;}

	virtual void write(ostream& out) const;
	virtual void print()const;
	void setShelf(const int shelf);
	void setLine(const char line);
	void setAmount(const double amount);
	void setArea(const int area);
	virtual double calcPrice(const int adsFactor);
};
ostream& operator<<(ostream& out, const Product& product);

