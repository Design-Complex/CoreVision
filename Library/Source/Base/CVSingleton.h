/*
 *  CVSingleton.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 9/25/09.
 *  Copyright 2009 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVSingleton_
#define _CVSingleton_

#include "CVString.h"
#include "CVLockable.h"
#include "CVGuard.h"

#define CVSingletonDeclare( TypeName ) \
	private: \
		CVPrivateConstructors( TypeName ); \
		static TypeName * sharedInstance_; \
		static CVMutex lock_; \
	public: \
		virtual ~TypeName(); \
		static TypeName & sharedInstance(); \

	#define CVSingletonDefine( TypeName ) \
		TypeName * TypeName::sharedInstance_ = 0; \
		CVMutex TypeName::lock_; \
		TypeName & TypeName::sharedInstance() { \
			if( TypeName::sharedInstance_ == 0 ) { \
				CVMutexGuard guard( TypeName::lock_ ); \
				if( TypeName::sharedInstance_ == 0 ) \
				TypeName::sharedInstance_ = new TypeName(); \
			} \
			return *(TypeName::sharedInstance_); \
		} \

#endif // _CVSingleton_
