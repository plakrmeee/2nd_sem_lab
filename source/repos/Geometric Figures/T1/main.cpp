#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "complexquad.hpp"

using namespace akrami;

double print(std::shared_ptr<Shape> figure)
{
	std::cout << "Frame X: " << figure->getFrameRect().pos.x << " " << "Frame Y: " << figure->getFrameRect().pos.y << std::endl;
	std::cout << "Frame width " << figure->getFrameRect().width << " " << "Frame height " << figure->getFrameRect().height << std::endl;
	std::cout << "Area: " << figure->getArea() << std::endl;
	std::cout << std::endl;
	figure->move(point_t{ 6,2 });
	std::cout << "Move (x=6 y=2) " << "Frame X: " << figure->getFrameRect().pos.x << " " << "Frame Y: " << figure->getFrameRect().pos.y << std::endl;
	std::cout << "Frame width " << figure->getFrameRect().width << " " << "Frame height " << figure->getFrameRect().height << std::endl;
	std::cout << "Area: " << figure->getArea() << std::endl;
	std::cout << std::endl;
	figure->move(4, 2);
	std::cout << "Move (dx=4 dy=2) " << "Frame X: " << figure->getFrameRect().pos.x << " " << "Frame Y: " << figure->getFrameRect().pos.y << std::endl;
	std::cout << "Frame width " << figure->getFrameRect().width << " " << "Frame height " << figure->getFrameRect().height << std::endl;
	std::cout << "Area: " << figure->getArea() << std::endl;
	std::cout << std::endl;
	figure->scale(2);
	std::cout << "Scale factor 2: " << "Frame width " << figure->getFrameRect().width << " " << "Frame height " << figure->getFrameRect().height << std::endl;
	std::cout << "Frame X: " << figure->getFrameRect().pos.x << " " << "Frame Y: " << figure->getFrameRect().pos.y << std::endl;
	std::cout << "Area: " << figure->getArea() << std::endl;
	std::cout << std::endl;

	return figure->getArea();
}

int main()
{
	std::cout << "RECTANGLE x1=2, y1=1, x2=5, y2=3" << std::endl;
	
	point_t rectanglePoint_1 = point_t{ 2, 1 };
	point_t rectanglePoint_2 = point_t{ 5, 3 };

	auto rectangle = std::make_shared<Rectangle>(rectanglePoint_1, rectanglePoint_2);

	double rectangleArea = print(rectangle);
	
	std::cout << std::endl;

	std::cout << "CIRCLE x=2, y=3, radius=2" << std::endl;

	point_t circlePoint = point_t{ 2,3 };
	double circleRadius = 2;

	auto circle = std::make_shared<Circle>(circlePoint, circleRadius);

	double circleArea = print(circle);

	std::cout << std::endl;

	std::cout << "COMPLEXQUAD x1=2, y1=2, x2=6, y2=5, x3=2, y3=5, x4=6, y4=2" << std::endl;

	point_t complexquadPoint_1 = point_t{ 2, 2 };
	point_t complexquadPoint_2 = point_t{ 6, 5 };
	point_t complexquadPoint_3 = point_t{ 2, 5 };
	point_t complexquadPoint_4 = point_t{ 6, 2 };

	auto complexquad = std::make_shared<Complexquad>(complexquadPoint_1, complexquadPoint_2, complexquadPoint_3, complexquadPoint_4);

	double complexquadArea = print(complexquad);

	std:: cout << "Sum of areas = " << rectangleArea + circleArea + complexquadArea << std::endl;
	
	return 0;
}