#include <gtest/gtest.h>
#define CAPACITY 10
#include <functions/functions.h>

using namespace figure;

//1
TEST(FigureTests, FigureTypeDefConstructorTest)
{
	Figure f = Figure();
	EXPECT_EQ(fig.getTypeFigure(), Cylinder);
}

 