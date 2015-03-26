/*
 *  CVTransformer.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/8/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVTransformer.h"
#include "CVGraphicsIncludes.h"

using namespace CV;

CVTransformer::CVTransformer() : transform_( CVTransform::identity( 4, 4 ) ), identity_( true ) {}

CVTransformer::~CVTransformer() {}

void CVTransformer::transform() {
	if( !identity_ ) glMultMatrixf( transform_.data() );
}

void CVTransformer::inverseTransform() {
	if( !identity_ ) glMultMatrixf( transform_.inverse().data() );
}

CVVertex CVTransformer::position() {
	return transform_.inverse().mult( kCVOrigin );
}

void CVTransformer::reset() {
	transform_ = CVMatrix<float>::identity( 4, 4 );
	identity_ = true;
}

CVTransform * CVTransformer::data() {
	return &transform_;
}

void CVTransformer::perspective( const float d ) {
	if( d != 0 ) {
		identity_ = false;
		
		float f = 1. / d;
		transform_( 0, 3 ) += transform_( 0, 2 ) * f; transform_( 0, 2 ) = 0.;
		transform_( 1, 3 ) += transform_( 1, 2 ) * f; transform_( 1, 2 ) = 0.;
		transform_( 2, 3 ) += transform_( 2, 2 ) * f; transform_( 2, 2 ) = 0.;
		transform_( 3, 3 ) += transform_( 3, 2 ) * f; transform_( 3, 2 ) = 0.;
	}

}

void CVTransformer::rotate( const float theta, const CVVertex &vec ) {
	const float &x = vec[ 0 ], &y = vec[ 1 ], &z = vec[ 2 ];
	float c = cos( theta ), s = sin( theta ), t;
	
	identity_ = false;
	if( x ) { // x
		t = transform_( 0, 1 ); transform_( 0, 1 ) = ( t * c ) - ( transform_( 0, 2 ) * s ); transform_( 0, 2 ) = ( t * s ) + ( transform_( 0, 2 ) * c );				
		t = transform_( 1, 1 ); transform_( 1, 1 ) = ( t * c ) - ( transform_( 1, 2 ) * s ); transform_( 1, 2 ) = ( t * s ) + ( transform_( 1, 2 ) * c );
		t = transform_( 2, 1 ); transform_( 2, 1 ) = ( t * c ) - ( transform_( 2, 2 ) * s ); transform_( 2, 2 ) = ( t * s ) + ( transform_( 2, 2 ) * c );
		t = transform_( 3, 1 ); transform_( 3, 1 ) = ( t * c ) - ( transform_( 3, 2 ) * s ); transform_( 3, 2 ) = ( t * s ) + ( transform_( 3, 2 ) * c );
	}
	
	if( y ) { // y
		t = transform_( 0, 0 ); transform_( 0, 0 ) = ( t * c ) + ( transform_( 0, 2 ) * s ); transform_( 0, 2 ) = ( transform_( 0, 2 ) * c ) - ( t * s );
		t = transform_( 1, 0 ); transform_( 1, 0 ) = ( t * c ) + ( transform_( 1, 2 ) * s ); transform_( 1, 2 ) = ( transform_( 1, 2 ) * c ) - ( t * s );
		t = transform_( 2, 0 ); transform_( 2, 0 ) = ( t * c ) + ( transform_( 2, 2 ) * s ); transform_( 2, 2 ) = ( transform_( 2, 2 ) * c ) - ( t * s );
		t = transform_( 3, 0 ); transform_( 3, 0 ) = ( t * c ) + ( transform_( 3, 2 ) * s ); transform_( 3, 2 ) = ( transform_( 3, 2 ) * c ) - ( t * s );
	}
	
	if( z ) { // z
		t = transform_( 0, 0 ); transform_( 0, 0 ) = ( t * c ) - ( transform_( 0, 1 ) * s ); transform_( 0, 1 ) = ( t * s ) + ( transform_( 0, 1 ) * c );
		t = transform_( 1, 0 ); transform_( 1, 0 ) = ( t * c ) - ( transform_( 1, 1 ) * s ); transform_( 1, 1 ) = ( t * s ) + ( transform_( 1, 1 ) * c );
		t = transform_( 2, 0 ); transform_( 2, 0 ) = ( t * c ) - ( transform_( 2, 1 ) * s ); transform_( 2, 1 ) = ( t * s ) + ( transform_( 2, 1 ) * c );
		t = transform_( 3, 0 ); transform_( 3, 0 ) = ( t * c ) - ( transform_( 3, 1 ) * s ); transform_( 3, 1 ) = ( t * s ) + ( transform_( 3, 1 ) * c );
	}
}
 
void CVTransformer::scale( const CVVertex &vec ) {
	const float &x = vec[ 0 ], &y = vec[ 1 ], &z = vec[ 2 ];
	identity_ = false;
	
	transform_( 0, 0 ) *= x; transform_( 0, 1 ) *= y; transform_( 0, 2 ) *= z;
	transform_( 1, 0 ) *= x; transform_( 1, 1 ) *= y; transform_( 1, 2 ) *= z;
	transform_( 2, 0 ) *= x; transform_( 2, 1 ) *= y; transform_( 2, 2 ) *= z; 
	transform_( 3, 0 ) *= x; transform_( 3, 1 ) *= y; transform_( 3, 2 ) *= z;
}

void CVTransformer::translate( const CVVertex &vec ) {
	const float &x = vec[ 0 ], &y = vec[ 1 ], &z = vec[ 2 ];
	identity_ = false;
	
	transform_( 0, 0 ) += transform_( 0, 3 ) * x; transform_( 0, 1 ) += transform_( 0, 3 ) * y; transform_( 0, 2 ) += transform_( 0, 3 ) * z;
	transform_( 1, 0 ) += transform_( 1, 3 ) * x; transform_( 1, 1 ) += transform_( 1, 3 ) * y; transform_( 1, 2 ) += transform_( 1, 3 ) * z;
	transform_( 2, 0 ) += transform_( 2, 3 ) * x; transform_( 2, 1 ) += transform_( 2, 3 ) * y; transform_( 2, 2 ) += transform_( 2, 3 ) * z;
	transform_( 3, 0 ) += transform_( 3, 3 ) * x; transform_( 3, 1 ) += transform_( 3, 3 ) * y; transform_( 3, 2 ) += transform_( 3, 3 ) * z;
}
