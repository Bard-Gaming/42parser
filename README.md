# 42parser

## Project Description
42parser is a parser library aimed at making
the implementation of the [42sh project](https://github.com/Bard-Gaming/42sh)
easier.

## Compile Instructions
To compile the standard version of the library,
simply run make:

```bash
make
```

To compile a version with debug symbols enabled,
use the ``debug`` rule:

```bash
make debug
```

Unit tests can be run using the ``tests_run`` rule:

```bash
make tests_run
```

When you're done, you can use the ``clean`` rule
to delete any temporary files, or the ``fclean``
rule to delete everything but the source code.
