#include "fluids.h"

Fluids::Fluids() {
    fluidlist={"Fuel","Engine Oil","Coolant"};
}
QSet<QString> Fluids::getfluidlist()
{
    return fluidlist;
}

QSet<QString> Fluids::addfluid(QString fluidname)
{
    fluidlist.insert(fluidname);
    return fluidlist;
}
