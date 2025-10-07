/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2015-2025 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/mit.
 */

#if defined(__ARM_EABI__)

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#if defined(MICRO_OS_PLUS_INCLUDE_STARTUP)

#include <micro-os-plus/startup/hooks.h>
#include <micro-os-plus/device.h>

// ----------------------------------------------------------------------------

/**
 * @details
 * This is the default implementation for the second hardware
 * initialisation routine.
 *
 * It is called from `_start()`, right after DATA & BSS init, before
 * the static constructors.
 *
 * The application can and should
 * redefine it for more complex cases that
 * require custom inits (before constructors), otherwise these inits can
 * be done in main().
 */
void __attribute__ ((weak)) micro_os_plus_startup_initialize_hardware (void)
{
  // Call the CMSIS system clock routine to store the clock frequency
  // in the SystemCoreClock global RAM location.
  SystemCoreClockUpdate ();
}

#endif // defined(MICRO_OS_PLUS_INCLUDE_STARTUP)

// ----------------------------------------------------------------------------

#endif // defined(__ARM_EABI__)

// ----------------------------------------------------------------------------
