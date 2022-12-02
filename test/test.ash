# Call function to stop program
stop:
	halt

# Fibonacci loop
loop:
	add r1, r2, r1
	write r1
	cmp r1, 34
	jmpif $stop
	jmp $loop

# Entry point function
main:
	set r1, 0 	# test
	set r2, 1
	jmp $loop