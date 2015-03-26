/*
 *  CVGammaTable.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 11/17/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVGammaTable.h"

using namespace CV;

CVRTTIDefine( CVGammaTable, CVObject )

bool CVGammaTable::saved_ = false;
CVFloatMatrix CVGammaTable::systemGamma_( 256, 3 );

CVGammaTable::CVGammaTable( const float gamma ) : gamma_( CVFloatMatrix( 256, 3 ) ) {
	
}

CVGammaTable::CVGammaTable( const float r, const float g, const float b ) : gamma_( CVFloatMatrix( 256, 3 ) ) {
	
}

CVGammaTable::CVGammaTable( const CVFloatVector &red, const CVFloatVector &green, const CVFloatVector &blue ) : gamma_( CVFloatMatrix( 256, 3 ) ) {
	// Get a pointer to the gamma table's memory
	float * gamma = gamma_.data();
	CVIndex n = sizeof( float ) * 256;
	
	// Copy the rgb values from the buffers into the table
	memcpy( gamma, red.data(), n );
	memcpy( gamma + 256, green.data(), n );
	memcpy( gamma + 512, blue.data(), n );
}

CVGammaTable::~CVGammaTable() {

}

CVFloatMatrix & CVGammaTable::systemGamma() {
	return CVGammaTable::systemGamma_;
}

void CVGammaTable::saveSystemGamma() {
	// Create the buffers
	float r[ 256 ], g[ 256 ], b[ 256 ];
	CGTableCount samples;
	
	// Get the values!
	CGGetDisplayTransferByTable( 0, 256, r, g, b, &samples );
	
	// Set saved flag
	CVGammaTable::saved_ = true;
}

void CVGammaTable::restoreSystemGamma() {
	// Do nothing if no gamma table has been saved
	if( !CVGammaTable::saved_ ) return;
	
	// Grab the values from the saved buffer
	float r[ 256 ], g[ 256 ], b[ 256 ];
	for( CVIndex i = 0; i < 256; i++ ) {
		r[ i ] = CVGammaTable::systemGamma_( i, 0 );
		g[ i ] = CVGammaTable::systemGamma_( i, 1 );
		b[ i ] = CVGammaTable::systemGamma_( i, 2 );
	}
	
	// Set the gamma!
	CGSetDisplayTransferByTable( 0, 256, r, g, b );
	
	// Reset saved flag
	CVGammaTable::saved_ = false;
}

void CVGammaTable::apply() {
	if( !CVGammaTable::saved_ )
		CVGammaTable::saveSystemGamma();
}

void CVGammaTable::reset() {
	if( CVGammaTable::saved_ )
		CVGammaTable::restoreSystemGamma();
}