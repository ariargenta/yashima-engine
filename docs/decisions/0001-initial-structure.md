# 1. Initial Project Structure

## Date
**2025-02-17**

## Status
**Accepted**

## Context
The Yashima Engine project aims to serve dual purposes:
1. Function as a production-grade graphics engine
2. Serve as an educational platform for graphics programming

Key considerations:
- New contributors need clear entry points
- Documentation must scale with complexity
- Code organization should demostrate best practices
- Need to capture architectural decisions and rationale

## Decision
Implement directory structure
```bash
    yashima-engine/
    ├── README.md # Project overview and entry point
    ├── CONTRIBUTING.md # Contribution guidelines
    ├── docs/
    |    ├── technical/ # Technical documentation
    |    ├── guides/ # Educational content
    |    ├── decisions/ # Architecture decisions
    ├── src/
    |    ├── window/ #Windowing management
    |    ├── renderer/ # Graphics abstraction
    |    ├── memory/ # Memory management
    └── tests/
    └── unit/ # Unit tests
```

## Consequences
### Positive
- Clear separation between code and documentation
- Scalable structure for future growth
- Educational focus maintained through organization
- Decision history preserved through ADRs
- Testing strategy built in from start

### Negative
- Apparent over-structured for initial phase
- Maintenance discipline
- Potential intimidation for new contributors
- Additional overhead in documentation

## Implementation Notes
1. Each component in `src/` will:
    - Have its own namespace
    - Maintain single responsibility
    - Include interface documentation

2. Documentation strategy:
    - README.md: Quick start and overview
    - Technical docs: Implementation details
    - Guides: Learning-focused content
    - ADRs: Decision history