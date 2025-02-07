#ifndef __SPHERE__
#define __SPHERE__

// This file contains the declaration of the class Sphere

#include "GeometricObject.h"
#include "Sampler.h"
//#419begin #type=<1> #src=<http://josephconley.com/blog/2008/9/12/ray-tracer.html>
//-------------------------------------------------------------------------------- class Sphere

class Sphere: public GeometricObject {	
								  	
public:
	
	Sphere(void);   									// Default constructor
			
	Sphere(Point3D center, double r);					// Constructor 
				
	Sphere(const Sphere& sphere); 						// Copy constructor
	
	virtual Sphere* 									// Virtual copy constructor
	clone(void) const;

	virtual												// Destructor
	~Sphere(void);   									

	Sphere& 											// assignment operator
	operator= (const Sphere& sphere);				
																				
	void
	set_center(const Point3D& c);
	
	void
	set_center(const double x, const double y, const double z);
	
	void
	set_radius(const double r);
					
	virtual bool 												 
	hit(const Ray& ray, double& t, ShadeRec& s) const;	

	virtual bool
	shadow_hit(const Ray& ray, float& tmin) const;
	
	void 								
	set_sampler(Sampler* sampler);
	
	Point3D 											
	sample(void);
	
	float
	pdf(ShadeRec& sr) const;	
	
	virtual Normal 																
	get_normal(const Point3D& p) const;	
	
	virtual BBox
	get_bounding_box(void) const;
	
protected:

	Point3D 	center;   			// center coordinates as a point  
	double 		radius;				// the radius 
	Sampler*	sampler_ptr;		// sampler for being a light object
	static const double kEpsilon;   // for shadows and secondary rays
	float		inv_area;
};



inline void
Sphere::set_center(const Point3D& c) {
	center = c;
}
		
inline void
Sphere::set_center(const double x, const double y, const double z) {
	center.x = x;
	center.y = y;
	center.z = z;
}
		
inline void
Sphere::set_radius(const double r) {
	radius = r;
}

#endif
