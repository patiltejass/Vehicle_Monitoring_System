#include <gtest/gtest.h>
#include <QSet>
#include <../Service/filters.h>
#include <../Service/fluids.h>

using namespace testing;

TEST(Filterstest, GetFiltersTest) {
    Filters obj;
    const QSet<QString> expectedFilterSet = {"Air Filter", "Cabin Filter", "Oil Filter"};
    const QSet<QString> actualFilterSet = obj.getfilterlist();

    EXPECT_EQ(expectedFilterSet, actualFilterSet);
}
TEST(Fluidsstest, GetFluidsTest) {
    Fluids obj;
    const QSet<QString> expectedFluidSet = {"Fuel","Engine Oil","Coolant"};
    const QSet<QString> actualFluidSet = obj.getfluidlist();

    EXPECT_EQ(expectedFluidSet, actualFluidSet);
}
