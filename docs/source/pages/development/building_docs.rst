Building The Documentation
==========================

Prerequisites
-------------

- **python** 3.11.11 or later recommended.
- **make**
- Python Modules:

| ``Sphinx==8.2.3``
| ``sphinx-copybutton==0.5.2``
| ``sphinx_nefertiti==0.8.5``

**Getting Source Code**

See :doc:`getting`.

Documentation Build Steps
-------------------------

Open a terminal in ``docs`` directory.

To build the html version, run the following command:

.. code-block:: bash

    make html

You will have your web documentation in ``docs/build/html`` directory.

To see other output options, simply run ``make`` without any arguments.
