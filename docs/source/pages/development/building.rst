Building From Source
====================

Prerequisites for Building
--------------------------

**Required:**

- g++-multilib
- meson
- ninja

**Optional:**

- libcurl
- libssl

**Installation on Debian/Ubuntu**

.. code-block:: bash

    sudo dpkg --add-architecture i386
    sudo apt update
    sudo apt install g++-multilib meson ninja-build libcurl4-openssl-dev:i386 libssl-dev:i386


**Getting Source Code**

See :doc:`getting`.

Build Steps
-----------

First of all, set ``PKG_CONFIG_PATH`` to 32 bit library path(s).

.. code-block:: bash

    export PKG_CONFIG_PATH=/usr/lib/i386-linux-gnu/pkgconfig:/usr/lib32/pkgconfig:$PKG_CONFIG_PATH

To compile, execute the following commands:

.. code-block:: bash

    meson setup build/release -Dprefix=$(realpath .)
    ninja -C build/release install

This will create a release build. The file ``t1x.iso`` will be generated in the ``bin`` directory.

Optional Build Arguments
~~~~~~~~~~~~~~~~~~~~~~~~

- **`--buildtype=debug`:** Include debug information (no optimization). It's recommended to build debug version in a separate folder i.e. ``build/debug``. The default ``buildtype`` is ``release``.

**Example**

.. code-block:: bash

    meson setup build/debug --buildtype=debug -Dprefix=$(realpath .)
    ninja -C build/debug install

This will create a debug build.

- **enable_unsafe:** Enables unsafe features like ``fread``, ``fwrite``, etc.

- **compile_ssl:** Compile with SSL support for ``hash`` function.

- **compile_curl:** Compile with cURL support for ``webhookMessage`` function.

**Example**

.. code-block:: bash

    meson setup build/release -Dprefix=$(realpath .) -Denable_unsafe=true -Dcompile_curl=true -Dcompile_ssl=true
    ninja -C build/release install

