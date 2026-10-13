# Infix to Postfix Conversion Using Stack

## 1. Project Overview

This project converts arithmetic expressions from **Infix Notation** to **Postfix Notation** using a **Stack (LIFO)** data structure. The algorithm handles operators, parentheses, precedence, and associativity to generate the correct postfix expression.

## 2. Aim

To implement a stack-based algorithm that converts infix expressions into postfix expressions efficiently.

## 3. Objectives

- Understand infix and postfix notations.
- Implement stack-based expression conversion.
- Handle operator precedence and associativity correctly.
- Process parentheses during conversion.
- Analyze the time and space complexity of the algorithm.
- Understand the applications of stacks in expression processing.

## 4. Algorithm

1. Initialize an empty stack and postfix output.
2. Scan the infix expression from left to right.
3. Add operands directly to the output.
4. Push opening parentheses `(` onto the stack.
5. When `)` is encountered, pop operators until `(` is found and discard the parentheses.
6. For operators, pop higher-precedence operators and equal-precedence operators when the current operator is left-associative. Then push the current operator.
7. After scanning, pop all remaining operators into the output.

## 5. Operator Precedence

- `^` – High precedence; right-to-left associativity.
- `*`, `/`, `%` – Medium precedence; left-to-right associativity.
- `+`, `-` – Low precedence; left-to-right associativity.

Parentheses determine the order of evaluation and are not included in the postfix output.

## 6. Example and Stack Trace

**Input Expression:** `A + B * C`

1. Read `A` → Output: `A`; Stack: Empty.
2. Read `+` → Output: `A`; Stack: `+`.
3. Read `B` → Output: `AB`; Stack: `+`.
4. Read `*` → Output: `AB`; Stack: `+ *` because `*` has higher precedence than `+`.
5. Read `C` → Output: `ABC`; Stack: `+ *`.
6. End of expression → Pop `*`, then `+`.

**Final Postfix Output:** `ABC*+`

## 8. Applications

- Expression evaluation in calculators
- Compiler design and parsing
- Stack-based virtual machines
- Arithmetic expression processing

## 9. Limitations

- The input should be valid unless error handling is implemented.
- Mismatched parentheses require validation.
- Unary operators and multi-digit numbers may need additional handling.

## 10. Conclusion

This project demonstrates how a **Stack** converts infix expressions into equivalent postfix expressions while preserving operator precedence and associativity. The algorithm operates in **O(n) time**, making it useful for expression processing and compiler design.
