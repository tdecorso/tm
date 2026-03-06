# tm - Tiny Math Library

**tm** is a small header-only math library written in C that provides basic vector and matrix operations useful for graphics programming.

---

## Features

The library currently provides:
### Vectors
  - 2D float vectors
  - addition
  - subtraction
  - scalar multiplication / division
  - dot product
  - length
  - normalization
### 3D float vectors
  - addition
  - subtraction
  - scalar multiplication / division
  - dot product
  - cross product
  - length
  - normalization
### Matrices  
  - 3×3 float matrices
  - identity matrix
  - matrix addition
  - matrix subtraction
  - matrix multiplication
  - translation matrices
  - scaling matrices
  - rotation matrices (x, y, z)
  - vector transformation
  - Matrices are stored in row-major order.

---

## Usage

The library is header-only. Include it in your project:
```
#include "tm.h"

int main(void) {
  vec2f p = {1.0f, 2.0f};
  
  mat3f transform = mat3f_identity();
  transform = mat3f_translate(transform, (vec2f){3.0f, 4.0f});
  transform = mat3f_scale(transform, (vec2f){2.0f, 2.0f});
  
  vec2f result = vec2f_transform(transform, p);
  return 0;
}

```
