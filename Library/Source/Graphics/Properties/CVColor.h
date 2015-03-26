/*
 *  CVColor.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 7/29/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVColor_
#define _CVColor_

#include "CVVector4.h"

namespace CV {

#define kWhiteColor				CVColor( 1.0f, 1.0f, 1.0f, 1.0f )
#define kBlackColor				CVColor( 0.0f, 0.0f, 0.0f, 1.0f )
#define kNeutralGreyColor		CVColor( .5, .5, .5, 1. )
#define kGhostWhiteColor		CVColor( .972, .972, 1., 1. )
#define kWhiteSmokeColor		CVColor( .96, .96, .96, .1 )
#define kLightSlateGreyColor	CVColor( .4666, .5333, .6, .1 )
#define kLightSteelBlueColor	CVColor( .6902, .7686, .88705, .1 )
#define kOliveDrabColor			CVColor( .4196, .5568, .1372, .1 )
#define kLawnGreenColor			CVColor( .4862, .9882, 0., 1. )
#define kSeaGreenColor			CVColor( .180, .545, .3411, 1. )
#define kCornflowerBlueColor	CVColor( .392, .5843, .9294, .1 )
#define kRedColor				CVColor( 1., 0., 0., 1. )
#define kYellowColor			CVColor( 1., 1., 0., 1. )
#define kGainsboroColor			CVColor( .8627, .8627, .8627, 1. )
#define kDarkOrangeColor		CVColor( 1., .549, 0., 1. )
#define kVeryDarkBrownColor		CVColor( .3607, .25, .2, 1. )
#define kLemonChiffonColor		CVColor( 1., .9803, .8039 )
	
	class CVColor : public CVVector4<float> {
		CVRTTIDeclare()
		
	public:
		float &r, &g, &b, &a;
		
		CVColor( float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 1.0f );
		CVColor( const CVColor &rhs );
		virtual ~CVColor();
		
		CVColor & operator=( const CVColor &rhs );
		
		// TODO : add conversions to dkl colorspace
		
		static const CVColor white;
		static const CVColor black;
		static const CVColor neutral;
		static const CVColor red;
		static const CVColor green;
		static const CVColor blue;		
	};
	
}

#endif // _CVColor_
