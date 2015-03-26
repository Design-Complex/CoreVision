/*
 *  CVGammaTable.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 11/17/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVGammaTable_
#define _CVGammaTable_

#include "CVMath.h"

namespace CV {

	class CVGammaTable : public CVObject {
		CVRTTIDeclare()
		
	private:
		CVPrivateCopyAndAssign( CVGammaTable );
		
		static bool				saved_;
		static CVFloatMatrix	systemGamma_;
		CVFloatMatrix			gamma_;
		
	public:
		CVGammaTable( const float gamma = 1.0 );
		CVGammaTable( const float r = 1.0, const float g = 1.0, const float b = 1.0 );
		CVGammaTable( const CVFloatVector &red = 0, const CVFloatVector &green = 0, const CVFloatVector &blue = 0 );
		virtual ~CVGammaTable();
		
		static CVFloatMatrix & systemGamma();
		static void saveSystemGamma();
		static void restoreSystemGamma();
		
		virtual void apply();
		virtual void reset();
	};
	
}

#endif // _CVGammaTable_
