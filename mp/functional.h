//
// mp::functional
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
#ifndef MP_FUNCTIONAL_H__
#define MP_FUNCTIONAL_H__

#ifdef MP_FUNCTIONAL_BOOST
#include <boost/function.hpp>
#include <boost/bind.hpp>
namespace mp {
	using boost::function;
	using boost::bind;
	namespace placeholders { }
}
#else
#include <functional>
namespace mp {
	using std::function;
	using std::bind;
	namespace placeholders {
		using namespace std::placeholders;
	}
}
#endif

#endif /* mp/functional.h */

