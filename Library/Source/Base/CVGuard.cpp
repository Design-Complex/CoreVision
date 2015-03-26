/*
 *  CVGuard.cpp
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/25/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#include "CVGuard.h"
#include "CVMutex.h"

using namespace CV;

//template <class LOCK>
//CVGuard<LOCK>::CVGuard( LOCK &lock )  : lock_( lock ) {
//	lock_.acquire();
//}
//
//template <class LOCK>
//CVGuard<LOCK>::~CVGuard() {
//	lock_.release();
//}
//
//template class CVGuard<CVMutex>;
