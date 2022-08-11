//
// mp::unordered
//
// Copyright (C) 2010 FURUHASHI Sadayuki
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

#ifndef MP_UNORDERED_H__
#define MP_UNORDERED_H__

#if defined(MP_UNORDERED_MAP_BOOST_ORG)
#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>
namespace mp {
	using boost::unordered_map;
	using boost::unordered_set;
	using boost::unordered_multimap;
	using boost::unordered_multiset;
	template <typename T> struct hash : public boost::hash<T> { };
}

#else
#include <unordered_map>
#include <unordered_set>
namespace mp {
	using std::unordered_map;
	using std::unordered_set;
	using std::unordered_multimap;
	using std::unordered_multiset;
	template <typename T> struct hash : public std::hash<T> { };
}

#endif

#endif /* mp/unordered.h */

