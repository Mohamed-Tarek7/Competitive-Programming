mask = mask | (1 << bit) // Set a bit to one
mask = mask & ~(1 << bit) // Set a bit to zero
mask = mask ^ (1 << bit) // Flip a bit
x ^ y ^ x = y
