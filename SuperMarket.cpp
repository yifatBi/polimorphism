
#include "SuperMarket.h"

#define FRUIT 12
#define VEGTEBALE 11
#define DRINK_MILK 31
#define YOGURT_MILK 32
#define CHEESE_MILK 33
#define OTHER_MILK 34
#define PRODUCT_TYPE_INDEX 3
#define FARMER_INNER_TYPE_INDEX 6
#define MILK_INNER_TYPE_INDEX 7


void SuperMarket::write(ostream & out) const
{
	out << "------------------" << endl;
	out << m_name <<" "<< m_numOfProducts<<" "<< m_factor_ads<<endl;
	writeProducts(out);
}

void SuperMarket::writeProducts(ostream & out) const
{
	for (int i = 0; i < m_numOfProducts;i++) {
		m_products[i]->write(out);
		out<<endl;
	}

}

SuperMarket::~SuperMarket()
{
	if (m_numOfProducts > 0) {
		for (int i = 0; i < m_numOfProducts; ++i)
			delete m_products[i];
		delete[] m_products;
	}

}

ostream& operator<<(ostream& out, const SuperMarket& superm) {
	superm.write(out);
	return out;
}

void SuperMarket::changeFactor(const int factor) {
	m_factor_ads = factor;
}
/**
 * split vector elements by space
 */
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}
vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}
void SuperMarket::addProduct(const string& id,const string &values) {
	if (isIdExist(atoi(id.c_str())))
		throw "this id already exist";
	//split params of product
	vector<std::string> productVals = split(values, ' ');
	if(productVals.size()<MIN_PRODUCT_PARAMS)
		throw "invalid product params";
	//remove the first empty element
	if(!productVals.at(0).length())
		productVals.erase(productVals.begin()+0);
	//add product
	addProductToTheShop(id, productVals);
}

double SuperMarket::culcAllProductsPrice() const {
	double shopPrice = 0;
	for (int i = 0; i < m_numOfProducts; ++i) {
		shopPrice+=m_products[i]->calcPrice(m_factor_ads);
	}
	return shopPrice;
}

bool SuperMarket::isIdExist(const int id) const {
	for (int i = 0; i < m_numOfProducts; ++i) {
		if(m_products[i]!=NULL&&(*m_products[i]).getId()==id){
			return true;
		}
	}
	return false;
}

void SuperMarket::addProduct(const string &values) {
	//split params of product
	vector<std::string> productVals = split(values, ' ');
	string id=productVals[0];
	//check if the id exist
	if (isIdExist(stoi(id)))
		throw "this id already exist";
	//check if valid number of params
	if(productVals.size()<MIN_PRODUCT_PARAMS)
		throw "invalid product params";
	//remove the first empty element
	productVals.erase(productVals.begin()+0);
	addProductToTheShop(id, productVals);
}

Product *SuperMarket::createProduct(const string& id,const vector<string>& productVals) {
	string productType= productVals.at(PRODUCT_TYPE_INDEX);
	string productInnerType =productVals.at(FARMER_INNER_TYPE_INDEX);
	if(productType==to_string(PACKAGE))productInnerType="";
	else if(productType==to_string(MILK))productInnerType=productVals.at(MILK_INNER_TYPE_INDEX);
	string product = productType+productInnerType;
	Product* newProduct;
	switch (atoi(product.c_str())){
		case(PACKAGE):
			newProduct = new Package(stoi(id),productVals);
			break;
		case (FRUIT):
			newProduct = new Fruit(stoi(id),productVals);
			break;
		case(VEGTEBALE):
			newProduct = new Vegtebale(stoi(id),productVals);
			break;
		case(OTHER_MILK):
			newProduct = new MilkOther(stoi(id),productVals);
			break;
		case(DRINK_MILK):
			newProduct = new Milk(stoi(id),productVals);
			break;
		case(YOGURT_MILK):
			newProduct = new Milk(stoi(id),productVals);
			break;
		case(CHEESE_MILK):
			newProduct = new Cheese(stoi(id),productVals);
			break;
		default:
			throw "invalid product type";
	}
	return newProduct;
}

void SuperMarket::addProductToTheShop(const string &id, const vector<string> &values) {
	Product** tempProductsArray = new Product*[m_numOfProducts + 1];
	if(m_numOfProducts)
		copy(m_products, m_products + m_numOfProducts, tempProductsArray);
	tempProductsArray[m_numOfProducts]=createProduct(id,values);
	if(m_products!=NULL)
		delete[] m_products;
	m_products=tempProductsArray;
	m_numOfProducts++;
}












