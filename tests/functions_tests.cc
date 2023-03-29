#include <gtest/gtest.h>
#define CAPACITY 10
#include <functions/functions.h>

using namespace figure;

//1
TEST(FigureTests, FigureTypeDefConstructorTest)
{
	Figure f = Figure();
	EXPECT_EQ(f.getTypeFigure(), Cylinder);
}

//2
TEST(FigureTests, FigureSphereArea)
{
	Figure figure_1 = Figure::create_sphere(0,0,0,0,0,13);
	double result = figure_1.calc_of_area_sphere();
	EXPECT_NEAR(result, 2123.71, PI);
}
 
//3
TEST(FigureTests, FigureCylinderArea)
{
	Figure figure_1 = Figure::create_cylinder(6,7,2,10,11,6,  )
	double result = figure_1.calc_of_area_cylinder();
	EXPECT_NEAR(result, )
}

//4
TEST(FigureTests, FigureParallelepipedArea)
{
	
}

//5
TEST(FigureTests, FigureSphereVolume)
{
	
}

//6
TEST(FigureTests, FigureCylinderVolume)
{
	
}

//7
TEST(FigureTests, FigureParallelepipedVolume)
{
	
}

//
TEST(StorageTests, CapacityCheck)
{
	Storage figures;
	const auto f = Figure::create_sphere();
	for(int i = 0; i < Storage::CAPACITY; ++i)
	{
		figures.add(f);
	}
	ASSERT_ANY_THROW(figures.add(f));
}

//
TEST(IndexMaxVolume, )
{
	
}