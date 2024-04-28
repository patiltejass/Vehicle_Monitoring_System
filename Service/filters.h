#ifndef FILTERS_H
#define FILTERS_H
#include<QSet>

class Filters
{
public:
    Filters();
    QSet<QString> getfilterlist();
    QSet<QString> addfilter(QString filtername);
private:
    QSet<QString> filterlist;

};

#endif // FILTERS_H
