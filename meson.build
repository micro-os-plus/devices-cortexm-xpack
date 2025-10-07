# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ project (https://micro-os-plus.github.io/).
# Copyright (c) 2022-2025 Liviu Ionescu. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/mit.
#
# -----------------------------------------------------------------------------

# This file is intended to be consumed by applications with:
#
# `subdir('xpacks/@micro-os-plus/devices-cortexm')`
#
# The result is a dependency that can be referred as:
#
# `dependencies: [micro_os_plus_devices_cortexm_dependency],`

# Note: the meson configuration is provided only as a proof of concept,
# for production it might need some refinements.

# -----------------------------------------------------------------------------

message('Processing xPack @micro-os-plus/devices-cortexm...')

# https://mesonbuild.com/Reference-manual_functions.html#declare_dependency
micro_os_plus_devices_cortexm_dependency = declare_dependency(
  include_directories: include_directories(
    'include',
  ),
  sources: files(
    'src/diag/trace-itm.cpp',

    'src/startup/initialize-hardware-early.c',
    'src/startup/initialize-hardware.c',
    'src/startup/initialize-interrupts-stack.cpp',
    'src/startup/terminate.cpp',

    'src/exception-handlers.cpp',
  ),
  compile_args: [
    # None.
  ],
  dependencies: [
    micro_os_plus_semihosting_dependency
  ]
)

message('+ -I include')
message('> micro_os_plus_devices_cortexm_dependency')

# -----------------------------------------------------------------------------
