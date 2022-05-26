#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace akrami
{
	class Rectangle : public Shape
	{
	public:
		Rectangle(const point_t& pos1, const point_t& pos2);
		double getArea() const override;
		rectangle_t getFrameRect() const override;
		void move(const point_t& pos) override;
		void move(double dx, double dy) override;
		void scale(double k) override;

	private:
		point_t posFirst_;
		point_t posSecond_;
	};
}

#endif // RECTANGLE_HPP