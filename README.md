# C standard library

[![Linux build status][linux-ci-badge]][linux-ci-url] [![macOS build status][macos-ci-badge]][macos-ci-url]

[linux-ci-badge]: https://github.com/mbrukman/c-stdlib/actions/workflows/linux.yml/badge.svg?branch=main
[linux-ci-url]: https://github.com/mbrukman/c-stdlib/actions/workflows/linux.yml?query=branch%3Amain
[macos-ci-badge]: https://github.com/mbrukman/c-stdlib/actions/workflows/macos.yml/badge.svg?branch=main
[macos-ci-url]: https://github.com/mbrukman/c-stdlib/actions/workflows/macos.yml?query=branch%3Amain

This project aims to implement the C standard library, per the C99 standard.

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
1. Build libc and run tests via: `ninja -f linux.ninja test`

### macOS

1. Install Xcode and accept the license agreement.
1. Create a symlink in this directory pointing to the Xcode app in your
   `Applications` folder, e.g.:

   ```sh
   $ ln -s /Applications/Xcode_12.5.app Xcode
   ```

   See the comment in [`macos.ninja`](macos.ninja) for details and rationale.

1. Install [Ninja][ninja].
1. Build libc and run tests via: `ninja -f macos.ninja test`

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
