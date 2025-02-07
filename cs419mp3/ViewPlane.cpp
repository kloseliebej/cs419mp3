// This file contains the definition the ViewPlane class
//#419begin #type=<1> #src=<http://josephconley.com/blog/2008/9/12/ray-tracer.html>
#include "ViewPlane.h"
#include "MultiJittered.h"
#include "Regular.h"
	
// ---------------------------------------------------------------- default constructor	
						
ViewPlane::ViewPlane(void)							
	: 	hres(400), 
		vres(400),
		image_hres(400),
		image_vres(400),
		s(1.0),
		gamma(1.0),
		inv_gamma(1.0),
		show_out_of_gamut(false),
        num_samples(1),
		sampler_ptr(NULL),
		max_depth(0)
{}


// ---------------------------------------------------------------- copy constructor

ViewPlane::ViewPlane(const ViewPlane& vp)   
	:  	hres(vp.hres),  
		vres(vp.vres), 
		image_hres(vp.hres),  
		image_vres(vp.vres), 
		s(vp.s),
		gamma(vp.gamma),
		inv_gamma(vp.inv_gamma),
		show_out_of_gamut(vp.show_out_of_gamut),
		sampler_ptr(vp.sampler_ptr),
		num_samples(vp.num_samples),
		max_depth(vp.max_depth)
{}


// ---------------------------------------------------------------- assignment operator

ViewPlane& 
ViewPlane::operator= (const ViewPlane& rhs) {
	if (this == &rhs)
		return (*this);
		
	hres 				= rhs.hres;
	vres 				= rhs.vres;
	image_hres			= rhs.hres;
	image_vres			= rhs.vres;
	s					= rhs.s;
	gamma				= rhs.gamma;
	inv_gamma			= rhs.inv_gamma;
	show_out_of_gamut	= rhs.show_out_of_gamut;
	num_samples			= rhs.num_samples;
	sampler_ptr			= rhs.sampler_ptr;
	max_depth			= rhs.max_depth;
	
	return (*this);
}


// -------------------------------------------------------------- destructor

ViewPlane::~ViewPlane(void) {}

void	// Set our sampler
ViewPlane::set_sampler(Sampler* sp) {
	if (sampler_ptr) {
		delete sampler_ptr;
		sampler_ptr = NULL;
	}
	
	num_samples - sp->get_num_samples();
	sampler_ptr = sp;
}

void	// Set number of samples and sampler
ViewPlane::set_samples(const int n)	{
	num_samples = n;
	
	if (sampler_ptr)
	{
		delete sampler_ptr;
		sampler_ptr = NULL;
	}
	
	
	if (num_samples > 1)
	{
		sampler_ptr = new MultiJittered(num_samples);
	}
	else
	{
		sampler_ptr = new Regular(1);
	}
}



	





