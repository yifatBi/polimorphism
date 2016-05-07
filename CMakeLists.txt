cmake_minimum_required(VERSION 3.3)
project(polimorphism)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Food.cpp Food.h Medicine.cpp Medicine.h SuperMarket.cpp SuperMarket.h Product.cpp Product.h FARMING.cpp FARMING.h Farming.cpp Farming.h Fruit.cpp Fruit.h Vegtebale.cpp Vegtebale.h Milk.cpp Milk.h Cheese.cpp Cheese.h Package.cpp Package.h)
add_executable(polimorphism ${SOURCE_FILES})