//
//  Copyright (C) 2010 by Haris Kurtagic
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of version 2.1 of the GNU Lesser
//  General Public License as published by the Free Software Foundation.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//

#ifndef _c_TestOdata_TopSkip_h
#define _c_TestOdata_TopSkip_h

#include "CppUnit/TestCase.h"
#include "c_GisHttpServer.h"

class c_TestOdata_TopSkip : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( c_TestOdata_TopSkip );
    CPPUNIT_TEST( TestTop );    
  CPPUNIT_TEST_SUITE_END();

public:
  c_TestOdata_TopSkip(void);
  ~c_TestOdata_TopSkip(void);
  
  //! \brief Set up context before running a test.
  virtual void setUp() ;

  //! Clean up after the test run.
  virtual void tearDown() ;
  
  void TestTop();
  
protected:
  c_GisHttpServer* m_GisHttpServer; 
    
};

#endif
