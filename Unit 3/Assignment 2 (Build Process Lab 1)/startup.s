.globl yehia
yehia:
    ldr sp , =stack_top
    bl main
end:
    b end