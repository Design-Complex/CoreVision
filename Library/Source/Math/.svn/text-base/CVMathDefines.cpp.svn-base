/*
 *  CVMathDefines.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 7/24/08.
 *  Copyright 2008 Rob Dotson, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVMathDefines.h"

using namespace CV;

const double CVMath::PI		= 3.14159265358979323846;
const double CVMath::PI2	= 3.14159265358979323846 * 2.0;
const double CVMath::PI_2	= 3.14159265358979323846 / 2.0;
const double CVMath::PI_4	= 3.14159265358979323846 / 4.0;

double CVMath::rand( int32_t * seed ) {
	*seed = *seed * 1664525L + 1013904223L;
	return ( double ) *seed / UINT_MAX;
}

template<typename T> T CVMath::rand( int32_t *seed, T min, T max ) {
	return ( T )( CVMath::rand( seed ) * ( max - min ) + min );
}

//template<typename T> T CVMath::

template size_t		 CVMath::rand<size_t>( int32_t *seed, size_t min, size_t max );
template int8_t		 CVMath::rand<int8_t>( int32_t *seed, int8_t min, int8_t max );
template uint8_t	 CVMath::rand<uint8_t>( int32_t *seed, uint8_t min, uint8_t max );
template int16_t	 CVMath::rand<int16_t>( int32_t *seed, int16_t min, int16_t max );
template uint16_t	 CVMath::rand<uint16_t>( int32_t *seed, uint16_t min, uint16_t max );
template int32_t	 CVMath::rand<int32_t>( int32_t *seed, int32_t min, int32_t max );
template uint32_t	 CVMath::rand<uint32_t>( int32_t *seed, uint32_t min, uint32_t max );
template int64_t	 CVMath::rand<int64_t>( int32_t *seed, int64_t min, int64_t max );
template uint64_t	 CVMath::rand<uint64_t>( int32_t *seed, uint64_t min, uint64_t max );
template float		 CVMath::rand<float>( int32_t *seed, float min, float max );
template double		 CVMath::rand<double>( int32_t *seed, double min, double max );
template long double CVMath::rand<long double>( int32_t *seed, long double min, long double max );

//template void CVMath::swap<size_t>( size_t * src, size_t * dst );
//template void CVMath::swap<int8_t>( int8_t * src, int8_t * dst );
//template void CVMath::swap<uint8_t>( uint8_t * src, uint8_t * dst );
//template void CVMath::swap<int16_t>( int16_t * src, int16_t * dst );
//template void CVMath::swap<uint16_t>( uint16_t * src, uint16_t * dst );
//template void CVMath::swap<int32_t>( int32_t * src, int32_t * dst );
//template void CVMath::swap<uint32_t>( uint32_t * src, uint32_t * dst );
//template void CVMath::swap<int64_t>( int64_t * src, int64_t * dst );
//template void CVMath::swap<uint64_t>( uint64_t * src, uint64_t * dst );
//template void CVMath::swap<float>( float * src, float * dst );
//template void CVMath::swap<double>( double * src, double * dst );
//template void CVMath::swap<long double>( long double * src, long double * dst );
