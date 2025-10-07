/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2025 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/mit.
 */

#if (!(defined(__APPLE__) || defined(__linux__) || defined(__unix__))) \
    || defined(__DOXYGEN__)

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_RTOS)

// ----------------------------------------------------------------------------

#include <micro-os-plus/startup/hooks.h>
#include <micro-os-plus/rtos.h>

// ----------------------------------------------------------------------------

using namespace micro_os_plus;

// ----------------------------------------------------------------------------

void
micro_os_plus_startup_initialize_interrupts_stack (void* stack_begin_address,
                                                   size_t stack_size_bytes)
{
  trace::printf ("%s(%p,%u)\n", __func__, stack_begin_address,
                 stack_size_bytes);

  rtos::interrupts::stack ()->set (
      static_cast<rtos::thread::stack::element_t*> (stack_begin_address),
      stack_size_bytes);
}

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_INCLUDE_RTOS)

// ----------------------------------------------------------------------------

#endif // ! Unix

// ----------------------------------------------------------------------------
