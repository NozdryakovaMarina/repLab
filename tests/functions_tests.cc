#include <gtest/gtest.h>
#include <functions/functions.h>
#define EPSILON 0.01
using namespace figure;

//1
TEST(FiguresTests, FigureDefaultConstructorTypeTest) 
{
	Figure fig = Figure();
	EXPECT_EQ(fig.getTypeFigure(), Sphere);
}

//2
TEST(FigureTests, FigureSphereArea)
{
	Point point1 = { 0,0,0};
	Point point2 = {0,0,13};
	Point point_figure[2] = { point1, point2 };
	Figure f(Sphere, point_figure);
	EXPECT_NEAR(f.compute_area(), 2122.64, EPSILON);
} 
 //3
 TEST(FigureTests, FigureSphereArea2)
{
	 Point point1 = {0, -1, 2};
	 Point point2 = {4, -1, 2};
	Point point_figure[2] = { point1, point2 };
	Figure f(Sphere, point_figure);
	EXPECT_NEAR(f.compute_area(), 200.96, EPSILON);
}

//4
TEST(FigureTests, FigureCylinderArea)
{
	Point point1 = {5,4,0};
	Point point2 = {5,4,6};
	Point point3 = {5,1,6};
	Point point_figure[3] = { point1, point2, point3 };
	Figure f(Cylinder, point_figure);
	EXPECT_NEAR(f.compute_area(), 169.56, EPSILON);
}

//5
TEST(FigureTests, FigureCylinderArea2)
{
	Point point1 = { 1,-1,2 };
	Point point2 = { 1,-1,-2 };
	Point point3 = { 1,3,-2 };
	Point point_figure[3] = { point1, point2, point3 };
	Figure f(Cylinder, point_figure);
	EXPECT_NEAR(f.compute_area(), 200.96, EPSILON);
}

//6
TEST(FigureTests, FigureParallelepipedArea)
{
	Point point1 = { 2,4,0 };
	Point point2 = { 5,1,4 };
	Point point_figure[2] = { point1, point2 };
	Figure f(Parallelepiped, point_figure); 
	EXPECT_NEAR(f.compute_area(), 66, EPSILON);
}

//7
TEST(FigureTests, FigureParallelepipedArea2)
{
	Point point1 = { 1,2,-4 };
	Point point2 = { 3,0,2 };
	Point point_figure[2] = { point1, point2 };
	Figure f(Parallelepiped, point_figure);
	EXPECT_NEAR(f.compute_area(), 56, EPSILON);
}

//8
TEST(FigureTests, FigureSphereVolume)
{
	Point point1 = { 0,0,0 };
	Point point2 = { 0,0,13 };
	Point point_figure[2] = { point1, point2 };
	Figure f(Sphere, point_figure);
	EXPECT_NEAR(f.compute_volume(), 9198.106, EPSILON);
}

//9
TEST(FigureTests, FigureSphereVolume2)
{
	Point point1 = { 0, -1, 2 };
	Point point2 = { 4, -1, 2 };
	Point point_figure[2] = { point1, point2 };
	Figure f(Sphere, point_figure);
	EXPECT_NEAR(f.compute_volume(), 267.946, EPSILON);
} 

//10
TEST(FigureTests, FigureCylinderVolume)
{
	Point point1 = { 5,4,0 };
	Point point2 = { 5,4,6 };
	Point point3 = { 5,1,6 };
	Point point_figure[3] = { point1, point2, point3 };
	Figure f(Cylinder, point_figure);
	EXPECT_NEAR(f.compute_volume(), 169.56, EPSILON);
}

//11
TEST(FigureTests, FigureCylinderVolume2)
{
	Point point1 = { 1,-1,2 };
	Point point2 = { 1,-1,-2 };
	Point point3 = { 1,3,-2 };
	Point point_figure[3] = { point1, point2, point3 };
	Figure f(Cylinder, point_figure);
	EXPECT_NEAR(f.compute_volume(), 200.96, EPSILON);
}

//12
TEST(FigureTests, FigureParallelepipedVolume)
{
	Point point1 = { 2,4,0 };
	Point point2 = { 5,1,4 };
	Point point_figure[2] = { point1, point2 };
	Figure f(Parallelepiped, point_figure);
	EXPECT_NEAR(f.compute_volume(), 36, EPSILON);
}

//13
TEST(FigureTests, FigureParallelepipedVolume2)
{
	Point point1 = { 1,2,-4 };
	Point point2 = { 3,0,2 };
	Point point_figure[2] = { point1, point2 };
	Figure f(Parallelepiped, point_figure);
	EXPECT_NEAR(f.compute_volume(), 24, EPSILON);
}

//14
TEST(FigureTests, FigureCylinderPi)
{
	Point point1 = { 5,4,0 };
	Point point2 = { 5,4,6 };
	Point point3 = { 5,1,6 };
	Point point_figure[3] = { point1, point2, point3 };
	Figure f(Cylinder, point_figure);
	ASSERT_NO_THROW(f.compute_area());
}

//15
TEST(FigureTests, FigureCylinderPi2)
{
	Point point1 = { 0,0,0 };
	Point point2 = { 5,4,6 };
	Point point3 = { 5,1,6 };
	Point point_figure[3] = { point1, point2, point3 };
	Figure f(Cylinder, point_figure);
	ASSERT_ANY_THROW(f.compute_area());
}

//16
TEST(FigureTests, FigureCylinderPiz)
{
	Point point1 = { 5,4,0 };
	Point point2 = { 5,4,6 };
	Point point3 = { 5,1,6 };
	Point point_figure[3] = { point1, point2, point3 };
	Figure f(Cylinder, point_figure);
	ASSERT_NO_THROW(f.compute_volume());
}

//17
TEST(FigureTests, FigureCylinderPiz2)
{
	Point point1 = { 0,0,0 };
	Point point2 = { 5,4,6 };
	Point point3 = { 5,1,6 };
	Point point_figure[3] = { point1, point2, point3 };
	Figure f(Cylinder, point_figure);
	ASSERT_ANY_THROW(f.compute_volume());
}