//
// SampleApp.cpp
//
// $Id: //poco/1.3/Util/samples/SampleApp/src/SampleApp.cpp#1 $
//
// This sample demonstrates the Application class.
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


#include "Poco/Util/Application.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Util/AbstractConfiguration.h"
#include "Poco/AutoPtr.h"
#include <iostream>


using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;
using Poco::Util::AbstractConfiguration;
using Poco::Util::OptionCallback;
using Poco::AutoPtr;


class SampleApp: public Application
	/// This sample demonstrates some of the features of the Util::Application class,
	/// such as configuration file handling and command line arguments processing.
	///
	/// Try SampleApp --help (on Unix platforms) or SampleApp /help (elsewhere) for
	/// more information.
{
public:
	SampleApp(): _helpRequested(false)
	{
	}

protected:	
	void initialize(Application& self)
	{
		loadConfiguration(); // load default configuration files, if present
		Application::initialize(self);
		// add your own initialization code here
	}
	
	void uninitialize()
	{
		// add your own uninitialization code here
		Application::uninitialize();
	}
	
	void reinitialize(Application& self)
	{
		Application::reinitialize(self);
		// add your own reinitialization code here
	}
	
	void defineOptions(OptionSet& options)
	{
		Application::defineOptions(options);

		options.addOption(
			Option("help", "h", "display help information on command line arguments")
				.required(false)
				.repeatable(false)
				.callback(OptionCallback<SampleApp>(this, &SampleApp::handleHelp)));

		options.addOption(
			Option("define", "D", "define a configuration property")
				.required(false)
				.repeatable(true)
				.argument("name=value")
				.callback(OptionCallback<SampleApp>(this, &SampleApp::handleDefine)));
				
		options.addOption(
			Option("config-file", "f", "load configuration data from a file")
				.required(false)
				.repeatable(true)
				.argument("file")
				.callback(OptionCallback<SampleApp>(this, &SampleApp::handleConfig)));

		options.addOption(
			Option("bind", "b", "bind option value to test.property")
				.required(false)
				.repeatable(false)
				.argument("value")
				.binding("test.property"));
	}
	
	void handleHelp(const std::string& name, const std::string& value)
	{
		_helpRequested = true;
		displayHelp();
		stopOptionsProcessing();
	}
	
	void handleDefine(const std::string& name, const std::string& value)
	{
		defineProperty(value);
	}
	
	void handleConfig(const std::string& name, const std::string& value)
	{
		loadConfiguration(value);
	}
		
	void displayHelp()
	{
		HelpFormatter helpFormatter(options());
		helpFormatter.setCommand(commandName());
		helpFormatter.setUsage("OPTIONS");
		helpFormatter.setHeader("A sample application that demonstrates some of the features of the Poco::Util::Application class.");
		helpFormatter.format(std::cout);
	}
	
	void defineProperty(const std::string& def)
	{
		std::string name;
		std::string value;
		std::string::size_type pos = def.find('=');
		if (pos != std::string::npos)
		{
			name.assign(def, 0, pos);
			value.assign(def, pos + 1, def.length() - pos);
		}
		else name = def;
		config().setString(name, value);
	}

	int main(const std::vector<std::string>& args)
	{
		if (!_helpRequested)
		{
			logger().information("Arguments to main():");
			for (std::vector<std::string>::const_iterator it = args.begin(); it != args.end(); ++it)
			{
				logger().information(*it);
			}
			logger().information("Application properties:");
			printProperties("");
		}
		return Application::EXIT_OK;
	}
	
	void printProperties(const std::string& base)
	{
		AbstractConfiguration::Keys keys;
		config().keys(base, keys);
		if (keys.empty())
		{
			if (config().hasProperty(base))
			{
				std::string msg;
				msg.append(base);
				msg.append(" = ");
				msg.append(config().getString(base));
				logger().information(msg);
			}
		}
		else
		{
			for (AbstractConfiguration::Keys::const_iterator it = keys.begin(); it != keys.end(); ++it)
			{
				std::string fullKey = base;
				if (!fullKey.empty()) fullKey += '.';
				fullKey.append(*it);
				printProperties(fullKey);
			}
		}
	}
	
private:
	bool _helpRequested;
};


POCO_APP_MAIN(SampleApp)
