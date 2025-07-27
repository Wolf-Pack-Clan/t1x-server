Installation
============

Prerequisites for Running
-------------------------

**Required:**

- libstdc++6:i386

**Optional:**

- libcurl
- libssl

**Installation on Debian/Ubuntu**

.. code-block:: bash

    sudo dpkg --add-architecture i386
    sudo apt update
    sudo apt install libstdc++6:i386 libcurl4t64:i386 libssl3t64:i386



Installing
------------

- Download ``t1x.so`` from the `releases page <https://github.com/Wolf-Pack-Clan/t1x-server/releases>`_
- Place ``t1x.so`` in the CoD root directory.
- Inject ``t1x.so`` into ``coduo_lnxded`` when starting the server. Like:

.. code-block:: bash

    LD_PRELOAD="./t1x.so" coduo_lnxded +exec myserver.cfg

Refer to step 5 of the `cod.pm <https://cod.pm>`_ server setup `guide <https://cod.pm/guide/a7a40b/call-of-duty-1-server-on-linux-installing-and-configuring>`_ for details.

Build From Source
-----------------

See :doc:`../development/building`
