//
// SharedMemoryImpl.h
//
// $Id: //poco/1.3/Foundation/include/Poco/SharedMemory_POSIX.h#2 $
//
// Library: Foundation
// Package: Processes
// Module:  SharedMemoryImpl
//
// Definition of the SharedMemoryImpl class.
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
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


#ifndef Foundation_SharedMemoryImpl_INCLUDED
#define Foundation_SharedMemoryImpl_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/SharedMemory.h"
#include "Poco/RefCountedObject.h"


namespace Poco {


class Foundation_API SharedMemoryImpl: public RefCountedObject
	/// Shared memory implementation for POSIX platforms.
{
public:
	SharedMemoryImpl(const std::string& name, std::size_t size, SharedMemory::AccessMode mode, const void* addrHint, bool server);
		/// Creates or connects to a shared memory object with the given name.
		///
		/// For maximum portability, name should be a valid Unix filename and not
		/// contain any slashes or backslashes.
		///
		/// An address hint can be passed to the system, specifying the desired
		/// start address of the shared memory area. Whether the hint
		/// is actually honored is, however, up to the system. Windows platform
		/// will generally ignore the hint.
		///
		/// If server is set to false, the shared memory region will be unlinked
		/// by calling shm_unlink when the SharedMemory object is destroyed.

	SharedMemoryImpl(const Poco::File& file, SharedMemory::AccessMode mode, const void* addrHint);
		/// Maps the entire contents of file into a shared memory segment.
		///
		/// An address hint can be passed to the system, specifying the desired
		/// start address of the shared memory area. Whether the hint
		/// is actually honored is, however, up to the system. Windows platform
		/// will generally ignore the hint.

	char* begin() const;
		/// Returns the start address of the shared memory segment.

	char* end() const;
		/// Returns the one-past-end end address of the shared memory segment. 

protected:
	void map(const void* addrHint);
		/// Maps the shared memory object.

	void unmap();
		/// Unmaps the shared memory object.

	void close();
		/// Releases the handle for the shared memory segment.

	~SharedMemoryImpl();
		/// Destroys the SharedMemoryImpl.

private:
	SharedMemoryImpl();
	SharedMemoryImpl(const SharedMemoryImpl&);
	SharedMemoryImpl& operator = (const SharedMemoryImpl&);

	std::size_t _size;
	int         _fd;
	char*       _address;
	SharedMemory::AccessMode _access;
	std::string _name;
	bool        _fileMapped;
	bool        _server;
};


//
// inlines
//
inline char* SharedMemoryImpl::begin() const
{
	return _address;
}


inline char* SharedMemoryImpl::end() const
{
	return _address + _size;
}


} // namespace Poco


#endif // Foundation_SharedMemoryImpl_INCLUDED
