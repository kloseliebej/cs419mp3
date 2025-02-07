#ifndef __RECTANGLE__
#define __RECTANGLE__
//#419begin #type=<1> #src=<http://josephconley.com/blog/2008/9/12/ray-tracer.html>
/*
 *  Rectangle.h
 *  Ray Tracer
 *
 *  Created by NoEvilPeople on 9/27/08.
 *  Copyright 2008 jmc2385@rit.edu. All rights reserved.
 *
 */

#include "Sampler.h"
#include "GeometricObject.h"

class Rectangle: public GeometricObject {	
public:
	
	Rectangle(void);   									
	
	Rectangle(const Point3D& _p0, const Vector3D& _a, const Vector3D& _b);
	
	Rectangle(const Point3D& _p0, const Vector3D& _a, const Vector3D& _b, const Normal& n);
	
	virtual Rectangle* 										
	clone(void) const;
	
	Rectangle(const Rectangle& r); 						
	
	virtual													
	~Rectangle(void);   									
	
	Rectangle& 												
	operator= (const Rectangle& rhs);
	
	virtual BBox
	get_bounding_box(void) const;				
	
	virtual bool 												 
	hit(const Ray& ray, double& t, ShadeRec& s) const;	
	
	
	// the following functions are used when the rectangle is a light source
	
	virtual void 								
	set_sampler(Sampler* sampler); 
	
	virtual Point3D 											
	sample(void);
	
	virtual Normal 																
	get_normal(const Point3D& p) const;		
	
	virtual float												
	pdf(ShadeRec& sr) const;
	
	virtual bool
	shadow_hit(const Ray& ray, float& tmin) const;
	
private:
	
	Point3D 		p0;   			// corner vertex 
	Vector3D		a;				// side
	Vector3D		b;				// side
	double			a_len_squared;	// square of the length of side a
	double			b_len_squared;	// square of the length of side b
	Normal			normal;	
	
	float			area;			// for rectangular lights
	float			inv_area;		// for rectangular lights
	Sampler*		sampler_ptr;	// for rectangular lights 	
	
	static const double kEpsilon;   											
};


#endif