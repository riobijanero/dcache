/* soapStub.h
   Generated by gSOAP 2.2.3b from managerv1.h
   Copyright (C) 2001-2003 Genivia inc.
   All Rights Reserved.
*/
#ifndef soapStub_H
#define soapStub_H

/* Types With Custom (De)serializers: */

/* Enumerations */

/* Classes and Structs */

#ifndef _SOAP_tns__getResponse
#define _SOAP_tns__getResponse
class SOAP_CMAC tns__getResponse
{ public:
	class ns11__RequestStatus *_Result;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_ns11__RequestStatus
#define _SOAP_ns11__RequestStatus
class SOAP_CMAC ns11__RequestStatus
{ public:
	int requestId;
	char *type;
	char *state;
	char *submitTime;
	char *startTime;
	char *finishTime;
	int estTimeToStart;
	class ArrayOfRequestFileStatus *fileStatuses;
	char *errorMessage;
	int retryDeltaTime;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_tns__advisoryDeleteResponse
#define _SOAP_tns__advisoryDeleteResponse
class SOAP_CMAC tns__advisoryDeleteResponse
{ public:
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_ArrayOfRequestFileStatus
#define _SOAP_ArrayOfRequestFileStatus
/* Array of ns11:RequestFileStatus schema type: */
class SOAP_CMAC ArrayOfRequestFileStatus
{ public:
	class ns11__RequestFileStatus *__ptr;
	int __size;
	int __offset;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_ArrayOfFileMetaData
#define _SOAP_ArrayOfFileMetaData
/* Array of ns11:FileMetaData schema type: */
class SOAP_CMAC ArrayOfFileMetaData
{ public:
	class ns11__FileMetaData *__ptr;
	int __size;
	int __offset;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_ns11__FileMetaData
#define _SOAP_ns11__FileMetaData
class SOAP_CMAC ns11__FileMetaData
{ public:
	char *SURL;
	LONG64 size;
	char *owner;
	char *group;
	int permMode;
	char *checksumType;
	char *checksumValue;
	bool isPinned;
	bool isPermanent;
	bool isCached;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_ArrayOfstring
#define _SOAP_ArrayOfstring
/* Array of xsd:string schema type: */
class SOAP_CMAC ArrayOfstring
{ public:
	char **__ptr;
	int __size;
	int __offset;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_ArrayOflong
#define _SOAP_ArrayOflong
/* Array of xsd:long schema type: */
class SOAP_CMAC ArrayOflong
{ public:
	LONG64 *__ptr;
	int __size;
	int __offset;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_tns__putResponse
#define _SOAP_tns__putResponse
class SOAP_CMAC tns__putResponse
{ public:
	ns11__RequestStatus *_Result;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_ns11__RequestFileStatus
#define _SOAP_ns11__RequestFileStatus
class SOAP_CMAC ns11__RequestFileStatus
{ public:
	char *SURL;
	LONG64 size;
	char *owner;
	char *group;
	int permMode;
	char *checksumType;
	char *checksumValue;
	bool isPinned;
	bool isPermanent;
	bool isCached;
	char *state;
	int fileId;
	char *TURL;
	int estSecondsToStart;
	char *sourceFilename;
	char *destFilename;
	int queueOrder;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_tns__mkPermanentResponse
#define _SOAP_tns__mkPermanentResponse
class SOAP_CMAC tns__mkPermanentResponse
{ public:
	ns11__RequestStatus *_Result;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_tns__copyResponse
#define _SOAP_tns__copyResponse
class SOAP_CMAC tns__copyResponse
{ public:
	ns11__RequestStatus *_Result;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_tns__getEstGetTimeResponse
#define _SOAP_tns__getEstGetTimeResponse
class SOAP_CMAC tns__getEstGetTimeResponse
{ public:
	ns11__RequestStatus *_Result;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_tns__getEstPutTimeResponse
#define _SOAP_tns__getEstPutTimeResponse
class SOAP_CMAC tns__getEstPutTimeResponse
{ public:
	ns11__RequestStatus *_Result;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_tns__pinResponse
#define _SOAP_tns__pinResponse
class SOAP_CMAC tns__pinResponse
{ public:
	ns11__RequestStatus *_Result;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_tns__pingResponse
#define _SOAP_tns__pingResponse
class SOAP_CMAC tns__pingResponse
{ public:
	bool _Result;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_tns__getFileMetaDataResponse
#define _SOAP_tns__getFileMetaDataResponse
class SOAP_CMAC tns__getFileMetaDataResponse
{ public:
	ArrayOfFileMetaData *_Result;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_tns__getRequestStatusResponse
#define _SOAP_tns__getRequestStatusResponse
class SOAP_CMAC tns__getRequestStatusResponse
{ public:
	ns11__RequestStatus *_Result;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_tns__getProtocolsResponse
#define _SOAP_tns__getProtocolsResponse
class SOAP_CMAC tns__getProtocolsResponse
{ public:
	ArrayOfstring *_Result;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_tns__setFileStatusResponse
#define _SOAP_tns__setFileStatusResponse
class SOAP_CMAC tns__setFileStatusResponse
{ public:
	ns11__RequestStatus *_Result;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_tns__unPinResponse
#define _SOAP_tns__unPinResponse
class SOAP_CMAC tns__unPinResponse
{ public:
	ns11__RequestStatus *_Result;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_ArrayOfboolean
#define _SOAP_ArrayOfboolean
/* Array of xsd:boolean schema type: */
class SOAP_CMAC ArrayOfboolean
{ public:
	bool *__ptr;
	int __size;
	int __offset;
	virtual void soap_default(struct soap*); 
	virtual void soap_serialize(struct soap*) const;
	virtual void soap_mark(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*); 
};
#endif

#ifndef _SOAP_tns__ping
#define _SOAP_tns__ping
struct tns__ping
{
};
#endif

#ifndef _SOAP_tns__getEstPutTime
#define _SOAP_tns__getEstPutTime
struct tns__getEstPutTime
{
	ArrayOfstring *arg0;
	ArrayOfstring *arg1;
	ArrayOflong *arg2;
	ArrayOfboolean *arg3;
	ArrayOfstring *arg4;
};
#endif

#ifndef _SOAP_tns__put
#define _SOAP_tns__put
struct tns__put
{
	ArrayOfstring *arg0;
	ArrayOfstring *arg1;
	ArrayOflong *arg2;
	ArrayOfboolean *arg3;
	ArrayOfstring *arg4;
};
#endif

#ifndef _SOAP_tns__getRequestStatus
#define _SOAP_tns__getRequestStatus
struct tns__getRequestStatus
{
	int arg0;
};
#endif

#ifndef _SOAP_tns__copy
#define _SOAP_tns__copy
struct tns__copy
{
	ArrayOfstring *arg0;
	ArrayOfstring *arg1;
	ArrayOfboolean *arg2;
};
#endif

#ifndef _SOAP_tns__getProtocols
#define _SOAP_tns__getProtocols
struct tns__getProtocols
{
};
#endif

#ifndef _SOAP_tns__getEstGetTime
#define _SOAP_tns__getEstGetTime
struct tns__getEstGetTime
{
	ArrayOfstring *arg0;
	ArrayOfstring *arg1;
};
#endif

#ifndef _SOAP_tns__advisoryDelete
#define _SOAP_tns__advisoryDelete
struct tns__advisoryDelete
{
	ArrayOfstring *arg0;
};
#endif

#ifndef _SOAP_tns__pin
#define _SOAP_tns__pin
struct tns__pin
{
	ArrayOfstring *arg0;
};
#endif

#ifndef _SOAP_tns__unPin
#define _SOAP_tns__unPin
struct tns__unPin
{
	ArrayOfstring *arg0;
	int arg1;
};
#endif

#ifndef _SOAP_tns__setFileStatus
#define _SOAP_tns__setFileStatus
struct tns__setFileStatus
{
	int arg0;
	int arg1;
	char *arg2;
};
#endif

#ifndef _SOAP_tns__mkPermanent
#define _SOAP_tns__mkPermanent
struct tns__mkPermanent
{
	ArrayOfstring *arg0;
};
#endif

#ifndef _SOAP_tns__get
#define _SOAP_tns__get
struct tns__get
{
	ArrayOfstring *arg0;
	ArrayOfstring *arg1;
};
#endif

#ifndef _SOAP_tns__getFileMetaData
#define _SOAP_tns__getFileMetaData
struct tns__getFileMetaData
{
	ArrayOfstring *arg0;
};
#endif

#ifndef _SOAP_SOAP_ENV__Header
#define _SOAP_SOAP_ENV__Header
/* SOAP Header: */
struct SOAP_ENV__Header
{
	void *dummy;	/* transient */
};
#endif

#ifndef _SOAP_SOAP_ENV__Code
#define _SOAP_SOAP_ENV__Code
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
	char *SOAP_ENV__Value;
	char *SOAP_ENV__Node;
	char *SOAP_ENV__Role;
};
#endif

#ifndef _SOAP_SOAP_ENV__Fault
#define _SOAP_SOAP_ENV__Fault
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
	char *faultcode;
	char *faultstring;
	char *faultactor;
	char *detail;
	struct SOAP_ENV__Code *SOAP_ENV__Code;
	char *SOAP_ENV__Reason;
	char *SOAP_ENV__Detail;
};
#endif

/* Typedefs */
typedef char *xsd__string;
typedef int xsd__int;
typedef char *xsd__dateTime;
typedef LONG64 xsd__long;
typedef bool xsd__boolean;
typedef bool tns__Boolean;
typedef LONG64 tns__Long;
typedef int tns__Integer;

/* Variables */

/* Remote Methods */

SOAP_FMAC1 int SOAP_FMAC2 tns__ping(struct soap*, tns__pingResponse *);

SOAP_FMAC1 int SOAP_FMAC2 tns__getEstPutTime(struct soap*, ArrayOfstring *, ArrayOfstring *, ArrayOflong *, ArrayOfboolean *, ArrayOfstring *, tns__getEstPutTimeResponse *);

SOAP_FMAC1 int SOAP_FMAC2 tns__put(struct soap*, ArrayOfstring *, ArrayOfstring *, ArrayOflong *, ArrayOfboolean *, ArrayOfstring *, tns__putResponse *);

SOAP_FMAC1 int SOAP_FMAC2 tns__getRequestStatus(struct soap*, int, tns__getRequestStatusResponse *);

SOAP_FMAC1 int SOAP_FMAC2 tns__copy(struct soap*, ArrayOfstring *, ArrayOfstring *, ArrayOfboolean *, tns__copyResponse *);

SOAP_FMAC1 int SOAP_FMAC2 tns__getProtocols(struct soap*, tns__getProtocolsResponse *);

SOAP_FMAC1 int SOAP_FMAC2 tns__getEstGetTime(struct soap*, ArrayOfstring *, ArrayOfstring *, tns__getEstGetTimeResponse *);

SOAP_FMAC1 int SOAP_FMAC2 tns__advisoryDelete(struct soap*, ArrayOfstring *, tns__advisoryDeleteResponse *);

SOAP_FMAC1 int SOAP_FMAC2 tns__pin(struct soap*, ArrayOfstring *, tns__pinResponse *);

SOAP_FMAC1 int SOAP_FMAC2 tns__unPin(struct soap*, ArrayOfstring *, int, tns__unPinResponse *);

SOAP_FMAC1 int SOAP_FMAC2 tns__setFileStatus(struct soap*, int, int, char *, tns__setFileStatusResponse *);

SOAP_FMAC1 int SOAP_FMAC2 tns__mkPermanent(struct soap*, ArrayOfstring *, tns__mkPermanentResponse *);

SOAP_FMAC1 int SOAP_FMAC2 tns__get(struct soap*, ArrayOfstring *, ArrayOfstring *, tns__getResponse *);

SOAP_FMAC1 int SOAP_FMAC2 tns__getFileMetaData(struct soap*, ArrayOfstring *, tns__getFileMetaDataResponse *);

/* Stubs */

SOAP_FMAC1 int SOAP_FMAC2 soap_call_tns__ping(struct soap*, const char*, const char*, tns__pingResponse *);

SOAP_FMAC1 int SOAP_FMAC2 soap_call_tns__getEstPutTime(struct soap*, const char*, const char*, ArrayOfstring *, ArrayOfstring *, ArrayOflong *, ArrayOfboolean *, ArrayOfstring *, tns__getEstPutTimeResponse *);

SOAP_FMAC1 int SOAP_FMAC2 soap_call_tns__put(struct soap*, const char*, const char*, ArrayOfstring *, ArrayOfstring *, ArrayOflong *, ArrayOfboolean *, ArrayOfstring *, tns__putResponse *);

SOAP_FMAC1 int SOAP_FMAC2 soap_call_tns__getRequestStatus(struct soap*, const char*, const char*, int, tns__getRequestStatusResponse *);

SOAP_FMAC1 int SOAP_FMAC2 soap_call_tns__copy(struct soap*, const char*, const char*, ArrayOfstring *, ArrayOfstring *, ArrayOfboolean *, tns__copyResponse *);

SOAP_FMAC1 int SOAP_FMAC2 soap_call_tns__getProtocols(struct soap*, const char*, const char*, tns__getProtocolsResponse *);

SOAP_FMAC1 int SOAP_FMAC2 soap_call_tns__getEstGetTime(struct soap*, const char*, const char*, ArrayOfstring *, ArrayOfstring *, tns__getEstGetTimeResponse *);

SOAP_FMAC1 int SOAP_FMAC2 soap_call_tns__advisoryDelete(struct soap*, const char*, const char*, ArrayOfstring *, tns__advisoryDeleteResponse *);

SOAP_FMAC1 int SOAP_FMAC2 soap_call_tns__pin(struct soap*, const char*, const char*, ArrayOfstring *, tns__pinResponse *);

SOAP_FMAC1 int SOAP_FMAC2 soap_call_tns__unPin(struct soap*, const char*, const char*, ArrayOfstring *, int, tns__unPinResponse *);

SOAP_FMAC1 int SOAP_FMAC2 soap_call_tns__setFileStatus(struct soap*, const char*, const char*, int, int, char *, tns__setFileStatusResponse *);

SOAP_FMAC1 int SOAP_FMAC2 soap_call_tns__mkPermanent(struct soap*, const char*, const char*, ArrayOfstring *, tns__mkPermanentResponse *);

SOAP_FMAC1 int SOAP_FMAC2 soap_call_tns__get(struct soap*, const char*, const char*, ArrayOfstring *, ArrayOfstring *, tns__getResponse *);

SOAP_FMAC1 int SOAP_FMAC2 soap_call_tns__getFileMetaData(struct soap*, const char*, const char*, ArrayOfstring *, tns__getFileMetaDataResponse *);

/* Skeletons */

SOAP_FMAC1 int SOAP_FMAC2 soap_serve(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_serve_tns__ping(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_serve_tns__getEstPutTime(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_serve_tns__put(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_serve_tns__getRequestStatus(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_serve_tns__copy(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_serve_tns__getProtocols(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_serve_tns__getEstGetTime(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_serve_tns__advisoryDelete(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_serve_tns__pin(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_serve_tns__unPin(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_serve_tns__setFileStatus(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_serve_tns__mkPermanent(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_serve_tns__get(struct soap*);

SOAP_FMAC1 int SOAP_FMAC2 soap_serve_tns__getFileMetaData(struct soap*);
#endif

/* end of soapStub.h */
