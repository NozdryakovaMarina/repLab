#include <gtest/gtest.h>
#include <functions/functions.h>
#define EPSILON 0.01
using namespace figure;

//2
TEST(FigureTests, FigureSphereArea)
{
	Figure figure_1 = Figure::create_sphere(0,0,0,0,0,13);
	double result = figure_1.calc_of_area_sphere();
	EXPECT_NEAR(result, 2122.64, EPSILON);
} 
 //3
 TEST(FigureTests, FigureSphereArea2)
{
	Figure figure_1 = Figure::create_sphere(0,-1,2,4,-1,2);
	double result = figure_1.calc_of_area_sphere();
	EXPECT_NEAR(result,200.96, EPSILON);
}

//4
TEST(FigureTests, FigureCylinderArea)
{
	Figure figure_1 = Figure::create_cylinder(5,4,0,5,4,6,5,1,6);
	double result = figure_1.calc_of_area_cylinder();
	EXPECT_NEAR(result,169.56, EPSILON);
}
//169.65
//5
TEST(FigureTests, FigureCylinderArea2)
{
	Figure figure_1 = Figure::create_cylinder(1, -1, 2, 1, -1, -2, 1, 3, -2);
	double result = figure_1.calc_of_area_cylinder();
	EXPECT_NEAR(result,200.96, EPSILON);
}

//6
TEST(FigureTests, FigureParallelepipedArea)
{
	Figure figure_1 = Figure::create_parallelepiped(2,4,0,5,1,4); 
	double result = figure_1.calc_of_area_parallelepiped();
	EXPECT_NEAR(result,66, EPSILON);
}

//7
TEST(FigureTests, FigureParallelepipedArea2)
{
	Figure figure_1 = Figure::create_parallelepiped(1,2,-4,3,0,2); 
	double result = figure_1.calc_of_area_parallelepiped();
	EXPECT_NEAR(result,56, EPSILON);
}

//8
TEST(FigureTests, FigureSphereVolume)
{
	Figure figure_1 = Figure::create_sphere(0,0,0,0,0,13);
	double result = figure_1.calc_of_volume_sphere();
	EXPECT_NEAR(result,9198.106, EPSILON);
}

//9
TEST(FigureTests, FigureSphereVolume2)
{
	Figure figure_1 = Figure::create_sphere(0,-1,2,4,-1,2);
	double result = figure_1.calc_of_volume_sphere();
	EXPECT_NEAR(result,267.946, EPSILON);
} 

//10
TEST(FigureTests, FigureCylinderVolume)
{
	Figure figure_1 = Figure::create_cylinder(5,4,0,5,4,6,5,1,6);
	double result = figure_1.calc_of_volume_cylinder();
	EXPECT_NEAR(result,169.56, EPSILON);
}

//11
TEST(FigureTests, FigureCylinderVolume2)
{
	Figure figure_1 = Figure::create_cylinder(9,-1,2, 0, -1, 2, 0,-1,-2);
	double result = figure_1.calc_of_volume_cylinder();
	EXPECT_NEAR(result, 452.16, EPSILON);
}

//12
TEST(FigureTests, FigureParallelepipedVolume)
{
	Figure figure_1 = Figure::create_parallelepiped(2,4,0,5,1,4); 
	double result = figure_1.calc_of_volume_parallelepiped();
	EXPECT_NEAR(result,36, EPSILON);
}

//13
TEST(FigureTests, FigureParallelepipedVolume2)
{
	Figure figure_1 = Figure::create_parallelepiped(1,2,-4,3,0,2);
	double result = figure_1.calc_of_volume_parallelepiped();
	EXPECT_NEAR(result,24, EPSILON);
}

TEST(FigureTests, FigureCylinderPi)
{
	Figure figure_1 = Figure::create_cylinder(5, 4, 0, 5, 4, 6, 5, 1, 6);
	double result = figure_1.calc_of_area_cylinder();
	ASSERT_NO_THROW(result, 169.56, EPSILON);
}

TEST(FigureTests, FigureCylinderPi2)
{
	Figure figure_1 = Figure::create_cylinder(0, 0, 0, 5, 4, 6, 5, 1, 6);
	ASSERT_ANY_THROW(figure_1.calc_of_area_cylinder());
}

TEST(FigureTests, FigureCylinderPiz)
{
	Figure figure_1 = Figure::create_cylinder(5, 4, 0, 5, 4, 6, 5, 1, 6);
	double result = figure_1.calc_of_volume_cylinder();
	ASSERT_NO_THROW(result, 169.56, EPSILON);
}

TEST(FigureTests, FigureCylinderPiz2)
{
	Figure figure_1 = Figure::create_cylinder(0, 0, 0, 5, 4, 6, 5, 1, 6);
	ASSERT_ANY_THROW(figure_1.calc_of_volume_cylinder());
}