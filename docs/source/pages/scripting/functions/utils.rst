Utility
=======

ban
---

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "-i ip", "string", "The IP address to ban"
    "-n num", "int", "The clientNum to ban"
    "-a num", "int", "adminNum"
    "-r reason", "string", "Reason for ban"
    "-d x<h/d>", "string", "Ban duration"

| **Returns** ``undefined``

Bans a player in same way as the console command which is explained :ref:`here <ban-client-ip-adress>`.

**Example**

.. code-block:: cpp

    // Example from rmod chat_commands
    cmd_ban(args)
    {
        if (args.size < 3)
        {
            showUsage(args[0]);
            self iPrintLn("Notes: Use 'h' for hours or 'd' for days");
            return;
        }
        arg = "";

        adminNum = self getEntityNumber();
        param_adminNum = "-a " + adminNum;
        arg += param_adminNum;
        for(i = 1; i < args.size; i++)
            arg += " " + args[i];

        ban(arg);
    }


fclose
------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "file", "int", "The file handle to close"

| **Returns** ``int``

Closes a file handle that was previously opened with :ref:`fopen`.

**Example**

.. code-block:: cpp

    fclose(file);


file_exists
-----------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "filename", "string", "File name/path to check"

| **Returns** ``int``

Checks if the specified file exists or not.

**Example**

.. code-block:: cpp

    // stub example for dev.
    // dev. should remove this comment after he is done changing it
    file_exists(filename);


fopen
-----

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "filename", "string", "description"
    "mode", "string", "description"

| **Returns** ``int``

Opens a file with the given ``mode`` and and associates a stream with it.

All modes can be found `here <https://man7.org/linux/man-pages/man3/fopen.3.html#DESCRIPTION>`_.

**Example**

.. code-block:: cpp

    fopen("config_mp.cfg", "w+");


fread
-----

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "file", "int", "description"

| **Returns** ``string``

Reads a buffer of 255 characters from the file stream opened with :ref:`fopen`.

**Example**

.. code-block:: cpp

    fread(file);


fwrite
------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "file", "int", "description"
    "buffer", "string", "description"

| **Returns** ``int``

Write ``buffer`` to ``file`` stream opened with :ref:`fopen`.

**Example**

.. code-block:: cpp

    buffer = "A picture is a poem without words.";
    fwrite(file, buffer);


getAscii
--------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "str", "string", "description"

| **Returns** ``int``

Returns the ASCII value of the **first** character of your string.

**Example**

.. code-block:: cpp

    getAscii("a");


getConfigString
---------------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "index", "int", "description"

| **Returns** ``string``

Get a Config String by ``index``.

**Example**

.. code-block:: cpp

    i = getConfigString(index);


getLocalizedStringIndex
-----------------------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "str", "localized string", "description"

| **Returns** ``int``

Returns the index of a localized string.

The index can be used to update an existing localized string using :ref:`makeUpdatedLocalizedString`.

**Example**

.. code-block:: cpp

    i = getLocalizedStringIndex(mylocalizedstring);


getServerStartTime
------------------

| **Returns** ``int``

As the name says, returns the server's start time.

**Example**

.. code-block:: cpp

    time = getServerStartTime();


getSubStr
---------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "str", "string", "The parent string"
    "start", "int", "Start of substring"
    "end", "int", "Optional, end of substring"

| **Returns** ``string``

Returns a substring from the specified string. The ``end`` index is **exclusive**.

**Example**

.. code-block:: cpp

    mystring = "Flowers grow out of dark moments.";
    start = 8;
    end = 16;
    mysub = getSubStr(mystring, start, end);
    // this should return "grow out"


getSystemTime
-------------

| **Returns** ``int``

As the name says, returns the system's current time.

**Example**

.. code-block:: cpp

    timeNow = getSystemTime();


getType
-------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "var", "any", ""

| **Returns** ``string``

Returns the type of ``var``.

**Example**

.. code-block:: cpp

    myvar = [];
    type = getType(myvar);
    // this would return array


hash
----

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "input", "string", "String to hash"
    "length", "int", "Length of result"

| **Returns** ``string``

this is the Description of the function. Explain the usage in detail here

**Example**

