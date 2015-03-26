/*
 *  CVCamera.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/7/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVCamera.h"

using namespace CV;

CVRTTIDefine( CVCamera, CVObject )

CVCamera::CVCamera( CVPixel origin, CVPixel dims, float zoom,  bool scissor ) : 
	CVObject::CVObject(), 
	scissor_( scissor ),
	zoom_( 0 ),
	origin_( origin ),
	dimensions_( dims ) {
		
		CV_ASSERT( zoom != 0.0f );
		zoom_ = 1.0f / zoom;
}

CVCamera::~CVCamera() {
	
}

void CVCamera::reset() { 
	setZoom( 1.0f / zoom_ );
	
	CVTransformer::reset();
}

float CVCamera::zoom() {
	return zoom_;
}

void CVCamera::setZoom( float z ) {
	zoom_ = 1.0f / z;
}

// Viewing Methods

void CVCamera::setup() {
	// Do nothing for a standard camera
}

void CVCamera::view() {
	if( scissor_ ) {
		glEnable( GL_SCISSOR_TEST );
		glViewport( origin_.x, origin_.y, dimensions_.x, dimensions_.y );
		glScissor( origin_.x, origin_.y, dimensions_.x, dimensions_.y );
	} else {
		glViewport( origin_.x, origin_.y, dimensions_.x, dimensions_.y );
	}
	
	this->setup();
	
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	CVTransformer::transform();
}


CVOrthographicCamera::CVOrthographicCamera( CVPixel origin, CVPixel dims, float zoom,  bool scissor ) :  CVCamera( origin, dims, zoom, scissor ) {}

CVOrthographicCamera::~CVOrthographicCamera() {}

// Viewing Methods
void CVOrthographicCamera::setup() {
	glMatrixMode( GL_PROJECTION ); 
	glLoadIdentity();
	
	if( dimensions_[ 0 ] <= dimensions_[ 1 ] )
		glOrtho( -this->zoom_, this->zoom_, -this->zoom_*dimensions_.y/dimensions_.x, this->zoom_*dimensions_.y/dimensions_.x, -this->zoom_, this->zoom_ );
	else
		glOrtho( -this->zoom_*dimensions_.x/dimensions_.y, this->zoom_*dimensions_.x/dimensions_.y, -this->zoom_, this->zoom_, -this->zoom_, this->zoom_ );
}


//void CVPerspectiveCamera::frustum( float left, float right, float bottom, float top, float near, float far ) {
//	left_ = left; right_ = right; bottom_ = bottom; top_ = top; near_ = near; far_ = far;
//}
