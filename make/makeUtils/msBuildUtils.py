import os
from makeUtils import binaryUtils
from makeUtils import msBuildUtils
from makeUtils import returnCodes

# since Visual studio 15.2, there is an executable, under the below given path
# the vswhere.exe can be used to get a path, to the latest installed version of msbuild.exe on the machine
# the existance of this path is guaranteed by microsoft to be constant
# see https://github.com/Microsoft/vswhere/wiki/Installing

__VsWherePath = os.path.join(os.path.expandvars('%ProgramFiles(x86)%'), r'Microsoft Visual Studio/Installer/vswhere.exe')
__ArgumentsForVsWhereToFindMsBuildExe = r"-latest -products * -requires Microsoft.Component.MSBuild -find MsBuild\**\Bin\MsBuild.exe"
__MsBuildNotFoundConstant = ""


#These are the default release build configuration parameters for ms build
__buildConfig = "release"
__platformConfig = "x64"
__maxCpuConfig = 4

__buildConfigParam = f'/p:Configuration="{__buildConfig}"'
__platformConfigParam = f'/p:Platform="{__platformConfig}"'
__cpuConfigParam = f'/maxcpucount:{__maxCpuConfig}'

__restoreNugetPackageParam='/r'

__rebuildFlagParam='/t:rebuild'
#end default configuration

'''
Will build the file at the given path with ms build using the default parameters specified in this file.
These parameters should suffice for building any csharp application in release mode.

If the return code of the msbuild exe is anthing other than the succes code, that is communicated to the caller with an exception containing the return code.
'''
def buildWithDefaultReleaseParameters(pathToBuildTarget):
    msBuildPath = msBuildUtils.getPathToLatestMsBuildExe()
    msBuildArguments = f"{__buildConfigParam} {__platformConfigParam} {__cpuConfigParam} {__restoreNugetPackageParam} {__rebuildFlagParam} {pathToBuildTarget}"
    (returnCode,_) = binaryUtils.callExeWithArguments(msBuildPath,msBuildArguments,False)
    if (not (returnCode == returnCodes.ExitSuccessCode)):
        raise RuntimeError(f"Ms build exe returned with error code {returnCode}")

'''
Returns the absolute path to the latest MsBuild exe, that can be found on the executing  machine using the vsWhere executeable.
'''
def getPathToLatestMsBuildExe():
    if(not os.path.exists(__VsWherePath)):
        raise FileNotFoundError(
            "Could not find the vswhere.exe used to locate the msbuild.exe under the path. The vswhere.exe was excpected under the path " + __VsWherePath)

    (errorCode, stdOutOfCall) = binaryUtils.callExeWithArguments(__VsWherePath, __ArgumentsForVsWhereToFindMsBuildExe,True)
    if(errorCode != 0):
        raise RuntimeError(f"The vswhere.exe returned error code {errorCode}. StdOut was: {stdOutOfCall}")
    # the array access at the end removes the last character.(called "array slicing")
    # for some reason there is always a \n at the end of the returned path and here we cut that off.
    msBuildPath = stdOutOfCall[:-1 or None]

    if(msBuildPath == __MsBuildNotFoundConstant):
        raise FileNotFoundError(
            "Could not find any installed MSBuild versions")
    return msBuildPath