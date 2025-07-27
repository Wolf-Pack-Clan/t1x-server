Player
======

connectionlessPacketToClient
----------------------------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "cmd", "string", "Command to send"

| **Called on** ``client``
| **Returns** ``bool``

Sends a connectionless packet to the client.

**Example**

.. code-block:: cpp

    player connectionlessPacketToClient("print\n\n" + "Welcome to the server!");


processClientCommand
--------------------

| **Called on** ``client``
| **Returns** ``bool``

Calls ``ClientCommand`` for the client.

**Example**

.. code-block:: cpp

    self processClientCommand();

