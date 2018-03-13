/*! Wrapper class for representing a auxiliary plane in 3d space.*/
#ifndef Plane_h
#define Plane_h
class Plane{
public:
	float alpha/*! Angle from x-axis*/,beta/*! Angle from y-axis*/,gamma/*! Angle from z-axis*/,distaneFromOrigin/*!Perpendicular distance from the origin*/;
};
#endif