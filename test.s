.section .text
ldr r1, $5      # 00
ldr r2, $20     # 05
add r1, r2      # 10
str r1, 200     # 12
jmp 30          # 17
                # 22
.skip 8         # 30
ldr r4 , $3     # 30
ldr r5 , $4     # 35

call 53         # 40

add r4,r5       # 45
str r4, 200     # 47
halt            # 52
ldr r4, $1      # 53
ret             # 58

.section .baba
veljko: .word 5,6,7
jmp veljko
