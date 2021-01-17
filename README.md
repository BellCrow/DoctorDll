# DoctorDll
The next version of my PeToolkit under a new name, as the old project wasn't a toolkit, but more a single tool.
The intention is to have a little framework, that is flexible and eases manipulation of processes and images 
in the Win32Api/PeImage world.

# What am I looking at?
Some time ago I've created a "stealthy" (stealthy in the way, that no LoadLibrary call is needed in the target process)
DLL injector, as a learning project. The project is called PeToolkitV2 and is also availabe on this github account.

# RoadMap
The following features are to be implemented in this software (All of these feature are only going to be implemented for 64 bit unmanaged Images/Processes until I decide otherwise)
## Logging
* [x] Basic logging functionality for output on the console 
* [x] Logging should be capable of having different indentation levels to facilitate rudimentary "grouping" of outputs, that logically are in a hierarchy 

## Memory Interaction
* Basic abstraction/implementation to allow manipulation of memory (be it on disk, in ram, own process or another process or even over network)
* * [ ] Operations like reading/writing bits/bytes, shorts, int32, int64, strings ... 
* * [ ] The ability to define a constant offset from which the operations target addresses are calculated from 

## Image Query
* [ ] Ability to query information of an image (be it in local memory or remote memory, is to be build upon the before defined memory abstraction)
* [ ] Loading images from persistent memory into local process ram (Images will always be mapped during loading)

Image information
* * [ ] Dos Header
* * [ ] Pe Header
* * [ ] Section Table
* * [ ] Data directory table
* * [ ] Import address table
* * [ ] Export address table
* * [ ] Relocation table

## Process Interaction
Abstraction to query information about other processes
* *  [ ] Loaded modules (Base address, name, etc.)
* * [ ] Of these loaded modules all the information, that was described in the "Image Query" section of this document, is to be parseable too

* [ ] Abstraction for creation of execution units in the remote process (be it a call to CreateRemoteThread or some other custom implementation)
* [ ] Abstraction reading/writing of data from and to the remote process (be it a call to ReadMemory/WriteMemory or some other custom implementation)

## Image Manipulation
If an Image is to be injected into another process, we have to somehow modify the mapped dll in process local memory 
in order to make it viable to "live" in the remote space. Therefore the following needs to be possible:
* [ ] Ability to change absolute addresses defined by the relocation table in the loaded image.
* [ ] Ability to change the addresses for imported functions defined as in the Import Address Table (IAT).

## Misc
- [ ] There also needs to be shellcode in order to call the DLL Main function, with the corrrect arguments, after the Image has been transfered to the remote process.

## Documentation
I will try to add/update class diagrams as i see fit. For process description I will use [BPMN with the Camunda modeler](https://camunda.com/de/bpmn/free-bpmn-2-0-tool/)

# Disclaimer
This tool is intended for research purposes on my part. I just ask the reader not to use this tool with malicious intent.
On the other hand im not your parent, so I cant really stop you from doing that. 


So suit yourself.
