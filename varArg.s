	.arch armv6
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"varArg.c"
	.text
	.align	2
	.global	ave
	.arch armv6
	.syntax unified
	.arm
	.fpu vfp
	.type	ave, %function
ave:
	@ args = 4, pretend = 16, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 1
	@ link register save eliminated.
	push	{r0, r1, r2, r3}
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	add	r3, fp, #8
	str	r3, [fp, #-20]
	mov	r2, #0
	mov	r3, #0
	strd	r2, [fp, #-12]
	mov	r3, #0
	str	r3, [fp, #-16]
	b	.L2
.L3:
	ldr	r3, [fp, #-20]
	add	r3, r3, #7
	bic	r3, r3, #7
	add	r2, r3, #8
	str	r2, [fp, #-20]
	vldr.64	d7, [r3]
	vldr.64	d6, [fp, #-12]
	vadd.f64	d7, d6, d7
	vstr.64	d7, [fp, #-12]
	ldr	r3, [fp, #-16]
	add	r3, r3, #1
	str	r3, [fp, #-16]
.L2:
	ldr	r2, [fp, #-16]
	ldr	r3, [fp, #4]
	cmp	r2, r3
	blt	.L3
	ldr	r3, [fp, #4]
	vmov	s15, r3	@ int
	vcvt.f64.s32	d7, s15
	vldr.64	d6, [fp, #-12]
	vdiv.f64	d5, d6, d7
	vmov	r2, r3, d5
	mov	r0, r2
	mov	r1, r3
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	add	sp, sp, #16
	bx	lr
	.size	ave, .-ave
	.section	.rodata
	.align	2
.LC0:
	.ascii	"%f\000"
	.text
	.align	2
	.global	main
	.syntax unified
	.arm
	.fpu vfp
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #16
	mov	r2, #0
	ldr	r3, .L7
	strd	r2, [sp, #8]
	mov	r2, #0
	ldr	r3, .L7+4
	strd	r2, [sp]
	mov	r2, #0
	ldr	r3, .L7+8
	mov	r0, #3
	bl	ave
	mov	r2, r0
	mov	r3, r1
	ldr	r0, .L7+12
	bl	printf
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L8:
	.align	2
.L7:
	.word	1075970048
	.word	1075314688
	.word	1074266112
	.word	.LC0
	.size	main, .-main
	.ident	"GCC: (Raspbian 8.3.0-6+rpi1) 8.3.0"
	.section	.note.GNU-stack,"",%progbits
