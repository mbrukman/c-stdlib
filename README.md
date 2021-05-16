# C standard library

[![Build Status][github-ci-badge]][github-ci-url]

[github-ci-badge]: https://github.com/mbrukman/c-stdlib/actions/workflows/main.yml/badge.svg
[github-ci-url]: https://github.com/mbrukman/c-stdlib/actions/workflows/main.yml

This project aims to implement the C standard library.

**Note:** This library is a work-in-progress and is not intended for production
use. If you are looking for a C standard library for use in production, there
are [plenty of options][c-std-libs] to choose from.

## References

* [ISO C standard][iso-c-std] ([draft][c-std-draft])
* [POSIX standard][posix-std]

## Build & test

### Linux

1. Install [Clang][llvm-download]; the LLVM project provides
   [APT repos][llvm-apt] for easy installation on Debian and Ubuntu.
1. Install [Ninja][ninja].
1. Build libc and run tests via: `ninja -f build-linux.ninja test`

### macOS

1. Install Xcode and accept the license agreement.
1. Create a symlink pointing to the Xcode app in your Applications folder, e.g.:

   ```sh
   $ ln -s /Applications/Xcode_12.4.app Xcode
   ```

1. Install [Ninja][ninja].
1. Build libc and run tests via: `ninja -f build-macos.ninja test`

## Contributing

This project is a personal learning project; as such, I am not looking to accept
contributions at this time. If you see something wrong or would like to propose
an improvement, please file an issue and let me know. Thanks!

## License

Apache 2.0; see [`LICENSE`](LICENSE) for details.

## Disclaimer

This project is not an official Google project. It is not supported by Google
and Google specifically disclaims all warranties as to its quality,
merchantability, or fitness for a particular purpose.

[c-std-libs]: https://en.wikipedia.org/wiki/C_standard_library#Implementations
[iso-c-std]: http://www.iso-9899.info/wiki/The_Standard
[c-std-draft]: http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf
[posix-std]: https://pubs.opengroup.org/onlinepubs/9699919799/
[llvm-download]: https://releases.llvm.org/download.html
[llvm-apt]: https://apt.llvm.org/
[ninja]: https://github.com/ninja-build/ninja
