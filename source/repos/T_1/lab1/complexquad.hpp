#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP

#include "shape.hpp"

namespace akrami
{
	class Complexquad : public Shape
	{
	public:
		Complexquad(const point_t& pos1, const point_t& pos2, const point_t& pos3, const point_t& pos4);
		double getArea() const override;
		rectangle_t getFrameRect() const override;
		void move(const point_t& pos) override;
		void move(double dx, double dy) override;
		void scale(double k) override;

	private:
		point_t posFirst_;
		point_t posSecond_;
		point_t posThird_;
		point_t posFourth_;
	};
}

#endif // COMPLEXQUAD_HPP