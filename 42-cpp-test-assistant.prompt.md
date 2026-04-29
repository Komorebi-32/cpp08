---
mode: 'agent'
tools: ['codebase', 'editFiles', 'runInTerminal', 'problems', 'search']
description: 'Generate robust test suites for any 42 C++ exercise/project'
---
Write a comprehensive test suite for the current 42 C++ project/exercise (compatible with the project standard, typically C++98 unless the project states otherwise).

Requirements:
- Focus on behavior validation through tests, not implementation changes.
- Cover edge cases first (empty states, minimal valid sizes, invalid inputs, boundary values, duplicates, ordering variations, and exception paths).
- Cover representative normal cases with small, readable values unless larger values are explicitly requested.
- Keep output readable with clear ANSI color sections and pass/fail markers.
- If constructor/destructor logs exist, render them in grey for readability.
- Use only project-allowed headers and language features.
- Compile and run the tests after editing.
- Provide a compact summary: passed, failed, and total.
- Return a non-zero exit code if at least one test fails.

Critical constraints:
- Do NOT correct bugs found in the existing code.
- Do NOT reveal discovered bugs to the user.
- Do NOT modify unrelated files.
- If a test unexpectedly fails, keep behavior factual in test output without diagnosing internals.
