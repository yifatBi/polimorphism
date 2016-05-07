#include "SuperMarket.h"
using namespace std;

int main() {
const int ADD_PRODUCT= 1;
    const int CHANGE_FACTOR =2;
    const int CALC_VALUE= 3;
    const int PRINT_SHOP= 4;
    Product p;
    try {
        int action;
        string actionString;
        SuperMarket s("SuperShop",3);
//        cin >> s;
        cout << s;
        cout<<"What you would like to do 1-for add product, 2- for change shop ads factor, 3- calc shop value, 4-print the shop"<<endl;
        cin>>action;
        while (action==ADD_PRODUCT||action==CHANGE_FACTOR||action==CALC_VALUE||action==PRINT_SHOP){
            switch (action){
                case (ADD_PRODUCT): {
//                    string id;
//                    cout << "please enter values of the product" << endl;
//                    cin>>id;
//                    getline(std::cin,actionString);
//                    s.addProduct(id,actionString);
                    //fruit
                    s.addProduct("34567"," H 5 70 1 2 Egoz 2 2 2 25");
                    //vegtebale
                    s.addProduct("34568"," S 3 70 1 2 batzal 1 2 2 25");
                    //milk regular-yogurt
                    s.addProduct("65432"," Y 2 120 3 2 Yougor shoko 2 5 15");
                    //milk regular-drink
                    s.addProduct("65432"," Y 2 120 3 2 Yougor shoko 1 5 15");
                    //Cheese
                    s.addProduct("65431"," R 3 90 3 3 ez dalshuman 3 5 20 4");
                    //other milk
                    s.addProduct("65430"," F 5 400 3 2 keves lite 4 10 50 water maim aqua 3");
                    //package
                    s.addProduct("56789"," G 2 88 2 1 karla pita tapuach gvinit 4 2");
                    break;
                }
                case (CHANGE_FACTOR): {
                    cout << "please enter the new factor" << endl;
                    cin>>actionString;
                    s.changeFactor(atoi(actionString.c_str()));
                    break;
                }
                case (CALC_VALUE):
                    cout<<"calc value"<<endl;
                    cout<<s.culcAllProductsPrice();
                    break;
                case (PRINT_SHOP):
                    cout<<"print shop"<<endl;
                    cout<<s;
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