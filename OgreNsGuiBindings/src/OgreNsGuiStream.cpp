////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "OgreNsGuiStream.h"

#include <NsCore/ReflectionImplement.h>


using namespace Noesis;
using namespace Noesis::Core;


namespace Noesis
{
	namespace Gui
	{

		////////////////////////////////////////////////////////////////////////////////////////////////////
		OgreNsGuiStream::OgreNsGuiStream(Ogre::DataStreamPtr dataStream)
			: mDataStream(dataStream)
		{
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		OgreNsGuiStream::~OgreNsGuiStream()
		{
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		NsBool OgreNsGuiStream::CanSeek() const
		{
			return !mDataStream.isNull();
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		void OgreNsGuiStream::SetPosition(NsUInt64 pos)
		{
			if(!mDataStream.isNull())
			{
				mDataStream->seek((size_t)pos);
			}	
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		NsUInt64 OgreNsGuiStream::GetPosition() const
		{
			if(!mDataStream.isNull())
			{
				return mDataStream->tell();
			}	
			return 0;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		void OgreNsGuiStream::SetLength(NsUInt64 length)
		{
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		NsUInt64 OgreNsGuiStream::GetLength() const
		{
			if(!mDataStream.isNull())
			{
				return mDataStream->size();
			}	

			return 0;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		NsBool OgreNsGuiStream::CanRead() const
		{
			return !mDataStream.isNull() && mDataStream->isReadable();
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		void OgreNsGuiStream::Read(void* buffer, NsSize size)
		{
			if(!mDataStream.isNull())
			{
				mDataStream->read(buffer, size);
			}	
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		NsBool OgreNsGuiStream::CanWrite() const
		{
			return !mDataStream.isNull() && mDataStream->isWriteable();
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		void OgreNsGuiStream::Write(const void* buffer, NsSize size)
		{
			if(!mDataStream.isNull())
			{
				mDataStream->write(buffer, size);
			}	
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		void OgreNsGuiStream::Flush()
		{
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		void OgreNsGuiStream::Close()
		{
			if(!mDataStream.isNull())
			{
				mDataStream->close();
			}
		}

		NS_IMPLEMENT_REFLECTION(OgreNsGuiStream)
		{
			NsImpl<IStream>();
		}
	}
}