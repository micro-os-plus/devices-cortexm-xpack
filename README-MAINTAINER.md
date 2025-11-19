[![license](https://img.shields.io/github/license/micro-os-plus/devices-cortexm-xpack)](https://github.com/micro-os-plus/devices-cortexm-xpack/blob/xpack/LICENSE)
[![CI on Push](https://github.com/micro-os-plus/devices-cortexm-xpack/actions/workflows/ci.yml/badge.svg)](https://github.com/micro-os-plus/devices-cortexm-xpack/actions/workflows/ci.yml)
[![GitHub issues](https://img.shields.io/github/issues/micro-os-plus/devices-cortexm-xpack.svg)](https://github.com/micro-os-plus/devices-cortexm-xpack/issues/)
[![GitHub pulls](https://img.shields.io/github/issues-pr/micro-os-plus/devices-cortexm-xpack.svg)](https://github.com/micro-os-plus/devices-cortexm-xpack/pulls)

# Maintainer info

## Prerequisites

A recent [xpm](https://xpack.github.io/xpm/), which is a portable
[Node.js](https://nodejs.org/) command line application.

It is recommended to update to the latest version with:

```sh
npm install --global xpm@latest
```

## Project repository

The project is hosted on GitHub as:

- <https://github.com/micro-os-plus/devices-cortexm-xpack.git>

To clone the stable branch (`xpack`), run the following commands in a
terminal (on Windows use the _Git Bash_ console):

```sh
rm -rf ~/Work/micro-os-plus/devices-cortexm-xpack.git && \
mkdir -p ~/Work/micro-os-plus && \
git clone \
  https://github.com/micro-os-plus/devices-cortexm-xpack.git \
  ~/Work/micro-os-plus/devices-cortexm-xpack.git
```

For development purposes, clone the development branch (`xpack-development`):

```sh
rm -rf ~/Work/micro-os-plus/devices-cortexm-xpack.git && \
mkdir -p ~/Work/micro-os-plus && \
git clone \
  --branch xpack-development \
  https://github.com/micro-os-plus/devices-cortexm-xpack.git \
  ~/Work/micro-os-plus/devices-cortexm-xpack.git
```

## Development setup

### Remove previous packages

In this early development phase, package versions are not properly set, and
if you have older versions of the xPack installed, sometimes updates may fail
to get the latest version. To fix this remove all global packages by using

```sh
xpm run rm-global-deps -C ~/Work/micro-os-plus/devices-cortexm-xpack.git
```

and repeat the steps from `xpm install`.

### Install dependencies

With a clean slate, install dependencies:

```sh
xpm run install-all -C ~/Work/micro-os-plus/devices-cortexm-xpack.git
```

## Run tests

The project includes unit tests.

To perform the tests, run the usual xpm sequence:

```sh
xpm run test-all -C ~/Work/micro-os-plus/devices-cortexm-xpack.git
```

### Clone writeable dependencies

The above procedure will allow to develop the project itself, but the
dependencies will be read-only; to be able to contribute to them,
also clone the development branch (`xpack-development`)es of all µOS++ source xPacks
into a folder of your choice and link them to the central xPacks
folder by running `xpack link` in each folder.

To automate this, there is a helper script to clone these repos into
`${HOME}/Work/micro-os-plus-xpack-repos`:

```sh
curl -L https://raw.githubusercontent.com/micro-os-plus/helper-scripts/main/clone-and-link-all-git-repos.sh | bash -
```

Note: If you prefer a different location, start the script with a first
argument as the destination folder path.

After cloning all Git repos, link this project to the development packages,
by running the `link-deps` actions:

```sh
cd devices-cortexm-xpack.git
xpm run link-deps
```

## Continuous Integration

The CI tests are performed on GitHub Actions, as the
[CI on Push](https://github.com/micro-os-plus/devices-cortexm-xpack/actions/workflows/ci.yml)
workflow.

## Code formatting

Code formatting is done using `clang-format --style=file`, either manually
from a script, or automatically from Visual Studio Code, or the Eclipse
CppStyle plug-in.

Always reformat the source files that were changed.

## How to publish

### Release schedule

There are no fixed releases.

### Check Git

In the `micro-os-plus/devices-cortexm-xpack` Git repo:

- switch to the `xpack-development` branch
- if needed, merge the `xpack` branch

No need to add a tag here, it'll be added when the release is created.

### Increase the version

Determine the upstream version (like `5.0.0`) and eventually update the
`package.json` file; the format is `5.0.0-pre`.

### Fix possible open issues

Check GitHub issues and pull requests:

- <https://github.com/micro-os-plus/devices-cortexm-xpack/issues/>

and fix them; assign them to a milestone (like `5.0.0`).

### Update `README-MAINTAINER.md`

Update the `README-MAINTAINER.md` file to reflect the changes
related to the new version.

### Update `CHANGELOG.md`

- open the `CHANGELOG.md` file
- check if all previous fixed issues are in
- add a new entry like _* v5.0.0_
- commit with a message like _prepare v5.0.0_

### Push changes

- reformat the source files that were changed
- commit and push

### Manual tests

To run the tests manually on the local machine:

```sh
xpm run install-all -C ~/Work/micro-os-plus/devices-cortexm-xpack.git
xpm run test-all -C ~/Work/micro-os-plus/devices-cortexm-xpack.git
```

### Publish on the npmjs.com server

- select the `xpack-development` branch
- commit all changes
- `npm pack` and check the content of the archive, which should list
  only `package.json`, `README.md`, `LICENSE`, `CHANGELOG.md`,
  the sources and CMake/meson files;
  possibly adjust `.npmignore`
- `npm version patch`, `npm version minor`, `npm version major`
- push the `xpack-development` branch to GitHub
- the `postversion` npm script should also update tags via `git push origin --tags`
- wait for the CI job to complete
  (<https://github.com/micro-os-plus/devices-cortexm-xpack/actions/workflows/ci.yml>)

### Publish

- `npm publish --tag next` (use `npm publish --access public` when
  publishing for the first time)

The version is visible at:

- <https://www.npmjs.com/package/@micro-os-plus/devices-cortexm?activeTab=versions>

## Update the repo

When the package is considered stable:

- with a Git client (VS Code is fine)
- merge `xpack-development` into `xpack`
- push to GitHub
- select `xpack-development`

## Tag the npm package as `latest`

When the release is considered stable, promote it as `latest`:

- `npm dist-tag ls @micro-os-plus/devices-cortexm`
- `npm dist-tag add @micro-os-plus/devices-cortexm@5.0.0 latest`
- `npm dist-tag ls @micro-os-plus/devices-cortexm`
