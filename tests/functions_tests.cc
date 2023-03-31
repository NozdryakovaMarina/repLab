#include <gtest/gtest.h>
#include <functions/functions.h>
#define PI 3.14159265
using namespace figure;

//2
TEST(FigureTests, FigureSphereArea)
{
	Figure figure_1 = Figure::create_sphere(0,0,0,0,0,13);
	double result = figure_1.calc_of_area_sphere();
	EXPECT_NEAR(result, 2123.72, PI);
}
 
 //3
 TEST(FigureTests, FigureSphereArea2)
{
	Figure figure_1 = Figure::create_sphere(0,-1,2,4,-1,2);
	double result = figure_1.calc_of_area_sphere();
	EXPECT_NEAR(result,201.06, PI);
}

//4
TEST(FigureTests, FigureCylinderArea)
{
	Figure figure_1 = Figure::create_cylinder(5,4,0,5,4,6,5,1,6);
	double result = figure_1.calc_of_area_cylinder();
	EXPECT_NEAR(result,84.15,PI);
}

//5
TEST(FigureTests, FigureCylinderArea2)
{
	Figure figure_1 = Figure::create_cylinder(0,-1,2,9,-1,2,0,-1,-2);
	double result = figure_1.calc_of_area_cylinder();
	EXPECT_NEAR(result,326.73,PI);
}
//6
TEST(FigureTests, FigureParallelepipedArea)
{
	Figure figure_1 = Figure::create_parallelepiped(2,4,0,5,1,4); 
	double result = figure_1.calc_of_area_parallelepiped();
	EXPECT_NEAR(result,66,PI);
}

//7
TEST(FigureTests, FigureParallelepipedArea2)
{
	Figure figure_1 = Figure::create_parallelepiped(1,2,-4,3,0,2); 
	double result = figure_1.calc_of_area_parallelepiped();
	EXPECT_NEAR(result,56,PI);
}

//8
TEST(FigureTests, FigureSphereVolume)
{
	Figure figure_1 = Figure::create_sphere(0,0,0,0,0,13);
	double result = figure_1.calc_of_volume_sphere();
	EXPECT_NEAR(result,9202.77,PI);
}

//9
TEST(FigureTests, FigureSphereVolume2)
{
	Figure figure_1 = Figure::create_sphere(0,-1,2,4,-1,2);
	double result = figure_1.calc_of_volume_sphere();
	EXPECT_NEAR(result,268.08,PI);
} 

//10
TEST(FigureTests, FigureCylinderVolume)
{
	Figure figure_1 = Figure::create_cylinder(5,4,0,5,4,6,5,1,6);
	double result = figure_1.calc_of_volume_cylinder();
	EXPECT_NEAR(result,848.23,PI);
}

//11
TEST(FigureTests, FigureCylinderVolume2)
{
	Figure figure_1 = Figure::create_cylinder(0,-1,2,9,-1,2,0,-1,-2);
	double result = figure_1.calc_of_volume_cylinder();
	EXPECT_NEAR(result,452.39,PI);
}

//12
TEST(FigureTests, FigureParallelepipedVolume)
{
	Figure figure_1 = Figure::create_parallelepiped(2,4,0,5,1,4); 
	double result = figure_1.calc_of_volume_parallelepiped();
	EXPECT_NEAR(result,36,PI);
}

//13
TEST(FigureTests, FigureParallelepipedVolume2)
{
	Figure figure_1 = Figure::create_parallelepiped(1,2,-4,3,0,2); 
	double result = figure_1.calc_of_volume_parallelepiped();
	EXPECT_NEAR(result,24,PI);
}
