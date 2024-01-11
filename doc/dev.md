[ Back to [README.md](../README.md) ]

TinyUTF8 Developer Documentation
================================

Development Environment
-----------------------

You will need the following tools for development:

* [Git](https://git-scm.com/)
* A [POSIX](https://pubs.opengroup.org/onlinepubs/9699919799) compatible [shell environment](https://pubs.opengroup.org/onlinepubs/9699919799/idx/xcu.html)
* [Clang](https://clang.llvm.org/) C compiler

The following tools are not strictly required but very much recommended:
* [VSCodium](https://vscodium.com/) IDE (alternatively [VSCode](https://code.visualstudio.com), if you cannot help it)
* The following VSCodium/VSCode extensions:
  * [clangd](https://open-vsx.org/extension/llvm-vs-code-extensions/vscode-clangd) (code completion and live issues)
  * [CodeLLDB](https://open-vsx.org/extension/vadimcn/vscode-lldb) (IDE debugging)
  * [Tasks Shell Input](https://open-vsx.org/extension/augustocdias/tasks-shell-input) (IDE debugging integration with project)
  * [Error Lens](https://open-vsx.org/extension/usernamehw/errorlens) (better error highlighting in code)
  * [Code Spell Checker](https://open-vsx.org/extension/streetsidesoftware/code-spell-checker) (avoid spelling mistakes in code and comments)

GNU/Linux users can usually install Git and Clang directly via their distribution packet manager and by default have a full POSIX conforming environment pre-installed.

BSD derivate users (e.g. FreeBSD, OpenBSD, NetBSD) either can install Git and Clang via their system packet manager, or may even have both pre-installed by default, and always come with a POSIX conforming environment.

macOS users can get Clang and Git by installing [Xcode](https://apps.apple.com/us/app/xcode/id497799835?mt=12). Older versions are also sufficient and from the [developer download portal](https://developer.apple.com/develop); just select "Downloads" and log in (logging in with an Apple ID is required but an Apple ID is available free of charge and a developer subscription is not required for downloading and using Xcode). Alternatively they can install the command line developer tools for your current version of macOS by just executing `xcode-select --install` in Terminal and follow the prompted instructions. macOS always comes with a POSIX conforming shell environment.

Windows users can either use [Linux on Windows](https://learn.microsoft.com/en-us/windows/wsl/install) and then installing a Linux distribution, e.g. Debian or Ubuntu, or they can install a [MinGW-64 development environment](https://www.mingw-w64.org/downloads), like [Cygwin](https://cygwin.com/install.html) (with added Clang packet) or [w64devkit](https://github.com/mstorsjo/llvm-mingw/releases).

All systems for that [Docker](https://www.docker.com) is available (or a Docker compatible container environment) can also setup a Docker image for developing. A simple GNU/Linux environment like [Alpine Linux](https://hub.docker.com/_/alpine) (basically a Linux Kernel + [BusyBox](https://www.busybox.net/about.html)) is already sufficient and allows installing Git and Clang via the [`pkg`](https://wiki.alpinelinux.org/wiki/Alpine_Package_Keeper) packet manager.



Generating Test Data
--------------------

### Creating NFC/NFD forms

https://dencode.com/en/string/unicode-normalization


### Create Unicode data

https://www.coderstool.com/unicode-text-converter


### Create hex dumps from UTF-8 Hex

```
printf '\x..\x..\x..' | xxd -u -i | sed 's/0X/0x/g' | sed 's/^../\t/'
```


### Count bytes from UTF-8 Hex

```
printf '%s' '\x..\x..\x..' | tr '\' '\n' | wc -l
```

### Count code points from UTF-32

```
printf 'u+..u+..u+...' | tr 'u' '\n' | wc -l
```

### Create UTF-8 from UTF-32

You can use the following JavaScript code for that:

```
const inputValues= [
	// 'u+DFFFu+00'
];
for (var i = 0; i < inputValues.length; i++) {
	const utf32String = inputValues[i];
	const utf32Array = utf32String.split('u+').filter(Boolean);
	const utf8Array = utf32Array.map(utf32 => {
		const codePoint = parseInt(utf32, 16);
		if (codePoint < 0x80) {
			return codePoint;
		} else if (codePoint < 0x800) {
			return [0xc0 | (codePoint >> 6),
				0x80 | (codePoint & 0x3f)];
		} else if (codePoint < 0x10000) {
			return [0xe0 | (codePoint >> 12),
				0x80 | ((codePoint >> 6) & 0x3f),
				0x80 | (codePoint & 0x3f)];
		} else {
			return [0xf0 | (codePoint >> 18),
				0x80 | ((codePoint >> 12) & 0x3f),
				0x80 | ((codePoint >> 6) & 0x3f),
				0x80 | (codePoint & 0x3f)];
		}
	});
	const utf8Result = utf8Array.flat().map(
	code => `0x${code.toString(16).padStart(2, '0')}`);
	console.log(utf8Result.join(', '));
}
```

E.g. you can run it at: https://reqbin.com/code/javascript
