/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2015 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/MIT/.
 */

// ----------------------------------------------------------------------------

#if defined(__ARM_EABI__)

// ----------------------------------------------------------------------------

#if defined(TRACE)

// ----------------------------------------------------------------------------

#if defined(HAVE_MICRO_OS_PLUS_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // HAVE_MICRO_OS_PLUS_CONFIG_H

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_USE_TRACE_ITM)

#include <micro-os-plus/diag/trace.h>

// TODO: Find a better way to include the ITM definitions (including
// the entire vendor header is overkill).
#include <micro-os-plus/device.h>

// ----------------------------------------------------------------------------

namespace micro_os_plus
{
  namespace trace
  {
    // ------------------------------------------------------------------------

    void
    initialize (void)
    {
      // For ITM no inits required.
      // The debug registers are set the JTAG software.
    }

    // ------------------------------------------------------------------------

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)

    // ITM is the ARM standard mechanism, running over SWD/SWO on Cortex-M3/M4
    // devices, and is the recommended setting, if available.
    //
    // The JLink probe and the GDB server fully support SWD/SWO
    // and the JLink Debugging plug-in enables it by default.
    // The current OpenOCD does not include support to parse the SWO stream,
    // so this configuration will not work on OpenOCD (will not crash, but
    // nothing will be displayed in the output console).

#if !defined(MICRO_OS_PLUS_INTEGER_TRACE_ITM_STIMULUS_PORT)
#define MICRO_OS_PLUS_INTEGER_TRACE_ITM_STIMULUS_PORT (0)
#endif

    ssize_t
    write (const void* buf, std::size_t nbyte)
    {
      if (buf == nullptr || nbyte == 0)
        {
          return 0;
        }

      const char* cbuf = (const char*)buf;

      for (size_t i = 0; i < nbyte; i++)
        {
          // Check if ITM or the stimulus port are not enabled.
          if (((ITM->TCR & ITM_TCR_ITMENA_Msk) == 0)
              || ((ITM->TER
                   & (1UL << MICRO_OS_PLUS_INTEGER_TRACE_ITM_STIMULUS_PORT))
                  == 0))
            {
              // Return the number of sent characters (may be 0).
              return (ssize_t)i;
            }

          // Wait until STIMx is ready...
          while (ITM->PORT[MICRO_OS_PLUS_INTEGER_TRACE_ITM_STIMULUS_PORT].u32
                 == 0)
            ;
          // then send data, one byte at a time
          ITM->PORT[MICRO_OS_PLUS_INTEGER_TRACE_ITM_STIMULUS_PORT].u8
              = (uint8_t) (*cbuf++);
        }

      // All characters successfully sent.
      return (ssize_t)nbyte;
    }

#else

#error "ITM available only on ARCH 7M"

#endif // defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)

  } // namespace trace
} // namespace micro_os_plus

#endif // defined(MICRO_OS_PLUS_USE_TRACE_ITM)

#endif // defined(TRACE)

// ----------------------------------------------------------------------------

#endif // defined(__ARM_EABI__)

// ----------------------------------------------------------------------------
