cmake_minimum_required(VERSION 3.3)
project(polimorphism)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Food.cpp Food.h Medicine.cpp Medicine.h SuperMarket.cpp SuperMarket.h Products/Product.cpp Products/Product.h Products/Farming.cpp Products/Farming.h Products/Farming.cpp Products/Farming.h Products/Fruit.cpp Products/Fruit.h Products/Vegtebale.cpp Products/Vegtebale.h Products/Milk.cpp Products/Milk.h Products/Cheese.cpp Products/Cheese.h Products/Package.cpp Products/Package.h Products/MilkOther.cpp Products/MilkOther.h)
add_executable(polimorphism ${SOURCE_FILES})