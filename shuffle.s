.intel_syntax noprefix

.global shuffle

.text
shuffle:
	# fisher yates algorithms https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
	# -- To shuffle an array a of n elements (indices 0..n-1):
	# for i from n−1 downto 1 do
	# 	j ← random integer such that 0 ≤ j ≤ i
	# 	exchange a[j] and a[i]

	# initialize counter to n-1
	MOV RCX, 51
.forLoop:
	
# body of the forloop
	# Push variables to stack
	PUSH RDI
	PUSH RCX
	CALL rand 		# Call rand with no parameters. return value goes to RAX

	# Pop variables from stack
	POP RCX
	POP RDI

	XOR RDX, RDX		# Don't care about the value in RDX. Zero it out so it doesn't AND with stuff later

	# Get our random integer j where 0 <= j <= i 
	MOV RSI, RCX
	ADD RSI, 1
	DIV RSI  		# DIV returns RDX:RAX with RDX meaning quotient and RAX being remainer

	# Swapping 
	MOV EAX, dword ptr [RDI+RCX*4] 
	MOV ESI, dword ptr [RDI+RDX*4]
	MOV dword ptr [RDI+RCX*4], ESI
	MOV dword ptr [RDI+RDX*4], EAX

	DEC RCX 		# Decrement counter
	CMP RCX, 1		# loop condition
	JG .forLoop		# Greater than compare
# outside the loop

	RET
