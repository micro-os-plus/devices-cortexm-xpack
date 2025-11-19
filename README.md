[![GitHub package.json version](https://img.shields.io/github/package-json/v/micro-os-plus/devices-cortexm-xpack)](https://github.com/micro-os-plus/devices-cortexm-xpack/blob/xpack/package.json)
[![GitHub tag (latest by date)](https://img.shields.io/github/v/tag/micro-os-plus/devices-cortexm-xpack)](https://github.com/micro-os-plus/devices-cortexm-xpack/tags/)
[![npm (scoped)](https://img.shields.io/npm/v/@micro-os-plus/devices-cortexm.svg?color=blue)](https://www.npmjs.com/package/@micro-os-plus/devices-cortexm/)
[![license](https://img.shields.io/github/license/micro-os-plus/devices-cortexm-xpack)](https://github.com/micro-os-plus/devices-cortexm-xpack/blob/xpack/LICENSE)
[![CI on Push](https://github.com/micro-os-plus/devices-cortexm-xpack/actions/workflows/ci.yml/badge.svg)](https://github.com/micro-os-plus/devices-cortexm-xpack/actions/workflows/ci.yml)

# A source code library with µOS++ Cortex-M definitions

Due to the CMSIS design, some Cortex-M architecture definitions are
available only via the vendor specific device headers, so they
cannot be located in the architecture package.

The project is hosted on GitHub as
[micro-os-plus/devices-cortexm-xpack](https://github.com/micro-os-plus/devices-cortexm-xpack).

## Maintainer info

This page is addressed to developers who plan to include this source
library into their own projects.

For maintainer info, please see the
[README-MAINTAINER](README-MAINTAINER.md) file.

## Install

As a source library xPack, the easiest way to add it to a project is via
**xpm**, but it can also be used as any Git project, for example as a submodule.

### Prerequisites

A recent [xpm](https://xpack.github.io/xpm/),
which is a portable [Node.js](https://nodejs.org/) command line application.

It is recommended to update to the latest version with:

```sh
npm install --global xpm@latest
```

For details please follow the instructions in the
[xPack install](https://xpack.github.io/install/) page.

### xpm

Note: the package will be available from npmjs.com at a later date.

For now, it can be installed from GitHub:

```sh
cd my-project
xpm init # Unless a package.json is already present

xpm install github:micro-os-plus/devices-cortexm-xpack
```

When ready, this package will be available as
[`@micro-os-plus/devices-cortexm`](https://www.npmjs.com/package/@micro-os-plus/devices-cortexm)
from the `npmjs.com` registry:

```sh
cd my-project
xpm init # Unless a package.json is already present

xpm install @micro-os-plus/devices-cortexm@latest

ls -l xpacks/@micro-os-plus/devices-cortexm
```

### Git submodule

If, for any reason, **xpm** is not available, the next recommended
solution is to link it as a Git submodule below an `xpacks` folder.

```sh
cd my-project
git init # Unless already a Git project
mkdir -p xpacks

git submodule add https://github.com/micro-os-plus/devices-cortexm-xpack.git \
  xpacks/micro-os-plus/devices-cortexm
```

## Branches

Apart from the unused `master` branch, there are two active branches:

- `xpack`, with the latest stable version (default)
- `xpack-development`, with the current development version

All development is done in the `xpack-development` branch, and contributions via
Pull Requests should be directed to this branch.

When new releases are published, the `xpack-development` branch is merged
into `xpack`.

## Developer info

TBD

### Build & integration info

The project is written in C++, and the tests are expected to be
written in C++ too (although there are no
major reasons to prevent adding C wrappers).

On embedded platforms, the test applications should be built with
**Arm semihosting** support.

To integrate this package into user projects, consider the following details:

#### Include folders

The following folders should be passed to the compiler during the build:

- `include`

The header files to be included in user projects are:

```c++
#include <micro-os-plus/devices-cortexm.h>
```

#### Source files

The source files to be added to user projects are:

- `devices-cortexm.cpp`

#### Preprocessor definitions

- none

#### Compiler options

- `-std=c++20` or higher for C++ sources
- `-std=c11` for C sources

#### C++ Namespaces

- none

#### C++ Classes

- none

### Examples

TBD

### Known problems

- none

### Tests

The project is fully tested via GitHub
[Actions](https://github.com/micro-os-plus/devices-cortexm-xpack/actions/)
on each push.
The tests run on GNU/Linux, macOS and Windows, are compiled with GCC,
clang and arm-none-eabi-gcc and run natively or via QEMU.

## Change log - incompatible changes

According to [semver](https://semver.org) rules:

> Major version X (X.y.z | X > 0) MUST be incremented if any
backwards incompatible changes are introduced to the public API.

The incompatible changes, in reverse chronological order,
are:

- v4.x: rename `SEMIHOSTING_SYS_GETCMDLINE`
- v3.x: rename `DEBUG` to `MICRO_OS_PLUS_DEBUG`; `TRACE` to
  `MICRO_OS_PLUS_TRACE`

## License

Unless otherwise stated, the content is released under the terms of the
[MIT License](https://opensource.org/licenses/mit/),
with all rights reserved to
[Liviu Ionescu](https://github.com/ilg-ul).
