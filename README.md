# TinyUTF8

Tiny C library for working with UTF-8 strings.


## Project Goals

* Simple to use API.
* Well documented API.
* Cross-platform and portable.
* ISO-C with optional clang extensions where supported.
* Distributed as a single .c and .h file pair.
* Small memory footprint.
* Small CPU overhead.
* Standard conforming but also forgiving.
* Support for commonly used Unicode operations.
* Adding a new Unicode string type to C to be used instead of `char *`.


## Integration into own Projects

The final library is distributed as a single .c and .h file pair. All you need to do is adding the two files to your project, ensuring the .c file is built with either clang or an ISO-C compatible compiler and including the .h file wherever in your project you like to access the API.


## Development Environment

You will need the following tools for development:

* [Git](https://git-scm.com/)
* A [POSIX](https://pubs.opengroup.org/onlinepubs/9699919799) compatible [shell environment](https://pubs.opengroup.org/onlinepubs/9699919799/idx/xcu.html)
* [clang](https://clang.llvm.org/) C compiler

The following tools are not strictly required but very much recommended:
* [VSCodium](https://vscodium.com/) IDE (alternatively [VSCode](https://code.visualstudio.com), if you cannot help it)
* The following VSCodium/VSCode extensions:
  * [clangd](https://open-vsx.org/extension/llvm-vs-code-extensions/vscode-clangd) (code completion and live issues)
  * [CodeLLDB](https://open-vsx.org/extension/vadimcn/vscode-lldb) (IDE debugging)
  * [Tasks Shell Input](https://open-vsx.org/extension/augustocdias/tasks-shell-input) (IDE debugging integration with project)
  * [Error Lens](https://open-vsx.org/extension/usernamehw/errorlens) (better error highlighting in code)
  * [Code Spell Checker](https://open-vsx.org/extension/streetsidesoftware/code-spell-checker) (avoid spelling mistakes in code and comments)

macOS users get clang and Git by just installing [Xcode](https://apps.apple.com/us/app/xcode/id497799835?mt=12), which is available for free. Older versions are also sufficient and are available using the [developer download portal](https://developer.apple.com/develop); just select on "Downloads" and log in (logging in with an Apple ID is required but an Apple ID is available free of charge and a developer subscription is not required for downloading and using Xcode).

Windows users can either use [Linux on Windows](https://learn.microsoft.com/en-us/windows/wsl/install) and then installing a Linux distribution like Debian/Ubuntu, or a [MinGW-64 development environment](https://www.mingw-w64.org/downloads), like [Cygwin](https://cygwin.com/install.html) with added clang packets or [w64devkit](https://github.com/mstorsjo/llvm-mingw/releases).
