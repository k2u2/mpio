//
// mpio memory
//
// Copyright (C) 2008-2010 FURUHASHI Sadayuki
// Copyright (C) 2022 k2u2 at github.com
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.
//
#ifndef MP_MEMORY_H__
#define MP_MEMORY_H__

#ifdef MP_MEMORY_BOOST_ORG
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
//#include <boost/scoped_ptr.hpp>
namespace mp {
	using boost::shared_ptr;
	using boost::weak_ptr;
	//using boost::scoped_ptr;
	using boost::static_pointer_cast;
	using boost::dynamic_pointer_cast;
	using boost::enable_shared_from_this;
}
#else
#include <memory>
namespace mp {
	using std::shared_ptr;
	using std::weak_ptr;
	//using std::scoped_ptr;
	using std::static_pointer_cast;
	using std::dynamic_pointer_cast;
	using std::enable_shared_from_this;
}
#endif

#endif /* mp/memory.h */

