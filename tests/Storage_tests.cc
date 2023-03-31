#include <gtest/gtest.h>
#include <functions/functions.h>

using namespace figure;


//1
TEST(StorageTests, CapacityCheck)
{
	Storage _figures;
	Figure figure_1 = Figure::create_sphere(0,0,0,0,0,13);
	for(int i = 0; i < Storage::CAPACITY; ++i)
	{
		_figures.add(figure_1);
	}
	ASSERT_ANY_THROW(_figures.add(figure_1));
}

//2
TEST(StorageTests, del_item)
{
	Storage _figures;
	Figure figure_1 = Figure::create_cylinder(0,-1,2,9,-1,2,0,-1,-2);
	Figure figure_2 = Figure::create_sphere(0,-1,2,4,-1,2);
	_figures.add(figure_1);
	_figures.add(figure_2);
	_figures.del_item(0);
	TypeFigure t = _figures[0].getTypeFigure();
	EXPECT_EQ(t, Sphere);
}

//3
TEST(StorageTests, InsertTest)
{
	Storage _figures;
	Figure figure_1 = Figure::create_sphere(0,0,0,0,0,13);
	Figure figure_2 = Figure::create_cylinder(0,-1,2,9,-1,2,0,-1,-2);
	Figure figure_3 = Figure::create_parallelepiped(1,2,-4,3,0,2);
	_figures.add(figure_1);
	_figures.add(figure_2);
	_figures.insert_figure(figure_3,1);
	TypeFigure t = _figures[1].getTypeFigure();
	EXPECT_EQ(t,Parallelepiped);
}
	
//4
TEST(StorageTests,IndexOfMaxVolume)
{
	Storage _figures;
	_figures.add(Figure::create_sphere(0,-1,2,4,-1,2));
	_figures.add(Figure::create_cylinder(5,4,0,5,4,6,5,1,6));
	_figures.add(Figure::create_parallelepiped(1,2,-4,3,0,2));
	EXPECT_EQ(IndexOfMaxVolume(_figures),1);
}