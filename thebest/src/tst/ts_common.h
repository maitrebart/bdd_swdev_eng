#ifndef THEBEST_TS_COMMON_H
#define THEBEST_TS_COMMON_H

#include <iostream>

namespace TsCommon
{

void outputTestInfo(std::string msg);
void outputTestError(std::string msg);
void outputOverallResult(bool success);
void outputTestResult(bool success, std::string testName);

} // TsCommon

#endif // THEBEST_TS_COMMON_H
