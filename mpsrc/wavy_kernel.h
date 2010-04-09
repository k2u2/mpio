//
// mpio wavy kernel
//
// Copyright (C) 2008-2010 FURUHASHI Sadayuki
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
#ifndef MP_WAVY_KERNEL_H__
#define MP_WAVY_KERNEL_H__

#include "pp.h"

#ifndef MP_WAVY_KERNEL
#  if   defined(HAVE_SYS_EPOLL_H)
#    define MP_WAVY_KERNEL epoll
#  elif defined(HAVE_SYS_EVENT_H)
#    define MP_WAVY_KERNEL kqueue
#  elif defined(HAVE_PORT_H)
#    define MP_WAVY_KERNEL eventport
#  else
#    if   defined(__linux__)
#      define MP_WAVY_KERNEL epoll
#    elif defined(__APPLE__) && defined(__MACH__)
#      define MP_WAVY_KERNEL kqueue
#    elif defined(__FreeBSD__) || defined(__NetBSD__)
#      define MP_WAVY_KERNEL kqueue
#    elif defined(__sun__)
#      define MP_WAVY_KERNEL eventport
#    else
#      define MP_WAVY_KERNEL select
#    endif
#  endif
#endif

#define MP_WAVY_KERNEL_HEADER(sys) \
	MP_PP_HEADER(., wavy_kernel_, sys, )

#ifndef MP_WAVY_KERNEL_BACKLOG_SIZE
#define MP_WAVY_KERNEL_BACKLOG_SIZE 1024
#endif

#include MP_WAVY_KERNEL_HEADER(MP_WAVY_KERNEL)

//static const short EVKERNEL_READ;
//static const short EVKERNEL_WRITE;
//
//class kernel {
//public:
//	kernel();
//	~kernel();
//
//	size_t max() const;
//
//	struct event;
//
//	int add_fd(int fd, short event);
//	int remove_fd(int fd, short event);
//
//	struct timer;
//	int create_timer(timer* tm, const timespec* value, const timespec* interval);
//	int add_timer(timer* tm);
//	int remove_timer(int ident);
//	static int read_timer(event e);
//
//	struct signal;
//	int create_signal(signal* sg, int signo);
//	int add_signal(signal* sg);
//	int remove_signal(int ident);
//	static int read_signal(event e);
//
//	int add_kernel(kernel* pt);
//	int ident() const;
//
//	struct backlog;
//	int wait(backlog* result);
//	int wait(backlog* result, int timeout_msec);
//	int reactivate(event e);
//	int remove(event e);
//};

#endif /* wavy_kernel.h */
