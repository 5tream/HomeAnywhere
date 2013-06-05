Feature Requirements 
====================
（*in order of decreasing precendences*）
--------------------
## Server
1. *RS-01*  
Any IoT devices(e。g. switcher, air conditioner, smart phone, etc.) be described in an unified form.
	* Some modeling works should be done in the very first.
	* Database should be created for restoring devices' information
2. *RS-02*  
HTTP based server
	* Support POST, GET, PUT, DELETE methods.
	* Support pull/push
3. *RS-03*  
Structured and streamed data be supported. 
	* Structured data are transferred within *HTTP-like* protocol and represented as *XML* and *JSON*.
	* Streamed data especially video/audio stream are  transferred within *rtmp*.
4. *RS-04*  
Ability to host rtmp streams for publish subscription
	* User client (e。g. browser, mobile phone, etc.) can subscribe to an specified rtmp stream for displaying.
	* Every stream should be identified by an unique identifier.
5. *RS-05"  
RESTful api supported.
	* Device, data are treated as *resource*
	* Each device can be accessed via URI.

## Client
1. *RC-01*  
Ability to connect to the server using HTTP connection
	* Ability to perform device registering, data posting, command handling.
	* Ability to stream video/audio and transfer video/audio stream using rtmp.
