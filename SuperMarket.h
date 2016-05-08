#pragma once

#include "Products/Product.h"
#include "Products/Vegtebale.h"
#include "Products/Fruit.h"
#include "Products/Cheese.h"
#include "Products/Package.h"
#include "Products/MilkOther.h"

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
	void changeFactor(const int factor);
	/**
	 * Calc the shop value according all products
	 */
	double culcAllProductsPrice()const;
	/**
	 * create product with the correct type
	 */
	Product* createProduct(const string& id,const vector<string>& productVals);
	/**
	 * add product from console, id and values
	 */
	void addProduct(const string& id,const string& values);
	/**
	 * add product to the shop products list
	 */
	void addProductToTheShop(const string &id, const vector<string> &values);
	/**
	 * add product with string of params list seperated by space
	 */
	void addProduct(const string& values);
	/*
	 * out shop
	 */
	void write(ostream& out) const;
	/**
	 * out shop products
	 */
	void writeProducts(ostream& out) const;
	
	~SuperMarket();
};

ostream& operator<<(ostream& out, const SuperMarket& superm);
istream& operator>>(istream& in, SuperMarket& superm);