.. code-block:: cpp

    // stub example for dev.
    // dev. should remove this comment after he is done changing it
    hash(input, _len);


logPrintConsole
---------------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "str", "string", ""

| **Returns** ``bool``

Prints your string to the server console. Returns ``true`` if successful.

**Example**

.. code-block:: cpp

    logPrintConsole("hello");


makeLocalizedString
-------------------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "str", "string", ""

| **Returns** ``string``

Makes your string a localized string.

**Example**

.. code-block:: cpp

    mystring = "Tears are the silent language of grief."
    mystring_localized = makeLocalizedString(mystring);


makeUpdatedLocalizedString
--------------------------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "str", "string", "New version of the string"
    "index", "int", "Index of the string to update"

| **Returns** ``string``

Updates an existing localized string.

**Example**

.. code-block:: cpp

    index = getLocalizedStringIndex(mystring_localized);
    newstr = "Tears are not the silent language of grief.";
    makeUpdatedLocalizedString(newstr, index);


monotone
--------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "input", "string", ""

| **Returns** ``string``

Removes color codes from the input string.

**Example**

.. code-block:: cpp

    monotone("^3col^^22or^4ed");
    // result is "colored"


replace
-------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "orig", "string", "Your string"
    "rep", "string", "Part to be replaced"
    "with", "string", "String to be replaced with"

| **Returns** ``string``

Replaces a part of your string with the ``with`` parameter.

**Example**

.. code-block:: cpp

    mystring = "Tears are not the silent language of grief.";
    newstr = replace(mystring, "not ", "");


sendCommandToClient
-------------------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "clientNum", "int", ""
    "message", "string", "message to send"

| **Returns** ``bool``

Sends a message to the client. Returns ``true`` if successful.

**Example**

.. code-block:: cpp

    // Example from rmod chat_commands
    message_player(player, message)
    {
        sendCommandToClient(player getEntityNumber(), "i \"" + message + "\"");
    }


strftime
--------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "timestamp", "int", ""
    "timezone", "string", ""
    "format", "string", ""

| **Returns** ``string``

Formats a timestamp with timezone.

**Example**

.. code-block:: cpp

    timeNow = getSystemTime();
    formatted_time = strftime(timeNow, "utc", "%m/%d/%Y %I:%M %p %Z");


strip
-----

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "input", "string", ""

| **Returns** ``string``

Removes leading and trailing spaces from a string.

**Example**

.. code-block:: cpp

    strip("  Hello   ");
    // result is "Hello"


strstr
------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "str", "string", "The full string aka `Haystack`"
    "sub", "string", "The substring aka `Needle`"

| **Returns** ``bool``

Checks if the substring exists in the specified string.

**Example**

.. code-block:: cpp

    if(strstr("Unknown Soldier", "Unknown"))
        iPrintLn("unknown in name");


strtok
------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "input", "string", ""
    "delimiter", "string", ""

| **Returns** ``array``

Splits the input string at delimiter into parts and returns them as an array.

**Example**

.. code-block:: cpp

    mystring = "value1,value2,value3";
    values = strtok(mystring, ",");
    for(i=0; i<values.size; i++)
        iPrintLn(values[i]);


toLower
-------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "string", "string", ""

| **Returns** ``string``

Turns your string to lower case.

**Example**

.. code-block:: cpp

    toLower(string);


toUpper
-------

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "str", "string", ""

| **Returns** ``string``

Turns your string to upper case.

**Example**

.. code-block:: cpp

    toUpper(str);


unban
-----

.. csv-table:: **Arguments**
    :header: "Argument", "Type", "Description"
    :align: left

    "-i ip", "string", "The IP address to ban"

| **Returns** ``undefined``

Unbans a player in same way as the console command which is explained :ref:`here <unban-client-ip-adress>`.

**Example**

.. code-block:: cpp

    cmd_unban(args)
    {
        if (args.size < 3)
        {
            showUsage(args[0]);
            return;
        }
        arg = "";

        adminNum = self getEntityNumber();
        param_adminNum = "-a " + adminNum;

        arg += param_adminNum;
        for(i = 1; i < args.size; i++)
            arg += " " + args[i];

        unban(arg);
    }

