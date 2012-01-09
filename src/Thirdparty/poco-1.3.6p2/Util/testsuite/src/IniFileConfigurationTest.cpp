//
// IniFileConfigurationTest.cpp
//
// $Id: //poco/1.3/Util/testsuite/src/IniFileConfigurationTest.cpp#1 $
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#include "IniFileConfigurationTest.h"
#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"
#include "Poco/Util/IniFileConfiguration.h"
#include "Poco/AutoPtr.h"
#include "Poco/Exception.h"
#include <sstream>
#include <algorithm>


using Poco::Util::IniFileConfiguration;
using Poco::Util::AbstractConfiguration;
using Poco::AutoPtr;
using Poco::NotImplementedException;
using Poco::NotFoundException;


IniFileConfigurationTest::IniFileConfigurationTest(const std::string& name): CppUnit::TestCase(name)
{
}


IniFileConfigurationTest::~IniFileConfigurationTest()
{
}


void IniFileConfigurationTest::testLoad()
{
	static const std::string iniFile = 
		"; comment\n"
		"  ; comment  \n"
		"prop1=value1\n"
		"  prop2 = value2  \n"
		"[section1]\n"
		"prop1 = value3\r\n"
		"\tprop2=value4\r\n"
		";prop3=value7\r\n"
		"\n"
		"  [ section 2 ]\n"
		"prop1 = value 5\n"
		"\t   \n"
		"Prop2 = value6";
		
	std::istringstream istr(iniFile);	
	AutoPtr<IniFileConfiguration> pConf = new IniFileConfiguration(istr);
	
	assert (pConf->getString("prop1") == "value1");
	assert (pConf->getString("prop2") == "value2");
	assert (pConf->getString("section1.prop1") == "value3");
	assert (pConf->getString("Section1.Prop2") == "value4");
	assert (pConf->getString("section 2.prop1") == "value 5");
	assert (pConf->getString("section 2.prop2") == "value6");
	assert (pConf->getString("SECTION 2.PROP2") == "value6");
	
	AbstractConfiguration::Keys keys;
	pConf->keys(keys);
	assert (keys.size() == 4);
	assert (std::find(keys.begin(), keys.end(), "prop1") != keys.end());
	assert (std::find(keys.begin(), keys.end(), "prop2") != keys.end());
	assert (std::find(keys.begin(), keys.end(), "section1") != keys.end());
	assert (std::find(keys.begin(), keys.end(), "section 2") != keys.end());
	
	pConf->keys("Section1", keys);
	assert (keys.size() == 2);
	assert (std::find(keys.begin(), keys.end(), "prop1") != keys.end());
	assert (std::find(keys.begin(), keys.end(), "prop2") != keys.end());
	
	try
	{
		pConf->setString("foo", "bar");
		fail("Not supported - must throw");
	}
	catch (NotImplementedException&)
	{
	}
	
	try
	{
		std::string s = pConf->getString("foo");
		fail("No property - must throw");
	}
	catch (NotFoundException&)
	{
	}
}


void IniFileConfigurationTest::setUp()
{
}


void IniFileConfigurationTest::tearDown()
{
}


CppUnit::Test* IniFileConfigurationTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("IniFileConfigurationTest");

	CppUnit_addTest(pSuite, IniFileConfigurationTest, testLoad);

	return pSuite;
}
