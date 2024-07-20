# How to use templates?  
  
## How templates work?
The script creates a .h file to include/ and a .c file to wrappers/. In the header file the script puts the different functions' signatures and in .c file their definitions.
  
Create template files in scripts/templates-folder. Run the template generation script from root of the project with `python scripts/template_gen.py`. The complete form of the command is `python scripts/template_gen.py <target type name> <template file> <type file>`.  
* `<target type name>` is the type name used in file names and include guards.
* `<template file>` is the file with the templates.
* `<type file>` is a file with a list of types for which the templates will be created for.
  
## Template file structure is as follows:
* The file has the functions separated with ###.
* The first section is considered a header, that is pasted to the beginning of the resulting .c file. You can put macros, includes and such there. If you don't need it, begin the file with "###".
* \<t> is a placeholder for type name.
* \<T> is a placeholder for type name in upper case.
* See `example.tpl` for an example.

