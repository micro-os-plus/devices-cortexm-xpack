[![license](https://img.shields.io/github/license/micro-os-plus/device-cortexm-xpack)](https://github.com/micro-os-plus/device-cortexm-xpack/blob/xpack/LICENSE)
[![CI on Push](https://github.com/micro-os-plus/device-cortexm-xpack/workflows/CI%20on%20Push/badge.svg)](https://github.com/micro-os-plus/device-cortexm-xpack/actions?query=workflow%3A%22CI+on+Push%22)

# A source xPack with µOS++ Cortex-M definitions

Due to the CMSIS design, some Cortex-M architecture definitions are
available only via the vendor specific device headers, so they
cannot be located in the architecture package.

The project is hosted on GitHub as
[micro-os-plus/device-cortexm-xpack](https://github.com/micro-os-plus/device-cortexm-xpack).

## Maintainer info

This page is addressed to developers who plan to include this package
into their own projects.

For maintainer infos, please see the
[README-MAINTAINER](README-MAINTAINER.md) file.

## Install

As a source xPacks, the easiest way to add it to a project is via **xpm**,
but it can also be used as any Git project, for example as a submodule.

### Prerequisites

A recent [xpm](https://xpack.github.io/xpm/),
which is a portable [Node.js](https://nodejs.org/) command line application.

For details please follow the instructions in the
[install](https://xpack.github.io/install/) page.

### xpm

Note: the package will be available from npmjs.com at a later date.

For now, it can be installed from GitHub:

```sh
cd my-project
xpm init # Unless a package.json is already present

xpm install github:micro-os-plus/device-cortexm-xpack
```

When ready, this package will be available as
[`@micro-os-plus/device-cortexm`](https://www.npmjs.com/package/@micro-os-plus/device-cortexm)
from the `npmjs.com` registry:

```sh
cd my-project
xpm init # Unless a package.json is already present

xpm install @micro-os-plus/device-cortexm@latest
```

### Git submodule

If, for any reason, **xpm** is not available, the next recommended
solution is to link it as a Git submodule below an `xpacks` folder.

```sh
cd my-project
git init # Unless already a Git project
mkdir -p xpacks

git submodule add https://github.com/micro-os-plus/device-cortexm-xpack.git \
  xpacks/micro-os-plus-device-cortexm
```

## Branches

Apart from the unused `master` branch, there are two active branches:

- `xpack`, with the latest stable version (default)
- `xpack-develop`, with the current development version

All development is done in the `xpack-develop` branch, and contributions via
Pull Requests should be directed to this branch.

When new releases are published, the `xpack-develop` branch is merged
into `xpack`.

## User info

The **µTest++** framework is inspired by [Node tap](https://node-tap.org),
but is way simpler and has only a limited number of primitives.

- test suites must be compiled as separate applications, one apllication
  can return only the result of one test suite
- a test suite may include any number of test cases
- each test case may perform any number of tests checks
- each test check either succeeds or fails
- the test progress is shown on STDOUT, with each test check on a separate
  line, prefixed with either a check sign (✓) or a cross sign (✗)
- the main result of the test is passed back as the process exit code

If there is at least one successful test and there are no failed tests,
the entire test suite is successful and the process returns
0 as exit value.

### Build & integration info

The project is written in C++, and the tests are expected to be
written in C++ too (although there are no
major reasons to prevent adding C wrappers).

On embedded platforms, the test applications should be built with
**Arm semihosting** support.

To integrate this package into user projects, consider the following details:

#### Source folders

- `src`

The source file to be added to user projects is: `device-cortexm.cpp`.

#### Include folders

- `include`

The header file to be included in user project is:

```c++
#include <micro-os-plus/device-cortexm.h>
```

#### Preprocessor definitions

- none required

#### Compiler options

- `-std=c++17` or higher for C++ sources
- `-std=c11` for C sources

#### Namespaces

TBD

#### Classes

TBD

### Examples

TBD

### Known problems

- none

### Tests

The project is fully tested via GitHub
[Actions](https://github.com/micro-os-plus/device-cortexm-xpack/actions)
on each push.
The tests run on GNU/Linux, macOS and Windows, are compiled with GCC,
clang and arm-none-eabi-gcc and run natively or via QEMU.

## License

The original content is released under the
[MIT License](https://opensource.org/licenses/MIT/),
with all rights reserved to
[Liviu Ionescu](https://github.com/ilg-ul/).
