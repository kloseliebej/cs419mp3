/*
 *  BRDF.cpp
 *  Ray Tracer
 *
 *  Created by NoEvilPeople on 9/17/08.
 *  Copyright 2008 jmc2385@rit.edu. All rights reserved.
 *
 */
//#419begin #type=<1> #src=<http://josephconley.com/blog/2008/9/12/ray-tracer.html>
#include "BRDF.h"

BRDF::BRDF(void) : sampler_ptr(NULL) 
{}

BRDF::BRDF(const BRDF& brdf) {
	if (brdf.sampler_ptr) {
		sampler_ptr = brdf.sampler_ptr->clone(); // should implement this
	}
	else {
		sampler_ptr = NULL;
	}
}

BRDF&
BRDF::operator= (const BRDF& rhs) {
	if (this == &rhs)
		return (*this);
	
	if (sampler_ptr) {
		delete sampler_ptr;
		sampler_ptr = NULL;
	}
	
	if (rhs.sampler_ptr) {
		sampler_ptr = rhs.sampler_ptr->clone();	// should implement this
	}
		
	return (*this);
}


BRDF::~BRDF(void) {
	if (sampler_ptr) {
		delete sampler_ptr;
		sampler_ptr = NULL;
	}
}

void
BRDF::set_sampler(Sampler* sPtr) {
	sampler_ptr = sPtr;
	sampler_ptr->map_samples_to_hemisphere(1);	// perfect diffuse
}

// ------------------------------------------------------------------------ f

MyRGBColor
BRDF::f(const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const {
	return (black);
}


// ------------------------------------------------------------------------ sample_f

MyRGBColor
BRDF::sample_f(const ShadeRec& sr,  Vector3D& wo, const Vector3D& wi) const {
	return (black);
}


// ------------------------------------------------------------------------ sample_f

//RGBColor
//BRDF::sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi, float& pdf) const {
//	return (black);
//}


// ------------------------------------------------------------------------ rho	

MyRGBColor
BRDF::rho(const ShadeRec& sr, const Vector3D& wo) const {
	return (black);
}