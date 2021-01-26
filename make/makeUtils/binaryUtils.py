import subprocess

"""Calls an executeable with the given arguments
    returns the std output of the exe call as a string
    and the return code of the call as a tuple (errorCode, stdoutString)

    Keyword arguments:
    pathToExe -- the path to the exe
    argumentsAsString -- the arguments to call the exe with as a string
    shouldCaptureOutPut -- if set to true the stdout of the called exe is not printed to console but is returned in the tuple as the second value
    """
def callExeWithArguments(pathToExe, argumentsAsString, shouldCaptureOutPut):
    if(shouldCaptureOutPut):
        processFinishedStruct = subprocess.run(pathToExe + " " + argumentsAsString, universal_newlines=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE )
    else:
        processFinishedStruct = subprocess.run(pathToExe + " " + argumentsAsString, universal_newlines=True )

    stdoutRet = processFinishedStruct.stdout
    returnCode = processFinishedStruct.returncode
    return (returnCode,stdoutRet)