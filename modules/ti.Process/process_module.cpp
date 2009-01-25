/**
 * Appcelerator Titanium - licensed under the Apache Public License 2
 * see LICENSE in the root folder for details on the license. 
 * Copyright (c) 2009 Appcelerator, Inc. All Rights Reserved.
 */
#include <kroll/kroll.h>
#include "process_module.h"
#include "process_test.h"

using namespace kroll;
using namespace ti;

namespace ti
{
	KROLL_MODULE(ProcessModule);
	
	void ProcessModule::Initialize()
	{
		// load our variables
		this->binding = new ProcessBinding(host->GetGlobalObject());

		// set our ti.Process
		SharedValue value = Value::NewObject(this->binding);
		host->GetGlobalObject()->Set("Process", value);
	}

	void ProcessModule::Destroy()
	{
	}
	
	void ProcessModule::Test()
	{
	  ProcessUnitTestSuite test;
	  test.Run(host);
	}
}
