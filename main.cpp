/**
 * Yifat Biezuner 15/05/2016
 * This program generate shop with products in polymorphism methology
 * and supermarket functinality of add products calacValue changeFactor ads or print shop
 */
#include "SuperMarket.h"
using namespace std;

int main() {
const int ADD_PRODUCT= 1;
    const int CHANGE_FACTOR =2;
    const int CALC_VALUE= 3;
    const int PRINT_SHOP= 4;
    try {
        int action;
        string actionString;
        char generate;
        SuperMarket superMarket("SuperShop",3);
        cout << superMarket;
        cout<<"Would you like to generate shop products?(Y/N)"<<endl;
        cin>>generate;
        if(generate=='y'||generate=='Y')
        {
            //fruit
            superMarket.addProduct("34567 H 5 70 1 2 Egoz 2 2 2 25");
            //vegtebale
            superMarket.addProduct("34568 S 3 70 1 2 batzal 1 2 2 25");
            //milk regular-yogurt
            superMarket.addProduct("65432 Y 2 120 3 2 Yougor shoko 2 5 15");
            //milk regular-drink
            superMarket.addProduct("65433 Y 2 120 3 2 Yougor shoko 1 5 15");
            //Cheese
            superMarket.addProduct("65431"," R 3 90 3 3 ez dalshuman 3 5 20 4");
            //other milk
            superMarket.addProduct("65430"," F 5 400 3 2 keves lite 4 10 50 water maim aqua 3");
            //package
            superMarket.addProduct("56789"," G 2 88 2 1 karla pita tapuach gvinit 4 2");
        }

        cout<<"What you would like to do 1-for add product, 2- for change shop ads factor, 3- calc shop value, 4-print the shop"<<endl;
        cin>>action;
        while (action==ADD_PRODUCT||action==CHANGE_FACTOR||action==CALC_VALUE||action==PRINT_SHOP){
            switch (action){
                case (ADD_PRODUCT): {
                    string id;
                    cout << "please enter values of the product" << endl;
                    cin>>id;
                    getline(std::cin,actionString);
                    superMarket.addProduct(id,actionString);
                    break;
                }
                case (CHANGE_FACTOR): {
                    cout << "please enter the new factor" << endl;
                    cin>>actionString;
                    superMarket.changeFactor(atoi(actionString.c_str()));
                    break;
                }
                case (CALC_VALUE):
                    cout<<"calc value"<<endl;
                    cout<<superMarket.culcAllProductsPrice()<<endl;
                    break;
                case (PRINT_SHOP):
                    cout<<"print shop"<<endl;
                    cout<<superMarket;
                    break;
                default:
                    break;
            }
            cout<<"What you would like to do 1-for add product, 2- for change shop ads factor, 3- calc shop value, 4-print the shop"<<endl;
            cin>>action;
        }
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
    catch (...) {
        cout << "general exception occured" << endl;
    }
    return 0;
}