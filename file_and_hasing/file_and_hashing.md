## File

**File => Array of bytes**

A FILE is defined in the C library and never appears in kernel code. A struct file, on the other hand, is a kernel structure that never appears in user programs.

mode_t f_mode;
The file mode identifies the file as either readable or writable (or both), by means of the bits FMODE_READ and FMODE_WRITE. You might want to check this field for read/write permission in your ioctl function, but you don’t need to check permissions for read and write because the kernel checks before invoking your method. An attempt to write without permission, for example, is rejected without the driver even knowing about it.

loff_t f_pos;
The current reading or writing position. loff_t is a 64-bit value (long long in gcc terminology). The driver can read this value if it needs to know the current position in the file, but should never change it (read and write should update a position using the pointer they receive as the last argument instead of acting on filp->f_pos directly).

unsigned int f_flags;
These are the file flags, such as O_RDONLY, O_NONBLOCK, and O_SYNC. A driver needs to check the flag for nonblocking operation, while the other flags are seldom used. In particular, read/write permission should be checked using f_mode instead of f_flags. All the flags are defined in the header <linux/fcntl.h>.

struct file_operations \*f_op;
The operations associated with the file. The kernel assigns the pointer as part of its implementation of open, and then reads it when it needs to dispatch any operations. The value in filp->f_op is never saved for later reference; this means that you can change the file operations associated with your file whenever you want, and the new methods will be effective immediately after you return to the caller. For example, the code for open associated with major number 1 (/dev/null, /dev/zero, and so on) substitutes the operations in filp->f_op depending on the minor number being opened. This practice allows the implementation of several behaviors under the same major number without introducing overhead at each system call. The ability to replace the file operations is the kernel equivalent of “method overriding” in object-oriented programming.

void \*private_data;
The open system call sets this pointer to NULL before calling the open method for the driver. The driver is free to make its own use of the field or to ignore it. The driver can use the field to point to allocated data, but then must free memory in the release method before the file structure is destroyed by the kernel. private_data is a useful resource for preserving state information across system calls and is used by most of our sample modules.

struct dentry \*f_dentry;
The directory entry (dentry) structure associated with the file. Dentries are an optimization introduced in the 2.1 development series. Device driver writers normally need not concern themselves with dentry structures, other than to access the inode structure as filp->f_dentry->d_inode.

**File Interfaces**

- input
  - fopen
  - fclose
  - fgets
  - fread
  - fscanf
- output
  - fputs
  - fprintf
  - fwrite


