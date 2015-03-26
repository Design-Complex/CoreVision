/*
 *  CVTypes.h
 *  CoreVision
 *
 *  Created by Rob Dotson on 4/3/08.
 *  Copyright 2008 Rob Dotson, Vision Core Grant, Center for Neural Science, New York University. All rights reserved.
 *
 */

#ifndef _CVTypes_
#define _CVTypes_

#include <sys/types.h>
#include <string>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

#include <ApplicationServices/ApplicationServices.h>

#ifdef __cplusplus
extern "C" {
#endif

	typedef size_t CVIndex;
	
#ifdef __cplusplus
}
#endif

#define CVStandardTypes( Class ) \
template class Class<int8_t>; \
template class Class<uint8_t>; \
template class Class<int16_t>; \
template class Class<uint16_t>; \
template class Class<int32_t>; \
template class Class<uint32_t>; \
template class Class<int64_t>; \
template class Class<uint64_t>; \
template class Class<float>; \
template class Class<double>; \
template class Class<long double>; \
template class Class<CVIndex>; \



#include "CVRTTI.h"

//typedef std::string CVString;
//typedef std::tr1::match_results<const char *> CVRegexMatchResult;

#endif // _CVTypes_
