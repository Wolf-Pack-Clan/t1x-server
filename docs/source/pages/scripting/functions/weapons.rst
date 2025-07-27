Weapons
=======

Supported Weapon Properties
---------------------------

Supported weapon properties can be found by searching ``weaponinfo_t`` in ``types.h`` file in the source code.

getWeaponIntProperty
--------------------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "name", "string", ""
    "property", "string", ""

| **Returns** ``int``

Get an integer property of a weapon.

**Example**

.. code-block:: cpp

    luger_ammo = getWeaponIntProperty("luger_mp", "maxAmmo");


getWeaponStrProperty
--------------------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "name", "string", ""
    "property", "string", ""

| **Returns** ``string``

Get a string property of a weapon.

**Example**

.. code-block:: cpp

    luger_name = getWeaponStrProperty("luger_mp", "displayName");


setWeaponIntProperty
--------------------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "name", "string", ""
    "property", "string", ""
    "value", "int", ""

| **Returns** ``bool``

Set an integer property of a weapon.

**Example**

.. code-block:: cpp

    setWeaponIntProperty("colt_mp", "clipSize", "1");


setWeaponStrProperty
--------------------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "name", "string", ""
    "property", "string", ""
    "value", "string", ""

| **Returns** ``bool``

Set a string property of a weapon.

**Example**

.. code-block:: cpp

    setWeaponStrProperty("bar_mp", "weaponClass", "pistol");

