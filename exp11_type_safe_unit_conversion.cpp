#include <iostream>
using namespace std;
struct Meter {static constexpr double factor=1.0;};
struct Kilometer {static constexpr double factor=1000.0;};
struct Centimeter {static constexpr double factor=0.01;};
template<typename Unit> class Quantity {
    double value;
public: constexpr explicit Quantity(double v):value(v){} constexpr double getValue()const{return value;}
};
template<typename ToUnit,typename FromUnit> constexpr Quantity<ToUnit> convert(const Quantity<FromUnit>& quantity){double baseValue=quantity.getValue()*FromUnit::factor;return Quantity<ToUnit>(baseValue/ToUnit::factor);}
int main(){constexpr Quantity<Meter> distance(5000);constexpr auto km=convert<Kilometer>(distance);constexpr auto cm=convert<Centimeter>(distance);cout<<"Distance in Meters: "<<distance.getValue()<<" m\n"<<"Distance in Kilometers: "<<km.getValue()<<" km\n"<<"Distance in Centimeters: "<<cm.getValue()<<" cm\n";}
