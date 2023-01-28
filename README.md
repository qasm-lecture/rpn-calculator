# Reverse Polish Notation Calculator Fuzzing Example

This folder contains a working but not fuzz-safe RPN calculator application.

## Files of Interest

- `main.cpp`: Naive implementation that can still be crashed by the fuzzer

## Commands of Interest

- Build and fuzz the app

```bash
$ nix-shell
$ make fuzz
```

It is possible that AFL emits error messages instead of fuzzing.
*Read these messages* and follow their advice.

## Exercise

Fix the file `main.cpp` so that it withstands long times of fuzzing.

For every crash, AFL will create a file in `out/crashes`. Each file contains
input on which the RPN calculator crashed. Examine such inputs, run the program
manually without the fuzzer with them, analyze the cause for the crash and
fix it, one by one.

## Usage

Following functions are supported:
* addition (+)
* subtraction (-)
* multiplication (*)
* division (/)
* ln (l)
* exponential (e)
* square (s)
* squareroot (q)

### Example

```bash
9l
User input is "9l"
Result is: 2
```
