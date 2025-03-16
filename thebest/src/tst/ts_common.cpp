#include "ts_common.h"

#include <iostream>

namespace TsCommon
{

void
outputTestInfo(std::string msg)
{
   std::cout << "INFO: " << msg << "\n";
}

void
outputTestError(std::string msg)
{
   std::cout << "ERROR: " << msg << "\n";
}

void
outputOverallResult(bool success)
{
   constexpr const char* MESSAGE[] = { "FAILURE: At least one test didn't pass", "SUCCESS: All tests passed" };
   std::cout << "\n" << MESSAGE[success] << "\n";
}

void
outputTestResult(bool success, std::string testName)
{
   constexpr const char* MESSAGE[] = { "FAILED ", "SUCCESS" };
   std::cout << MESSAGE[success] << ": " << testName << "\n";
}

} // TsCommon
