#include <gtest/gtest.h>
#include <functions/functions.h>

using namespace figure;


//1
TEST(StorageTests, StorageSizeTest)
{
	Storage fig = Storage();
	EXPECT_EQ(fig.get_size(), 0);
}

//2
TEST(StorageTests, del_item)
{
	Storage figures;
	Figure figure;
	Point point1_1 = { 9,-1,2 };
	Point point1_2 = { 0,-1,2 };
	Point point1_3 = { 0,-1,-2 };
	Point points1[3] = { point1_1, point1_2, point1_3 };
	Point point2_1 = { 0,-1,2 };
	Point point2_2 = { 4,-1,2 };
	Point points2[2] = {point2_1, point2_2};
	figures.add(figure.create_cylinder(points1));
	figures.add(figure.create_sphere(points2));
	figures.del_item(0);
	int x = 0;
	if (*figures.get_index(0) == *figure.create_sphere(points2)) ++x;
	EXPECT_EQ(x, 1);
}

//2
TEST(StorageTests, InsertTest)
{
	Storage figures;
	Figure figure;
	Point point1_1 = { 0,0,0 };
	Point point1_2 = { 0,0,13 };
	Point points1[2] = {point1_1, point1_2};
	Point point2_1 = { 9,-1,2 };
	Point point2_2 = { 0,-1,2 };
	Point point2_3 = { 0,-1,-2 };
	Point points2[3] = { point2_1, point2_2, point2_3 };
	figures.add(figure.create_sphere(points1));
	figures.add(figure.create_cylinder(points2));
	figures.insert_figure(figure.create_parallelepiped(points1),0);
	int x = 0;
	if (*figures.get_index(0) == *figure.create_parallelepiped(points1)) x++;
	EXPECT_EQ(x, 1);
}
	
//3
TEST(StorageTests, IndexOfMaxVolume)
{
	Storage figures;
	Figure figure;
	Point point1_1 = { 0,0,0 };
	Point point1_2 = { 0,0,13 };
	Point points1[2] = { point1_1, point1_2 };
	Point point2_1 = { 9,-1,2 };
	Point point2_2 = { 0,-1,2 };
	Point point2_3 = { 0,-1,-2 };
	Point points2[3] = { point2_1, point2_2, point2_3 };
	Point point3_1 = { 2,4,0 };
	Point point3_2 = { 5,1,4 };
	Point points3[2] = {point3_1, point3_2};
	figures.add(figure.create_sphere(points1));
	figures.add(figure.create_cylinder(points2));
	figures.add(figure.create_parallelepiped(points3));
	Figure result = figures.IndexOfMaxVolume();
	TypeFigure t = result.getTypeFigure();
	EXPECT_EQ(t, Sphere);
}

//4
TEST(StorageTests, InstallTest)
{
	Storage figures;
	Figure figure;
	Point point1_1 = { 0,0,0 };
	Point point1_2 = { 0,0,13 };
	Point points1[2] = { point1_1, point1_2 };
	Point point2_1 = { 9,-1,2 };
	Point point2_2 = { 0,-1,2 };
	Point point2_3 = { 0,-1,-2 };
	Point points2[3] = { point2_1, point2_2, point2_3 };
	figures.add(figure.create_sphere(points1));
	figures.add(figure.create_cylinder(points2));
	figures.install_figure(figure.create_parallelepiped(points1), 0);
	int x = 0;
	if (*figures.get_index(0) == *figure.create_parallelepiped(points1)) x++;
	EXPECT_EQ(x, 1);
}

//5
TEST(StorageTests, GetSize)
{
	Storage figures;
	Figure figure;
	Point point1_1 = { 0,0,0 };
	Point point1_2 = { 0,0,13 };
	Point points1[2] = { point1_1, point1_2 };
	Point point2_1 = { 9,-1,2 };
	Point point2_2 = { 0,-1,2 };
	Point point2_3 = { 0,-1,-2 };
	Point points2[3] = { point2_1, point2_2, point2_3 };
	Point point3_1 = { 2,4,0 };
	Point point3_2 = { 5,1,4 };
	Point points3[2] = { point3_1, point3_2 };
	figures.add(figure.create_sphere(points1));
	figures.add(figure.create_cylinder(points2));
	figures.add(figure.create_parallelepiped(points3));
	int x = figures.get_size();
	EXPECT_EQ(x, 3);
}