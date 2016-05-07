
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



SuperMarket::SuperMarket(const string & name,int numOfProducts, const Product ** products):
	m_name(name),m_numOfProducts(numOfProducts)
{
	m_products = new Product*[m_numOfProducts];
	if (m_products == NULL)
		throw "m_products allocation failed";
	for (int i = 0;i < m_numOfProducts;i++) {
//		if (typeid(*products[i]) == typeid(Food)) {
//			Food* temp = new Food;
//			if (temp == NULL)
//				throw "food allocation failed";
//			temp->setName(products[i]->getName());
//			temp->setCost(products[i]->getCost());
//			temp->setCalories(((Food*)products[i])->getCalories());
//		}
//		else if (typeid(*products[i]) == typeid(Medicine)) {
//			Medicine* temp = new Medicine;
//			if (temp == NULL)
//				throw "Medicine allocation failed";
//			temp->setName(products[i]->getName());
//			temp->setCost(products[i]->getCost());
//			temp->setPres(((Medicine*)products[i])->getPres());
//		}
	}
}

void SuperMarket::read(istream & in)
{
	cout << "Supermarket name : " << endl;
	in >> m_name;
	cout << "Ads Factor : " << endl;
	in >> m_factor_ads;
	readProducts(in);
}

void SuperMarket::readProducts(istream & in)
{
	cout << "Number of products " << endl;
	in >> m_numOfProducts;
	m_products = new Product*[m_numOfProducts];
	if (m_products == NULL)
		throw "error allocating products";
	for (int i = 0; i < m_numOfProducts; i++) {
		Product* newProduct = createProduct(in);

		cout << "Enter products data" << endl;
		newProduct->read(in);
		m_products[i] = newProduct;
	}

}

Product* SuperMarket::createProduct(istream & in)
{
	char choice;
	cout << "Please enter F for food and M for medicine " << endl;
	in >> choice;

//	switch (choice) {
//	case 'F':
//	case 'f':
//		return new Food;
//		break;
//	case 'M':
//	case 'm':
//		return new Medicine;
//		break;
//	default :
//		return NULL;
//	}
}

void SuperMarket::write(ostream & out) const
{
	out << "------------------" << endl;
	out << m_name <<" "<< m_numOfProducts<<" "<< m_factor_ads<<endl;
	writeProducts(out);
}

void SuperMarket::writeProducts(ostream & out) const
{
//	out << "There are " << m_numOfProducts << " products : " << endl;
	for (int i = 0; i < m_numOfProducts;i++)
		m_products[i]->write(out);
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


istream& operator>>(istream& in, SuperMarket& superm) {
	superm.read(in);
	return in;
}

void SuperMarket::changeFactor(const int factor) {
	m_factor_ads = factor;
}

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
	//split params of product and generate product type
	vector<std::string> productVals = split(values, ' ');
	//remove the first empty element
	productVals.erase(productVals.begin()+0);
	//get product type
	string productType= productVals.at(PRODUCT_TYPE_INDEX);
	string productInnerType =productVals.at(FARMER_INNER_TYPE_INDEX);
	if(productType==to_string(PACKAGE))productInnerType="";
	else if(productType==to_string(MILK))productInnerType=productVals.at(MILK_INNER_TYPE_INDEX);
	cout<< productType+productInnerType<<endl;
	string product = productType+productInnerType;
	Product* newProduct;
	switch (atoi(product.c_str())){
		case(PACKAGE):
			newProduct = new Package(stoi(id),productVals);
			cout<<"this is package"<<endl;
			break;
		case (FRUIT):
			newProduct = new Fruit(stoi(id),productVals);
			cout<<"This is Fruit"<<endl;
			break;
		case(VEGTEBALE):
			newProduct = new Vegtebale(stoi(id),productVals);
			cout<<"This is Vegtebale"<<endl;
			break;
		case(OTHER_MILK):
			newProduct = new MilkOther(stoi(id),productVals);
			cout<<"Other Milk"<<endl;
			break;
		case(DRINK_MILK):
			newProduct = new Milk(stoi(id),productVals);
			cout<< "DRINK milk"<<endl;
			break;
		case(YOGURT_MILK):
			newProduct = new Milk(stoi(id),productVals);
			cout<< "YOGURT milk"<<endl;
			break;
		case(CHEESE_MILK):
			newProduct = new Cheese(stoi(id),productVals);
			cout<<"This is cheese"<<endl;
			break;
		default:
			newProduct = new Product(stoi(id),productVals);
			break;
	}
	newProduct->print();
//			cout<<*newProduct<<endl;
			cout<<endl<<"price : "<< newProduct->calcPrice(m_factor_ads)<<endl;

}

double SuperMarket::culcAllProductsPrice() const {
	return 0;
}

bool SuperMarket::isIdExist(const int id) const {
	for (int i = 0; i < m_numOfProducts; ++i) {
		if(m_products[i]!=NULL&&(*m_products[i]).getId()==id){
			return true;
		}
	}
	return false;
}






