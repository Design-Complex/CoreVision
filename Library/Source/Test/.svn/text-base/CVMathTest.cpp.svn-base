/*
 *  CVMathTest.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 8/25/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CoreVision.h"

class CVComputeThreadOne : public CVDisplayThread {
	virtual void * run() {
		CVMatrix<double> a = CVMatrix<double>( 4, 4 );
		
		std::cout << a.description() << std::endl;
		
		CVMatrix<double> b = CVMatrix<double>::identity( 4, 4 );
		
		std::cout << b.description() << std::endl;
		
		CVMatrix<double> c = a + b;
		
		std::cout << c.description() << std::endl;
		
		c = a - b;
		
		std::cout << c.description() << std::endl;
		
		c += ( a + b );
		
		std::cout << c.description() << std::endl;
		
		c = c + 4;
		
		std::cout << c.description() << std::endl;
		
		c /= CVMath::PI;
		
		std::cout << c.description() << std::endl;
		
		return NULL;
	}
};

class CVComputeThreadTwo : public CVDisplayThread {
	virtual void * run() {
		CVMatrix<double> a = CVMatrix<double>::random( 10, 10 );
		CVMatrix<double> b = CVMatrix<double>::identity( 10, 10 );
		
		std::cout << a.description() << std::endl;
		std::cout << b.description() << std::endl;
		
		CVMatrix<double> c = a;
		c.transpose();
		
		std::cout << c.description() << std::endl;
		
		c.clamp( 0, .25 );
		std::cout << c.description() << std::endl;
		
		c = a.max( b );
		std::cout << c.description() << std::endl;
		
		c = a.min( b );
		std::cout << c.description() << std::endl;
		
		return NULL;
	}
};

class CVComputeThreadThree : public CVDisplayThread {
	virtual void * run() {
		CVMatrix2<double> a( 1, 2, 3, 4 );
		CVMatrix2<double> b = a;
		
		std::cout << a.description() << std::endl;
		
		b.transpose();
		std::cout << b.description() << std::endl;
		
		CVMatrix2<double> c( b * a );
		std::cout << c.description() << std::endl;
		
		CVPixel pix( 1, 1 );
		std::cout << pix.x << ", " << pix.y << std::endl;
		
		try {
			//CVMatrix<double>d( 0, 0 );
			
			std::cout << a.mult( b ).description() << std::endl;
		} CVThrowAllExceptions()
		
		try {
			CVMatrix2<double> a( 1, 0, 1, 0 );
			CVVector2<double> v( 0, 1 );
			
			CVVector2<double> r = a * v;
			
			std::cout << r.description() << std::endl;
		} CVThrowAllExceptions()
		
		return NULL;
	}
};

int32_t main() {
	try {
		CVThreadManager *tm = CVThreadManager::sharedInstance();
		//CVThread *a = tm->spawn( new CVComputeThreadOne() );
		//CVThread *b = tm->spawn( new CVComputeThreadTwo() );
		CVThread *c = tm->spawn( new CVComputeThreadThree() );
		
		//a->join();
		//b->join();
		c->join();
		
		exit( 0 );
		
	} catch( CVException &e ) {
		std::cout << e.what() << std::endl;
		exit( 1 );
	} catch( ... ) {
		std::cout << "Unknown exception occurred!" << std::endl;
		exit( 2 );
	}
}