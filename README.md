TinyUTF8
========

Tiny C library for working with UTF-8 strings.


Project Goals
-------------

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


Integration into other Projects
-------------------------------

The final library is distributed as a single .c and .h file pair. Just download the release files of an actual release and all you need to do is adding the two files to your project, ensuring the .c file is built with either clang or an ISO-C compatible compiler and including the .h file wherever in your project you like to access the API.


API Documentation
-----------------

The API documentation can be found under [doc/api.md](doc/api.md)


Developer Documentation
-----------------------

The developer documentation can be found under [doc/dev.md](doc/dev.md)